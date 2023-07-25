export module directed_graph;

export import :adjacent_nodes_iterator;
export import :const_adjacent_nodes_iterator;
export import :directed_graph_iterator;
export import :const_directed_graph_iterator;
import :node;
import std;

namespace ProCpp
{

	export
	template<typename T>
	class directed_graph
	{
	public:
		using value_type = T;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;

		using iterator = const_directed_graph_iterator<directed_graph>;
		using const_iterator = const_directed_graph_iterator<directed_graph>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		using iterator_adjacent_nodes = adjacent_nodes_iterator<directed_graph>;
		using const_iterator_adjacent_nodes = const_adjacent_nodes_iterator<directed_graph>;
		using reverse_iterator_adjacent_nodes = std::reverse_iterator<iterator_adjacent_nodes>;
		using const_reverse_iterator_adjacent_nodes = std::reverse_iterator<const_iterator_adjacent_nodes>;

		// For an insert to be successful, the value shall not be in the graph yet. 
		// The iterator in the returned pair points to the inserted node, or to the
		// node that was already in the graph with the given value.
		// The boolean is true if a new node with given value has been added to
		// the graph, and false if there was already a node with the given value.
		std::pair<iterator, bool> insert(const T& node_value);
		std::pair<iterator, bool> insert(T&& node_value);
		iterator insert(const_iterator hint, const T& node_value);
		iterator insert(const_iterator hint, T&& node_value);

		template<std::forward_iterator Iter>
		void insert(Iter first, Iter last);

		// Returns an iterator to the element after the last deleted element.
		iterator erase(const_iterator pos);
		iterator erase(const_iterator first, const_iterator last);

		// Returns true if the edge was successfully created, false otherwise.
		bool insert_edge(const T& from_node_value, const T& to_node_value);

		// Returns true if the given edge was erased, false otherwise.
		bool erase_edge(const T& from_node_value, const T& to_node_value);

		// Removes all nodes from the graph.
		void clear() noexcept;

		// Returns a reference to the node with given index.
		// No bounds checking is done.
		reference operator[](size_type index);
		const_reference operator[](size_type index) const;

		reference at(size_type index);
		const_reference at(size_type index) const;

		// Iterator member functions.
		iterator begin() noexcept;
		iterator end() noexcept;
		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;
		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		reverse_iterator rbegin() noexcept;
		reverse_iterator rend() noexcept;
		const_reverse_iterator rbegin() const noexcept;
		const_reverse_iterator rend() const noexcept;
		const_reverse_iterator crbegin() const noexcept;
		const_reverse_iterator crend() const noexcept;

		// Return iterators to the list of adjacent nodes for the given node.
		// Return a default constructed iterator as end iterator if the value is not found.
		iterator_adjacent_nodes begin(const T& node_value) noexcept;
		iterator_adjacent_nodes end(const T& node_value) noexcept;
		const_iterator_adjacent_nodes begin(const T& node_value) const noexcept;
		const_iterator_adjacent_nodes end(const T& node_value) const noexcept;
		const_iterator_adjacent_nodes cbegin(const T& node_value) const noexcept;
		const_iterator_adjacent_nodes cend(const T& node_value) const noexcept;

		// Return reverse iterators to the list of adjacent nodes for the given node.
		// Return a default constructed iterator as end iterator if the value is not found.
		reverse_iterator_adjacent_nodes rbegin(const T& node_value) noexcept;
		reverse_iterator_adjacent_nodes rend(const T& node_value) noexcept;
		const_reverse_iterator_adjacent_nodes rbegin(const T& node_value) const noexcept;
		const_reverse_iterator_adjacent_nodes rend(const T& node_value) const noexcept;
		const_reverse_iterator_adjacent_nodes crbegin(const T& node_value) const noexcept;
		const_reverse_iterator_adjacent_nodes crend(const T& node_value) const noexcept;

