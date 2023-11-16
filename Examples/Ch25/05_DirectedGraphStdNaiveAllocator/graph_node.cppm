export module directed_graph:node;

import std;

namespace ProCpp
{

	// Forward declaration.
	export
	template<typename T, typename A>
	class directed_graph;

	namespace details
	{

		template<typename T, typename A = std::allocator<T>>
		class graph_node
		{
		public:
			// Constructs a graph_node for the given value.
			explicit graph_node(directed_graph<T, A>* graph, T t);

			// Constructs a graph_node for the given value and with given allocator.
			explicit graph_node(directed_graph<T, A>* graph, T t, const A& allocator);

			~graph_node();

			// Copy and move constructors.
			graph_node(const graph_node& src);
			graph_node(graph_node&& src) noexcept;

			// Copy and move assignment operators.
			graph_node& operator=(const graph_node& rhs);
			graph_node& operator=(graph_node&& rhs);

			// Returns a reference to the stored value.
			[[nodiscard]] const T& value() const noexcept { return *m_data; }

			// A type alias for the container type used to store the adjacency list.
			using adjacency_list_type = std::set<std::size_t>;

			// Returns a reference to the adjacency list.
			[[nodiscard]] auto& get_adjacent_nodes_indices() { return m_adjacentNodeIndices; }
			[[nodiscard]] const auto& get_adjacent_nodes_indices() const { return m_adjacentNodeIndices; }

			// Removes a given node index from the adjacency list and updates
			// the remaining indices to account for the shift in indices.
			void remove_node_index(std::size_t node_index);

		private:
			// A pointer to the graph this node is in.
			directed_graph<T, A>* m_graph;

			A m_allocator;
			T* m_data{ nullptr };
			adjacency_list_type m_adjacentNodeIndices;
		};

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>* graph, T t)
			: graph_node<T, A>{ graph, std::move(t), A{} }
		{
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>* graph, T t, const A& allocator)
			: m_graph{ graph }
			, m_allocator{ allocator }
		{
			m_data = m_allocator.allocate(1);
			std::allocator_traits<A>::construct(m_allocator, m_data, std::move(t));
		}

		template<typename T, typename A>
		graph_node<T, A>::~graph_node()
		{
			if (m_data)
			{
				std::allocator_traits<A>::destroy(m_allocator, m_data);
				m_allocator.deallocate(m_data, 1);
				m_data = nullptr;
			}
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(const graph_node& src)
			: m_allocator{ src.m_allocator }
			, m_graph{ src.m_graph }
			, m_adjacentNodeIndices{ src.m_adjacentNodeIndices }
		{
			m_data = m_allocator.allocate(1);
			std::allocator_traits<A>::construct(m_allocator, m_data, *(src.m_data));
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(graph_node&& src) noexcept
			: m_allocator{ std::move(src.m_allocator) }
			, m_graph{ std::exchange(src.m_graph, nullptr) }
			, m_adjacentNodeIndices{ std::move(src.m_adjacentNodeIndices) }
			, m_data{ std::exchange(src.m_data, nullptr) }
		{
		}

		template<typename T, typename A>
		typename graph_node<T, A>::graph_node&
			graph_node<T, A>::operator=(const graph_node& rhs)
		{
			if (this != &rhs)
			{
				m_graph = rhs.m_graph;
				m_adjacentNodeIndices = rhs.m_adjacentNodeIndices;
				std::allocator_traits<A>::destroy(m_allocator, m_data);
				std::allocator_traits<A>::construct(m_allocator, m_data, *(rhs.m_data));
			}
			return *this;
		}

		template<typename T, typename A>
		typename graph_node<T, A>::graph_node&
			graph_node<T, A>::operator=(graph_node&& rhs)
		{
			if (this != &rhs)
			{
				m_graph = std::exchange(rhs.m_graph, nullptr);
				m_adjacentNodeIndices = std::move(rhs.m_adjacentNodeIndices);
				m_data = std::exchange(rhs.m_data, nullptr);
			}
			return *this;
		}

		template<typename T, typename A>
		void graph_node<T, A>::remove_node_index(std::size_t node_index)
		{
			// First, remove references to the to-be-deleted node.
			m_adjacentNodeIndices.erase(node_index);

			// Second, modify all adjacency indices to account for the removal of a node.
			// std::set doesn't let us modify its elements in place,
			// so we rebuild the set from scratch.
			std::vector<std::size_t> indices(std::begin(m_adjacentNodeIndices), std::end(m_adjacentNodeIndices));
			std::for_each(std::begin(indices), std::end(indices),
				[node_index](std::size_t& index) {
					if (index > node_index) {
						--index;
					}
				});
			m_adjacentNodeIndices.clear();
			m_adjacentNodeIndices.insert(std::begin(indices), std::end(indices));
		}

	}
}
