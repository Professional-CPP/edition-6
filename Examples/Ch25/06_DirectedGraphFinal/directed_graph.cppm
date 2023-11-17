export module directed_graph;

export import :const_directed_graph_iterator_impl;
export import :const_adjacent_nodes_iterator_impl;
import :node;
import std;

namespace ProCpp
{

	export
	template<typename T, typename A = std::allocator<T>>
	class directed_graph
	{
	public:
		using value_type = T;
		using reference = value_type&;
		using const_reference = const value_type&;
		using allocator_type = A;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;

		using iterator = const_directed_graph_iterator_impl<directed_graph>;
		using const_iterator = const_directed_graph_iterator_impl<directed_graph>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		using const_adjacent_nodes_iterator = const_adjacent_nodes_iterator_impl<directed_graph>;

		directed_graph() noexcept(noexcept(A{})) = default;
		explicit directed_graph(const A& allocator) noexcept;
		directed_graph(std::initializer_list<T> il, const A& allocator = A());

		template<std::input_iterator Iter>
		directed_graph(Iter first, Iter last, const A& allocator = A());

		directed_graph& operator=(std::initializer_list<T> il);

		void assign(std::initializer_list<T> il);

		template<std::input_iterator Iter>
		void assign(Iter first, Iter last);

		[[nodiscard]] allocator_type get_allocator() const;

		// For an insert to be successful, the value shall not be in the graph yet. 
		// The iterator in the returned pair points to the inserted node, or to the
		// node that was already in the graph with the given value.
		// The boolean is true if a new node with given value has been added to
		// the graph, and false if there was already a node with the given value.
		std::pair<iterator, bool> insert(T node_value);
		iterator insert(const_iterator hint, T node_value);
		
		template<std::input_iterator Iter>
		void insert(Iter first, Iter last);

		void insert(std::initializer_list<T> il);

		template<std::ranges::input_range Range>
		void insert_range(Range&& range);

		// Returns an iterator to the element after the last deleted element.
		iterator erase(const_iterator pos);
		iterator erase(const_iterator first, const_iterator last);
		size_type erase(const T& node_value);

		// Returns true if the edge was successfully created, false otherwise.
		bool insert_edge(const T& from_node_value, const T& to_node_value);

		// Returns true if the given edge was erased, false otherwise.
		bool erase_edge(const T& from_node_value, const T& to_node_value);

		// Removes all nodes from the graph.
		void clear() noexcept;

		// Returns a reference to the value in the node with given index
		// without bounds checking.
		const_reference operator[](size_type index) const;

		// Returns a reference to the value in the node with given index
		// with bounds checking.
		const_reference at(size_type index) const;

		// See Exercise 25-3.
		// Find an element in the graph.
		// Returns an end iterator if not found.
		//iterator find(const T& node_value);
		//const_iterator find(const T& node_value) const;

		// See Exercise 25-4.
		// Returns true if node_value is in the graph, false otherwise.
		//bool contains(const T& node_value) const;

		// Iterator member functions.
		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;
		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		const_reverse_iterator rbegin() const noexcept;
		const_reverse_iterator rend() const noexcept;
		const_reverse_iterator crbegin() const noexcept;
		const_reverse_iterator crend() const noexcept;

		// Helper structure to represent a range of adjacent nodes.
		struct nodes_adjacent_to_result
		{
			const_adjacent_nodes_iterator m_begin;
			const_adjacent_nodes_iterator m_end;
			const_adjacent_nodes_iterator begin() const noexcept { return m_begin; }
			const_adjacent_nodes_iterator end() const noexcept { return m_end; }
		};

		// Returns a range with the adjacent nodes for the given node value.
		std::optional<nodes_adjacent_to_result> nodes_adjacent_to(const T& node_value) const noexcept;

		// Two directed graphs are equal if their sets of nodes are equal (where
		// nodes with the same T value are considered equal) and the same number
		// of edges between each corresponding pair of nodes.
		// The order in which the nodes and edges have been added does not
		// affect equality.
		bool operator==(const directed_graph& rhs) const;

		// Swaps all nodes between this graph and the given graph.
		void swap(directed_graph& other_graph) noexcept;

		// Returns the number of nodes in the graph.
		[[nodiscard]] size_type size() const noexcept;
		[[nodiscard]] size_type max_size() const noexcept;
		[[nodiscard]] bool empty() const noexcept;

	private:
		friend class const_directed_graph_iterator_impl<directed_graph>;
		friend class details::graph_node<T, A>;

		using node_container_type = std::vector<details::graph_node<T, A>,
			typename std::allocator_traits<A>::template rebind_alloc<details::graph_node<T, A>>>;
		node_container_type m_nodes;