		// Two directed graphs are equal if they have the same nodes and edges.
		// The order in which the nodes and edges have been added does not
		// affect equality.
		bool operator==(const directed_graph& rhs) const;
		bool operator!=(const directed_graph& rhs) const;

		// Swaps all nodes between this graph and the given graph.
		void swap(directed_graph& other_graph) noexcept;

		// Returns the number of nodes in the graph.
		[[nodiscard]] size_type size() const noexcept;
		[[nodiscard]] size_type max_size() const noexcept;
		[[nodiscard]] bool empty() const noexcept;

	private:
		friend class directed_graph_iterator<directed_graph>;
		friend class const_directed_graph_iterator<directed_graph>;
		friend details::graph_node<T>;

		using nodes_container_type = std::vector<details::graph_node<T>>;

		nodes_container_type m_nodes;

		// Helper member functions to return an iterator to the given node, or the end iterator
		// if the given node is not in the graph.
		[[nodiscard]] typename nodes_container_type::iterator find_node(const T& node_value);
		[[nodiscard]] typename nodes_container_type::const_iterator find_node(const T& node_value) const;

		// Given an iterator to a node, removes that node from all adjacency lists
		// of all other nodes.
		void remove_all_links_to(typename nodes_container_type::const_iterator node_iter);

		// Given a set of adjacency node indices, returns the corresponding
		// set of node values.
		[[nodiscard]] std::set<T> get_adjacent_nodes_values(
			const typename details::graph_node<T>::adjacency_list_type& indices) const;

		// Given an iterator to a node, returns the index of that node in the nodes container.
		[[nodiscard]] std::size_t get_index_of_node(const typename nodes_container_type::const_iterator& node) const noexcept;
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
	std::pair<typename directed_graph<T>::iterator, bool> directed_graph<T>::insert(const T& node_value)
	{
		T copy{ node_value };
		return insert(std::move(copy));
	}

	template<typename T>
	std::pair<typename directed_graph<T>::iterator, bool> directed_graph<T>::insert(T&& node_value)
	{
		auto iter{ find_node(node_value) };
		if (iter != std::end(m_nodes))
		{
			// Value is already in the graph.
			return { iterator{ iter }, false };
		}
		m_nodes.emplace_back(this, std::move(node_value));

		// Value successfully added to the graph.
		return { iterator{ --std::end(m_nodes) }, true };
	}

	template<typename T>
	typename directed_graph<T>::iterator directed_graph<T>::insert(const_iterator hint, const T& node_value)
	{
		// Ignore the hint, just forward to another insert().
		return insert(node_value).first;
	}

	template<typename T>
	typename directed_graph<T>::iterator directed_graph<T>::insert(const_iterator hint, T&& node_value)
	{
		// Ignore the hint, just forward to another insert().
		return insert(std::move(node_value)).first;
	}

	template<typename T>
	template<std::forward_iterator Iter>
	void directed_graph<T>::insert(Iter first, Iter last)
	{
		// Copy each element in the range by using an insert_iterator adapter.
		// Give begin() as a dummy position -- insert ignores it anyway.
		std::copy(first, last, std::insert_iterator { *this, begin() });
	}

