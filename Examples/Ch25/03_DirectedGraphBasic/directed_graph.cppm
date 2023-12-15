export module directed_graph;

import :node;
import std;

namespace ProCpp
{

	export
	template<typename T>
	class directed_graph
	{
	public:
		// For insert to be successful, the value shall not be in the graph yet. 
		// Returns true if a new node with given value has been added to
		// the graph, and false if there was already a node with the given value.
		bool insert(T node_value);

		// Returns true if the given node value was erased, false otherwise.
		bool erase(const T& node_value);

		// Returns true if the edge was successfully created, false otherwise.
		bool insert_edge(const T& from_node_value, const T& to_node_value);

		// Returns true if the given edge was erased, false otherwise.
		bool erase_edge(const T& from_node_value, const T& to_node_value);

		// Removes all nodes from the graph.
		void clear() noexcept;

		// Returns a reference to the value in the node with given index
		// without bounds checking.
		const T& operator[](std::size_t index) const;

		// Two directed graphs are equal if their sets of nodes are equal (where
		// nodes with the same T value are considered equal) and the same number
		// of edges between each corresponding pair of nodes.
		// The order in which the nodes and edges have been added does not
		// affect equality.
		bool operator==(const directed_graph& rhs) const;

		// Swaps all nodes between this graph and the given graph.
		void swap(directed_graph& other_graph) noexcept;

		// Returns the number of nodes in the graph.
		[[nodiscard]] std::size_t size() const noexcept;

		// Returns a set with the adjacent nodes of a given node.
		// If the given node does not exist, an empty set is returned.
		[[nodiscard]] std::set<T> get_adjacent_nodes_values(const T& node_value) const;

	private:
		friend details::graph_node<T>;

		using node_container_type = std::vector<details::graph_node<T>>;

		node_container_type m_nodes;

		// Helper member functions to return an iterator to the given node, or the
		// end iterator if the given node is not in the graph.
		typename node_container_type::iterator find_node(const T& node_value);
		typename node_container_type::const_iterator find_node(const T& node_value) const;

		// Given an iterator to a node, removes that node from all adjacency lists
		// of all other nodes.
		void remove_all_links_to(typename node_container_type::const_iterator node_iter);

		// Given a set of adjacency node indices, returns the corresponding
		// set of node values.
		[[nodiscard]] std::set<T> get_adjacent_nodes_values(
			const typename details::graph_node<T>::adjacency_list_type& indices) const;

		// Given an iterator to a node, returns the index of that node in the nodes container.
		[[nodiscard]] std::size_t get_index_of_node(typename node_container_type::const_iterator node) const noexcept;
	};

	// The following stand-alone swap() function simply
	// forwards to the swap() member function.
	export
	template<typename T>
	void swap(directed_graph<T>& first, directed_graph<T>& second) noexcept
	{
		first.swap(second);
	}

	template<typename T>
	bool directed_graph<T>::insert(T node_value)
	{
		auto iter{ find_node(node_value) };
		if (iter != std::end(m_nodes))
		{
			// Value is already in the graph, return false.
			return false;
		}
		m_nodes.emplace_back(this, std::move(node_value));

		// Value successfully added to the graph, return true.
		return true;
	}

	template<typename T>
	std::size_t directed_graph<T>::get_index_of_node(typename node_container_type::const_iterator node) const noexcept
	{
		return node - std::cbegin(m_nodes);
	}

	template<typename T>
	bool directed_graph<T>::insert_edge(const T& from_node_value, const T& to_node_value)
	{
		const auto from{ find_node(from_node_value) };
		const auto to{ find_node(to_node_value) };
		if (from == std::end(m_nodes) || to == std::end(m_nodes))
		{
			return false;
		}

		const std::size_t to_index{ get_index_of_node(to) };
		return from->get_adjacent_nodes_indices().insert(to_index).second;
	}

	template<typename T>
	bool directed_graph<T>::erase_edge(const T& from_node_value, const T& to_node_value)
	{
		const auto from{ find_node(from_node_value) };
		const auto to{ find_node(to_node_value) };
		if (from == std::end(m_nodes) || to == std::end(m_nodes))
		{
			return false; // nothing to erase
		}

		const std::size_t to_index{ get_index_of_node(to) };
		from->get_adjacent_nodes_indices().erase(to_index);
		return true;
	}

	template<typename T>
	void directed_graph<T>::remove_all_links_to(typename node_container_type::const_iterator node_iter)
	{
		const std::size_t node_index{ get_index_of_node(node_iter) };

		for (auto&& node : m_nodes)
		{
			node.remove_node_index(node_index);
		}
	}

	template<typename T>
	bool directed_graph<T>::erase(const T& node_value)
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes))
		{
			return false;
		}
		remove_all_links_to(iter);
		m_nodes.erase(iter);
		return true;
	}

	template<typename T>
	void directed_graph<T>::clear() noexcept
	{
		m_nodes.clear();
	}

	template<typename T>
	typename directed_graph<T>::node_container_type::iterator
		directed_graph<T>::find_node(const T& node_value)
	{
		return std::find_if(std::begin(m_nodes), std::end(m_nodes),
			[&](const auto& node) { return node.value() == node_value; });
	}

	template<typename T>
	typename directed_graph<T>::node_container_type::const_iterator
		directed_graph<T>::find_node(const T& node_value) const
	{
		return std::find_if(std::begin(m_nodes), std::end(m_nodes),
			[&](const auto& node) { return node.value() == node_value; });
	}

	template<typename T>
	const T& directed_graph<T>::operator[](std::size_t index) const
	{
		return m_nodes[index].value();
	}

	template<typename T>
	std::set<T> directed_graph<T>::get_adjacent_nodes_values(
		const typename details::graph_node<T>::adjacency_list_type& indices) const
	{
		std::set<T> values;
		for (auto&& index : indices)
		{
			values.insert(m_nodes[index].value());
		}
		return values;
	}

	template<typename T>
	std::set<T> directed_graph<T>::get_adjacent_nodes_values(const T& node_value) const
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes))
		{
			return {};
		}

		return get_adjacent_nodes_values(iter->get_adjacent_nodes_indices());
	}

	template<typename T>
	bool directed_graph<T>::operator==(const directed_graph& rhs) const
	{
		if (m_nodes.size() != rhs.m_nodes.size()) { return false; }

		for (auto&& node : m_nodes)
		{
			const auto rhsNodeIter{ rhs.find_node(node.value()) };
			if (rhsNodeIter == std::end(rhs.m_nodes))
			{
				return false;
			}
			const auto adjacent_values_lhs{ get_adjacent_nodes_values(node.get_adjacent_nodes_indices()) };
			const auto adjacent_values_rhs{ rhs.get_adjacent_nodes_values(rhsNodeIter->get_adjacent_nodes_indices()) };
			if (adjacent_values_lhs != adjacent_values_rhs)
			{
				return false;
			}
		}
		return true;
	}

	template<typename T>
	void directed_graph<T>::swap(directed_graph& other_graph) noexcept
	{
		m_nodes.swap(other_graph.m_nodes);
	}

	template<typename T>
	std::size_t directed_graph<T>::size() const noexcept
	{
		return m_nodes.size();
	}
}