		// Helper member functions to return an iterator to the given node, or the end iterator
		// if the given node is not in the graph.
		[[nodiscard]] typename node_container_type::iterator find_node(const T& node_value);
		[[nodiscard]] typename node_container_type::const_iterator find_node(const T& node_value) const;

		// Given an iterator to a node, removes that node from all adjacency lists
		// of all other nodes.
		void remove_all_links_to(typename node_container_type::const_iterator node_iter);

		// Given a set of adjacency node indices, returns the corresponding
		// set of node values.
		// The returned set is only for internal use, no need to use the allocator.
		[[nodiscard]] std::set<T> get_adjacent_nodes_values(
			const typename details::graph_node<T, A>::adjacency_list_type& indices) const;

		// Given an iterator to a node, returns the index of that node in the nodes container.
		[[nodiscard]] std::size_t get_index_of_node(typename node_container_type::const_iterator node) const noexcept;
	};

	// The following stand-alone swap() function simply
	// forwards to the swap() member function.
	export
	template<typename T, typename A>
	void swap(directed_graph<T, A>& first, directed_graph<T, A>& second) noexcept
	{
		first.swap(second);
	}

	template<typename T, typename A>
	directed_graph<T, A>::directed_graph(const A& allocator) noexcept
		: m_nodes{ allocator }
	{
	}

	template<typename T, typename A>
	directed_graph<T, A>::directed_graph(std::initializer_list<T> il, const A& allocator)
		: m_nodes{ allocator }
	{
		assign(std::begin(il), std::end(il));
	}

	template<typename T, typename A>
	template<std::input_iterator Iter>
	directed_graph<T, A>::directed_graph(Iter first, Iter last, const A& allocator)
		: m_nodes{ allocator }
	{
		assign(first, last);
	}

	template<typename T, typename A>
	template<std::input_iterator Iter>
	void directed_graph<T, A>::assign(Iter first, Iter last)
	{
		clear();
		for (auto iter{ first }; iter != last; ++iter)
		{
			insert(*iter);
		}
	}

	template<typename T, typename A>
	void directed_graph<T, A>::assign(std::initializer_list<T> il)
	{
		assign(std::begin(il), std::end(il));
	}

