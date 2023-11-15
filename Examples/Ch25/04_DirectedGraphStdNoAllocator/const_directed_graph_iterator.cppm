export module directed_graph:const_directed_graph_iterator;

import std;

namespace ProCpp
{

	// Forward declaration.
	export
	template<typename T>
	class directed_graph;

	template<typename DirectedGraph>
	class const_directed_graph_iterator
	{
	public:
		using value_type = typename DirectedGraph::value_type;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = const value_type*;
		using reference = const value_type&;
		using node_container_iterator = typename DirectedGraph::node_container_type::const_iterator;

		// Bidirectional iterators must supply a default constructor.
		const_directed_graph_iterator() = default;

		explicit const_directed_graph_iterator(node_container_iterator it);

		reference operator*() const;

		// Return type must be something to which -> can be applied.
		// So, return a pointer.
		pointer operator->() const;

		const_directed_graph_iterator& operator++();
		const_directed_graph_iterator operator++(int);

		const_directed_graph_iterator& operator--();
		const_directed_graph_iterator operator--(int);

		// Defaulted operator==.
		bool operator==(const const_directed_graph_iterator&) const = default;

	protected:
		friend class directed_graph<value_type>;

		node_container_iterator m_nodeIterator;
	};

	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>::const_directed_graph_iterator(
		node_container_iterator it) : m_nodeIterator{ it }
	{
	}

	// Return a reference to the actual element.
	template<typename DirectedGraph>
	typename const_directed_graph_iterator<DirectedGraph>::reference
		const_directed_graph_iterator<DirectedGraph>::operator*() const
	{
		return m_nodeIterator->value();
	}

	// Return a pointer to the actual element, so the compiler can
	// apply -> to it to access the actual desired field.
	template<typename DirectedGraph>
	typename const_directed_graph_iterator<DirectedGraph>::pointer
		const_directed_graph_iterator<DirectedGraph>::operator->() const
	{
		return &m_nodeIterator->value();
	}

	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>&
		const_directed_graph_iterator<DirectedGraph>::operator++()
	{
		++m_nodeIterator;
		return *this;
	}

	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>
		const_directed_graph_iterator<DirectedGraph>::operator++(int)
	{
		auto oldIt{ *this };
		++*this;
		return oldIt;
	}

	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>&
		const_directed_graph_iterator<DirectedGraph>::operator--()
	{
		--m_nodeIterator;
		return *this;
	}

	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>
		const_directed_graph_iterator<DirectedGraph>::operator--(int)
	{
		auto oldIt{ *this };
		--*this;
		return oldIt;
	}

}
