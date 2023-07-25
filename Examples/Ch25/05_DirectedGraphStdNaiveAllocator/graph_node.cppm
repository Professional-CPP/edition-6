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
			graph_node(directed_graph<T, A>* graph, const T& t);
			graph_node(directed_graph<T, A>* graph, T&& t);

			// Constructs a graph_node for the given value and with given allocator.
			graph_node(directed_graph<T, A>* graph, const T& t, const A& allocator);
			graph_node(directed_graph<T, A>* graph, T&& t, const A& allocator);

			~graph_node();

			// Copy and move constructors.
			graph_node(const graph_node& src);
			graph_node(graph_node&& src) noexcept;

			// Copy and move assignment operators.
			graph_node& operator=(const graph_node& rhs);
			graph_node& operator=(graph_node&& rhs) noexcept;

			// Returns a reference to the stored value.
			[[nodiscard]] T& value() noexcept;
			[[nodiscard]] const T& value() const noexcept;

			// Equality operators.
			bool operator==(const graph_node& rhs) const;
			bool operator!=(const graph_node& rhs) const;

		private:
			friend class directed_graph<T, A>;

			// A pointer to the graph this node is in.
			directed_graph<T, A>* m_graph;

			// A type alias for the container type used to store the adjacency list.
			using adjacency_list_type = std::set<std::size_t>;

			// Returns a reference to the adjacency list.
			[[nodiscard]] adjacency_list_type& get_adjacent_nodes_indices();
			[[nodiscard]] const adjacency_list_type& get_adjacent_nodes_indices() const;

			A m_allocator;
			T* m_data{ nullptr };
			adjacency_list_type m_adjacentNodeIndices;
		};

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>* graph, const T& t)
			: graph_node<T, A>{ graph, t, A{} }
		{
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>* graph, const T& t, const A& allocator)
			: m_graph{ graph }
			, m_allocator{ allocator }
		{
			m_data = m_allocator.allocate(1);
			new(m_data) T{ t };
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>* graph, T&& t)
			: graph_node<T, A>{ graph, std::move(t), A{} }
		{
		}

		template<typename T, typename A>
		graph_node<T, A>::graph_node(directed_graph<T, A>* graph, T&& t, const A& allocator)
			: m_graph{ graph }
			, m_allocator{ allocator }
		{
			m_data = m_allocator.allocate(1);
			new(m_data) T{ std::move(t) };
		}

		template<typename T, typename A>
		graph_node<T, A>::~graph_node()
		{
			if (m_data)
			{
				std::destroy_at(m_data);
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
			new(m_data) T{ *(src.m_data) };
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
				std::destroy_at(m_data);
				new(m_data) T{ *(rhs.m_data) };
			}
			return *this;
		}

		template<typename T, typename A>
		typename graph_node<T, A>::graph_node&
			graph_node<T, A>::operator=(graph_node&& rhs) noexcept
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
		T& graph_node<T, A>::value() noexcept
		{
			return *m_data;
		}

		template<typename T, typename A>
		const T& graph_node<T, A>::value() const noexcept
		{
			return *m_data;
		}

		template<typename T, typename A>
		bool graph_node<T, A>::operator==(const graph_node& rhs) const
		{
			return m_graph == rhs.m_graph && 
				*m_data == *(rhs.m_data) &&
				m_adjacentNodeIndices == rhs.m_adjacentNodeIndices;
		}

		template<typename T, typename A>
		bool graph_node<T, A>::operator!=(const graph_node& rhs) const
		{
			return !(*this == rhs);
		}

		template<typename T, typename A>
		typename graph_node<T, A>::adjacency_list_type&
			graph_node<T, A>::get_adjacent_nodes_indices()
		{
			return m_adjacentNodeIndices;
		}

		template<typename T, typename A>
		const typename graph_node<T, A>::adjacency_list_type&
			graph_node<T, A>::get_adjacent_nodes_indices() const
		{
			return m_adjacentNodeIndices;
		}

	}
}