	template<typename T, typename A>
	directed_graph<T, A>& directed_graph<T, A>::operator=(std::initializer_list<T> il)
	{
		// Use a copy-and-swap-like algorithm to guarantee strong exception safety.
		// Do all the work in a temporary instance.
		directed_graph new_graph{ il };
		swap(new_graph); // Commit the work with only non-throwing operations.
		return *this;
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::allocator_type directed_graph<T, A>::get_allocator() const
	{
		return m_nodes.get_allocator();
	}

	template<typename T, typename A>
	std::pair<typename directed_graph<T, A>::iterator, bool> directed_graph<T, A>::insert(T node_value)
	{
		auto iter{ find_node(node_value) };
		if (iter != std::end(m_nodes))
		{
			// Value is already in the graph.
			return { iterator{ iter }, false };
		}
		m_nodes.emplace_back(this, std::move(node_value));

		// Value successfully added to the graph.
		return { iterator{ std::prev(std::end(m_nodes)) }, true };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::iterator directed_graph<T, A>::insert(const_iterator hint, T node_value)
	{
		// Ignore the hint, just forward to another insert().
		return insert(std::move(node_value)).first;
	}

	template<typename T, typename A>
	template<std::input_iterator Iter>
	void directed_graph<T, A>::insert(Iter first, Iter last)
	{
		// Copy each element in the range by using an insert_iterator adapter.
		// Give end() as a dummy position -- insert ignores it anyway.
		std::copy(first, last, std::insert_iterator { *this, end() });
	}

	template<typename T, typename A>
	void directed_graph<T, A>::insert(std::initializer_list<T> il)
	{
		insert(std::begin(il), std::end(il));
	}

	template<typename T, typename A>
	template<std::ranges::input_range Range>
	void directed_graph<T, A>::insert_range(Range&& range)
	{
		insert(std::ranges::begin(range), std::ranges::end(range));
	}

	template<typename T, typename A>
	std::size_t directed_graph<T, A>::get_index_of_node(typename node_container_type::const_iterator node) const noexcept
	{
		return node - std::cbegin(m_nodes);
	}

	template<typename T, typename A>
	bool directed_graph<T, A>::insert_edge(const T& from_node_value, const T& to_node_value)
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

	template<typename T, typename A>
	bool directed_graph<T, A>::erase_edge(const T& from_node_value, const T& to_node_value)
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

	template<typename T, typename A>
	void directed_graph<T, A>::remove_all_links_to(typename node_container_type::const_iterator node_iter)
	{
		const std::size_t node_index{ get_index_of_node(node_iter) };

		for (auto&& node : m_nodes)
		{
			node.remove_node_index(node_index);
		}
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::iterator
		directed_graph<T, A>::erase(const_iterator pos)
	{
		if (pos.m_nodeIterator == std::end(m_nodes))
		{
			return end();
		}
		remove_all_links_to(pos.m_nodeIterator);
		return iterator{ m_nodes.erase(pos.m_nodeIterator) };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::iterator
		directed_graph<T, A>::erase(const_iterator first, const_iterator last)
	{
		for (auto iter{ first }; iter != last; ++iter)
		{
			remove_all_links_to(iter.m_nodeIterator);
		}
		return iterator{ m_nodes.erase(first.m_nodeIterator, last.m_nodeIterator) };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::size_type directed_graph<T, A>::erase(const T& node_value)
	{
		const auto iter{ find_node(node_value) };
		if (iter != std::end(m_nodes))
		{
			remove_all_links_to(iter);
			m_nodes.erase(iter);
			return 1;
		}
		return 0;
	}

	template<typename T, typename A>
	void directed_graph<T, A>::clear() noexcept
	{
		m_nodes.clear();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::node_container_type::iterator
		directed_graph<T, A>::find_node(const T& node_value)
	{
		return std::find_if(std::begin(m_nodes), std::end(m_nodes),
			[&](const auto& node) { return node.value() == node_value; });
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::node_container_type::const_iterator
		directed_graph<T, A>::find_node(const T& node_value) const
	{
		return std::find_if(std::begin(m_nodes), std::end(m_nodes),
			[&](const auto& node) { return node.value() == node_value; });
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_reference
		directed_graph<T, A>::operator[](size_type index) const
	{
		return m_nodes[index].value();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_reference
		directed_graph<T, A>::at(size_type index) const
	{
		return m_nodes.at(index).value();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_iterator
		directed_graph<T, A>::cbegin() const noexcept
	{
		return begin();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_iterator
		directed_graph<T, A>::cend() const noexcept
	{
		return end();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_iterator
		directed_graph<T, A>::begin() const noexcept
	{
		return const_iterator{ std::begin(m_nodes) };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_iterator
		directed_graph<T, A>::end() const noexcept
	{
		return const_iterator{ std::end(m_nodes) };
	}



	template<typename T, typename A>
	typename directed_graph<T, A>::const_reverse_iterator
		directed_graph<T, A>::rbegin() const noexcept
	{
		return const_reverse_iterator{ end() };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_reverse_iterator
		directed_graph<T, A>::rend() const noexcept
	{
		return const_reverse_iterator{ begin() };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_reverse_iterator
		directed_graph<T, A>::crbegin() const noexcept
	{
		return rbegin();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_reverse_iterator
		directed_graph<T, A>::crend() const noexcept
	{
		return rend();
	}


	template<typename T, typename A>
	std::optional<typename directed_graph<T, A>::nodes_adjacent_to_result>
		directed_graph<T, A>::nodes_adjacent_to(const T& node_value) const noexcept
	{
		auto iter{ find_node(node_value) };
		if (iter == std::end(m_nodes)) { return {}; }
		return nodes_adjacent_to_result {
			const_adjacent_nodes_iterator{ std::cbegin(iter->get_adjacent_nodes_indices()), this },
			const_adjacent_nodes_iterator{ std::cend(iter->get_adjacent_nodes_indices()), this }
		};
	}


	template<typename T, typename A>
	std::set<T> directed_graph<T, A>::get_adjacent_nodes_values(
		const typename details::graph_node<T, A>::adjacency_list_type& indices) const
	{
		std::set<T> values;
		for (auto&& index : indices)
		{
			values.insert(m_nodes[index].value());
		}
		return values;
	}

	template<typename T, typename A>
	bool directed_graph<T, A>::operator==(const directed_graph& rhs) const
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

	template<typename T, typename A>
	void directed_graph<T, A>::swap(directed_graph& other_graph) noexcept
	{
		using std::swap;
		m_nodes.swap(other_graph.m_nodes);
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::size_type directed_graph<T, A>::size() const noexcept
	{
		return m_nodes.size();
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::size_type directed_graph<T, A>::max_size() const noexcept
	{
		return m_nodes.max_size();
	}

	template<typename T, typename A>
	bool directed_graph<T, A>::empty() const noexcept
	{
		return m_nodes.empty();
	}

}