	template<typename T>
	std::size_t directed_graph<T>::get_index_of_node(const typename nodes_container_type::const_iterator& node) const noexcept
	{
		const auto index{ std::distance(std::cbegin(m_nodes), node) };
		return static_cast<std::size_t>(index);
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
	void directed_graph<T>::remove_all_links_to(typename nodes_container_type::const_iterator node_iter)
	{
		const std::size_t node_index{ get_index_of_node(node_iter) };

		// Iterate over all adjacency lists of all nodes.
		for (auto&& node : m_nodes)
		{
			auto& adjacencyIndices{ node.get_adjacent_nodes_indices() };
			// First, remove references to the to-be-deleted node.
			adjacencyIndices.erase(node_index);
			// Second, modify all adjacency indices to account for the removal of a node.
			std::vector<std::size_t> indices(std::begin(adjacencyIndices), std::end(adjacencyIndices));
			std::for_each(std::begin(indices), std::end(indices),
				[node_index](std::size_t& index) {
					if (index > node_index) {
						--index;
					}
				});
			adjacencyIndices.clear();
			adjacencyIndices.insert(std::begin(indices), std::end(indices));
		}
	}

	template<typename T>
	typename directed_graph<T>::iterator
		directed_graph<T>::erase(const_iterator pos)
	{
		if (pos.m_nodeIterator == std::end(m_nodes))
		{
			return iterator{ std::end(m_nodes) };
		}
		remove_all_links_to(pos.m_nodeIterator);
		return iterator{ m_nodes.erase(pos.m_nodeIterator) };
	}

	template<typename T>
	typename directed_graph<T>::iterator
		directed_graph<T>::erase(const_iterator first, const_iterator last)
	{
		for (auto iter{ first }; iter != last; ++iter)
		{
			if (iter.m_nodeIterator != std::end(m_nodes))
			{
				remove_all_links_to(iter.m_nodeIterator);
			}
		}
		return iterator{ m_nodes.erase(first.m_nodeIterator, last.m_nodeIterator) };
	}

	template<typename T>
	void directed_graph<T>::clear() noexcept
	{
		m_nodes.clear();
	}

	template<typename T>
	typename directed_graph<T>::nodes_container_type::iterator
		directed_graph<T>::find_node(const T& node_value)
	{
		return std::find_if(std::begin(m_nodes), std::end(m_nodes),
			[&node_value](const auto& node) { return node.value() == node_value; });
	}

	template<typename T>
	typename directed_graph<T>::nodes_container_type::const_iterator
		directed_graph<T>::find_node(const T& node_value) const
	{
		return const_cast<directed_graph<T>*>(this)->find_node(node_value);
	}

	template<typename T>
	typename directed_graph<T>::reference
		directed_graph<T>::operator[](size_type index)
	{
		return m_nodes[index].value();
	}

	template<typename T>
	typename directed_graph<T>::const_reference
		directed_graph<T>::operator[](size_type index) const
	{
		return m_nodes[index].value();
	}

	template<typename T>
	typename directed_graph<T>::reference
		directed_graph<T>::at(size_type index)
	{
		return m_nodes.at(index).value();
	}

	template<typename T>
	typename directed_graph<T>::const_reference
		directed_graph<T>::at(size_type index) const
	{
		return m_nodes.at(index).value();
	}

	template<typename T>
	typename directed_graph<T>::iterator
		directed_graph<T>::begin() noexcept
	{
		return iterator{ std::begin(m_nodes) };
	}

	template<typename T>
	typename directed_graph<T>::iterator
		directed_graph<T>::end() noexcept
	{
		return iterator{ std::end(m_nodes) };
	}

	template<typename T>
	typename directed_graph<T>::const_iterator
		directed_graph<T>::cbegin() const noexcept
	{
		return begin();
	}

	template<typename T>
	typename directed_graph<T>::const_iterator
		directed_graph<T>::cend() const noexcept
	{
		return end();
	}

	template<typename T>
	typename directed_graph<T>::const_iterator
		directed_graph<T>::begin() const noexcept
	{
		return const_cast<directed_graph*>(this)->begin();
	}

	template<typename T>
	typename directed_graph<T>::const_iterator
		directed_graph<T>::end() const noexcept
	{
		return const_cast<directed_graph*>(this)->end();
	}



	template<typename T>
	typename directed_graph<T>::reverse_iterator
		directed_graph<T>::rbegin() noexcept
	{
		return reverse_iterator{ end() };
	}

	template<typename T>
	typename directed_graph<T>::reverse_iterator
		directed_graph<T>::rend() noexcept
	{
		return reverse_iterator{ begin() };
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator
		directed_graph<T>::rbegin() const noexcept
	{
		return const_reverse_iterator{ end() };
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator
		directed_graph<T>::rend() const noexcept
	{
		return const_reverse_iterator{ begin() };
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator
		directed_graph<T>::crbegin() const noexcept
	{
		return rbegin();
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator
		directed_graph<T>::crend() const noexcept
	{
		return rend();
	}

	template<typename T>
	typename directed_graph<T>::iterator_adjacent_nodes
		directed_graph<T>::begin(const T& node_value) noexcept
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes))
		{
			// Return a default constructed end iterator.
			return iterator_adjacent_nodes{};
		}
		return iterator_adjacent_nodes{ std::begin(iter->get_adjacent_nodes_indices()), this };
	}

	template<typename T>
	typename directed_graph<T>::iterator_adjacent_nodes
		directed_graph<T>::end(const T& node_value) noexcept
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes))
		{
			// Return a default constructed end iterator.
			return iterator_adjacent_nodes{};
		}
		return iterator_adjacent_nodes{ std::end(iter->get_adjacent_nodes_indices()), this };
	}

