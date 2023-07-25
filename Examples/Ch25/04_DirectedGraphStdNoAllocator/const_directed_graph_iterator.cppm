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
		using iterator_type = typename DirectedGraph::nodes_container_type::const_iterator;

		// Bidirectional iterators must supply a default constructor.
		// Using an iterator constructed with the default constructor
		// is undefined, so it doesn't matter how it's initialized.
		const_directed_graph_iterator() = default;

		const_directed_graph_iterator(iterator_type it);

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

		iterator_type m_nodeIterator;

		// Helper member functions for operator++ and operator--
		void increment();
		void decrement();
	};

	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>::const_directed_graph_iterator(
		iterator_type it) : m_nodeIterator{ it }
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
		return &(m_nodeIterator->value());
	}

	// Defer the details to the increment() helper.
	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>&
		const_directed_graph_iterator<DirectedGraph>::operator++()
	{
		increment();
		return *this;
	}

	// Defer the details to the increment() helper.
	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>
		const_directed_graph_iterator<DirectedGraph>::operator++(int)
	{
		auto oldIt{ *this };
		increment();
		return oldIt;
	}

	// Defer the details to the decrement() helper.
	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>&
		const_directed_graph_iterator<DirectedGraph>::operator--()
	{
		decrement();
		return *this;
	}

	// Defer the details to the decrement() helper.
	template<typename DirectedGraph>
	const_directed_graph_iterator<DirectedGraph>
		const_directed_graph_iterator<DirectedGraph>::operator--(int)
	{
		auto oldIt{ *this };
		decrement();
		return oldIt;
	}

	// Behavior is undefined if m_nodeIterator already refers to the past-the-end
	// element, or is otherwise invalid.
	template<typename DirectedGraph>
	void const_directed_graph_iterator<DirectedGraph>::increment()
	{
		++m_nodeIterator;
	}

	// Behavior is undefined if m_nodeIterator already refers to the first
	// element, or is otherwise invalid.
	template<typename DirectedGraph>
	void const_directed_graph_iterator<DirectedGraph>::decrement()
	{
		--m_nodeIterator;
	}

}
