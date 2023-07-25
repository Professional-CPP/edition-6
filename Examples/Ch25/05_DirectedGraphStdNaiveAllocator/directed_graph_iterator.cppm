export module directed_graph:directed_graph_iterator;

import :const_directed_graph_iterator;
import std;

namespace ProCpp
{

	template<typename DirectedGraph>
	class directed_graph_iterator : public const_directed_graph_iterator<DirectedGraph>
	{
	public:
		using value_type = typename DirectedGraph::value_type;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using iterator_type = typename DirectedGraph::nodes_container_type::iterator;

		// Bidirectional iterators must supply a default constructor.
		// Using an iterator constructed with the default constructor
		// is undefined, so it doesn't matter how it's initialized.
		directed_graph_iterator() = default;

		directed_graph_iterator(iterator_type it);

		reference operator*() const;

		// Return type must be something to which -> can be applied.
		// So, return a pointer.
		pointer operator->() const;

		directed_graph_iterator& operator++();
		directed_graph_iterator operator++(int);

		directed_graph_iterator& operator--();
		directed_graph_iterator operator--(int);
	};

	template<typename DirectedGraph>
	directed_graph_iterator<DirectedGraph>::directed_graph_iterator(
		iterator_type it) : const_directed_graph_iterator<DirectedGraph>{ it }
	{
	}

	// Return a reference to the actual element.
	template<typename DirectedGraph>
	typename directed_graph_iterator<DirectedGraph>::reference
		directed_graph_iterator<DirectedGraph>::operator*() const
	{
		return const_cast<reference>(this->m_nodeIterator->value());
	}

	// Return a pointer to the actual element, so the compiler can
	// apply -> to it to access the actual desired field.
	template<typename DirectedGraph>
	typename directed_graph_iterator<DirectedGraph>::pointer
		directed_graph_iterator<DirectedGraph>::operator->() const
	{
		return const_cast<pointer>(&(this->m_nodeIterator->value()));
	}

	// Defer the details to the increment() helper in the base class.
	template<typename DirectedGraph>
	directed_graph_iterator<DirectedGraph>&
		directed_graph_iterator<DirectedGraph>::operator++()
	{
		this->increment();
		return *this;
	}

	// Defer the details to the increment() helper in the base class.
	template<typename DirectedGraph>
	directed_graph_iterator<DirectedGraph>
		directed_graph_iterator<DirectedGraph>::operator++(int)
	{
		auto oldIt{ *this };
		this->increment();
		return oldIt;
	}

	// Defer the details to the decrement() helper in the base class.
	template<typename DirectedGraph>
	directed_graph_iterator<DirectedGraph>&
		directed_graph_iterator<DirectedGraph>::operator--()
	{
		this->decrement();
		return *this;
	}

	// Defer the details to the decrement() helper in the base class.
	template<typename DirectedGraph>
	directed_graph_iterator<DirectedGraph>
		directed_graph_iterator<DirectedGraph>::operator--(int)
	{
		auto oldIt{ *this };
		this->decrement();
		return oldIt;
	}

}
