export module directed_graph:node;

import std;

namespace ProCpp
{

	// Forward declaration.
	export
	template<typename T>
	class directed_graph;

	namespace details
	{

		template<typename T>
		class graph_node
		{
		public:
			// Constructs a graph_node for the given value.
			graph_node(directed_graph<T>* graph, const T& t);
			graph_node(directed_graph<T>* graph, T&& t);

			// Returns a reference to the stored value.
			[[nodiscard]] T& value() noexcept;
			[[nodiscard]] const T& value() const noexcept;

			// Defaulted operator==.
			bool operator==(const graph_node&) const = default;

		private:
			friend class directed_graph<T>;

			// A pointer to the graph this node is in.
			directed_graph<T>* m_graph;

			// A type alias for the container type used to store the adjacency list.
			using adjacency_list_type = std::set<std::size_t>;

			// Returns a reference to the adjacency list.
			[[nodiscard]] adjacency_list_type& get_adjacent_nodes_indices();
			[[nodiscard]] const adjacency_list_type& get_adjacent_nodes_indices() const;

			T m_data;
			adjacency_list_type m_adjacentNodeIndices;
		};

		template<typename T>
		graph_node<T>::graph_node(directed_graph<T>* graph, const T& t)
			: m_graph{ graph }
			, m_data{ t }
		{
		}

		template<typename T>
		graph_node<T>::graph_node(directed_graph<T>* graph, T&& t)
			: m_graph{ graph }
			, m_data{ std::move(t) }
		{
		}

		template<typename T>
		T& graph_node<T>::value() noexcept
		{
			return m_data;
		}

		template<typename T>
		const T& graph_node<T>::value() const noexcept
		{
			return m_data;
		}

		template<typename T>
		typename graph_node<T>::adjacency_list_type&
			graph_node<T>::get_adjacent_nodes_indices()
		{
			return m_adjacentNodeIndices;
		}

		template<typename T>
		const typename graph_node<T>::adjacency_list_type&
			graph_node<T>::get_adjacent_nodes_indices() const
		{
			return m_adjacentNodeIndices;
		}

	}
}
