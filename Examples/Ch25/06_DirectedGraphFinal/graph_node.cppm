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
		class graph_node_allocator
		{
		protected:
			explicit graph_node_allocator(const A& allocator);

			// Copy and move constructors.
			graph_node_allocator(const graph_node_allocator&) = delete;
			graph_node_allocator(graph_node_allocator&& src) noexcept;

			// Copy and move assignment operators.
			graph_node_allocator& operator=(const graph_node_allocator&) = delete;
			graph_node_allocator& operator=(graph_node_allocator&&) noexcept = delete;

			~graph_node_allocator();

			A m_allocator;
			T* m_data{ nullptr };
		};

		template<typename T, typename A>
		graph_node_allocator<T, A>::graph_node_allocator(const A& allocator)
			: m_allocator{ allocator }
		{
			m_data = m_allocator.allocate(1);
		}

		template<typename T, typename A>
		graph_node_allocator<T, A>::graph_node_allocator(graph_node_allocator&& src) noexcept
			: m_allocator{ std::move(src.m_allocator) }
			, m_data{ std::exchange(src.m_data, nullptr) }
		{
		}

		template<typename T, typename A>
		graph_node_allocator<T, A>::~graph_node_allocator()
		{
			if (m_data) {
				m_allocator.deallocate(m_data, 1);
				m_data = nullptr;
			}
		}




		template<typename T, typename A = std::allocator<T>>
		class graph_node : private graph_node_allocator<T, A>
		{
		public:
			// Constructs a graph_node for the given value.
			explicit graph_node(directed_graph<T, A>& graph, T t);

			// Constructs a graph_node for the given value and with given allocator.
			explicit graph_node(directed_graph<T, A>& graph, T t, const A& allocator);

			~graph_node();

			// Copy and move constructors.
			graph_node(const graph_node& src);
			graph_node(graph_node&& src) noexcept;

			// Copy and move assignment operators.
			graph_node& operator=(const graph_node& rhs);
			graph_node& operator=(graph_node&& rhs) noexcept;

			// Returns a reference to the stored value.
			[[nodiscard]] T& value() noexcept { return *(this->m_data); }
			[[nodiscard]] const T& value() const noexcept { return *(this->m_data); }

			// A type alias for the container type used to store the adjacency list.
			using adjacency_list_type = std::set<std::size_t>;

			// Returns a reference to the adjacency list.
			[[nodiscard]] auto& get_adjacent_nodes_indices() { return m_adjacentNodeIndices; }
			[[nodiscard]] const auto& get_adjacent_nodes_indices() const { return m_adjacentNodeIndices; }

			// Removes a given node index from the adjacency list and updates
			// the remaining indices to account for the shift in indices.
			void remove_node_index(std::size_t node_index);

		private:
			// A reference to the graph this node is in.
			directed_graph<T, A>& m_graph;

			adjacency_list_type m_adjacentNodeIndices;
		};

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>& graph, T t)
			: graph_node<T, A>{ graph, std::move(t), A{} }
		{
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>& graph, T t, const A& allocator)
			: m_graph{ graph }
			, graph_node_allocator<T, A>{ allocator }
		{
			new(this->m_data) T{ std::move(t) };
		}

		template<typename T, typename A>
		graph_node<T, A>::~graph_node()
		{
			if (this->m_data)
			{
				std::destroy_at(this->m_data);
			}
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(const graph_node& src)
			: graph_node_allocator<T, A>{ src.m_allocator }
			, m_graph{ src.m_graph }
			, m_adjacentNodeIndices{ src.m_adjacentNodeIndices }
		{
			new(this->m_data) T{ *(src.m_data) };
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(graph_node&& src) noexcept
			: graph_node_allocator<T, A>{ std::move(src) }
			, m_graph{ src.m_graph }
			, m_adjacentNodeIndices{ std::move(src.m_adjacentNodeIndices) }
		{
		}

		template<typename T, typename A>
		typename graph_node<T, A>::graph_node&
			graph_node<T, A>::operator=(const graph_node& rhs)
		{
			if (this != &rhs)
			{
				m_adjacentNodeIndices = rhs.m_adjacentNodeIndices;
				new(this->m_data) T{ *(rhs.m_data) };
			}
			return *this;
		}

		template<typename T, typename A>
		typename graph_node<T, A>::graph_node&
			graph_node<T, A>::operator=(graph_node&& rhs) noexcept
		{
			if (this != &rhs)
			{
				m_adjacentNodeIndices = std::move(rhs.m_adjacentNodeIndices);
				this->m_data = std::exchange(rhs.m_data, nullptr);
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