	template<typename T>
	typename directed_graph<T>::const_iterator_adjacent_nodes
		directed_graph<T>::cbegin(const T& node_value) const noexcept
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes))
		{
			// Return a default constructed end iterator.
			return const_iterator_adjacent_nodes{};
		}
		return const_iterator_adjacent_nodes{ std::cbegin(iter->get_adjacent_nodes_indices()), this };
	}

	template<typename T>
	typename directed_graph<T>::const_iterator_adjacent_nodes
		directed_graph<T>::cend(const T& node_value) const noexcept
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes))
		{
			// Return a default constructed end iterator.
			return const_iterator_adjacent_nodes{};
		}
		return const_iterator_adjacent_nodes{ std::cend(iter->get_adjacent_nodes_indices()), this };
	}

	template<typename T>
	typename directed_graph<T>::const_iterator_adjacent_nodes
		directed_graph<T>::begin(const T& node_value) const noexcept
	{
		return cbegin(node_value);
	}

	template<typename T>
	typename directed_graph<T>::const_iterator_adjacent_nodes
		directed_graph<T>::end(const T& node_value) const noexcept
	{
		return cend(node_value);
	}


	template<typename T>
	typename directed_graph<T>::reverse_iterator_adjacent_nodes
		directed_graph<T>::rbegin(const T& node_value) noexcept
	{
		return reverse_iterator_adjacent_nodes{ end(node_value) };
	}

	template<typename T>
	typename directed_graph<T>::reverse_iterator_adjacent_nodes
		directed_graph<T>::rend(const T& node_value) noexcept
	{
		return reverse_iterator_adjacent_nodes{ begin(node_value) };
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator_adjacent_nodes
		directed_graph<T>::rbegin(const T& node_value) const noexcept
	{
		return const_reverse_iterator_adjacent_nodes{ end(node_value) };
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator_adjacent_nodes
		directed_graph<T>::rend(const T& node_value) const noexcept
	{
		return const_reverse_iterator_adjacent_nodes{ begin(node_value) };
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator_adjacent_nodes
		directed_graph<T>::crbegin(const T& node_value) const noexcept
	{
		return rbegin(node_value);
	}

	template<typename T>
	typename directed_graph<T>::const_reverse_iterator_adjacent_nodes
		directed_graph<T>::crend(const T& node_value) const noexcept
	{
		return rend(node_value);
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
	bool directed_graph<T>::operator!=(const directed_graph& rhs) const
	{
		return !(*this == rhs);
	}

	template<typename T>
	void directed_graph<T>::swap(directed_graph& other_graph) noexcept
	{
		m_nodes.swap(other_graph.m_nodes);
	}

	template<typename T>
	typename directed_graph<T>::size_type directed_graph<T>::size() const noexcept
	{
		return m_nodes.size();
	}

	template<typename T>
	typename directed_graph<T>::size_type directed_graph<T>::max_size() const noexcept
	{
		return m_nodes.max_size();
	}

	template<typename T>
	bool directed_graph<T>::empty() const noexcept
	{
		return m_nodes.empty();
	}

}
