export module directed_graph:adjacent_nodes_iterator;

import :const_adjacent_nodes_iterator;
import std;

namespace ProCpp
{

	template<typename DirectedGraph>
	class adjacent_nodes_iterator : public const_adjacent_nodes_iterator<DirectedGraph>
	{
	public:
		using value_type = typename DirectedGraph::value_type;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using iterator_type = std::set<std::size_t>::iterator;

		// Bidirectional iterators must supply a default constructor.
		// In this case, the default-constructed iterator serves as an
		// end iterator.
		adjacent_nodes_iterator() = default;

		// No transfer of ownership of graph.
		adjacent_nodes_iterator(iterator_type it, const DirectedGraph* graph);

		reference operator*() const;

		// Return type must be something to which -> can be applied.
		// Return a pointer to a node, to which the compiler
		// will apply -> again.
		pointer operator->() const;

		adjacent_nodes_iterator& operator++();
		adjacent_nodes_iterator operator++(int);

		adjacent_nodes_iterator& operator--();
		adjacent_nodes_iterator operator--(int);
	};

	template<typename DirectedGraph>
	adjacent_nodes_iterator<DirectedGraph>::adjacent_nodes_iterator(
		iterator_type it, const DirectedGraph* graph)
		: const_adjacent_nodes_iterator<DirectedGraph>{ it, graph }
	{
	}

	// Return a reference to the node.
	template<typename DirectedGraph>
	typename adjacent_nodes_iterator<DirectedGraph>::reference
		adjacent_nodes_iterator<DirectedGraph>::operator*() const
	{
		// Return an reference to the actual node, not the index to the node.
		return const_cast<reference>((*(this->m_graph))[*(this->m_adjacentNodeIterator)]);
	}

	// Return a pointer to the actual node, so the compiler can
	// apply -> to it to access the actual desired field.
	template<typename DirectedGraph>
	typename adjacent_nodes_iterator<DirectedGraph>::pointer
		adjacent_nodes_iterator<DirectedGraph>::operator->() const
	{
		return const_cast<pointer>(&((*(this->m_graph))[*(this->m_adjacentNodeIterator)]));
	}

	// Defer the details to the increment() helper.
	template<typename DirectedGraph>
	adjacent_nodes_iterator<DirectedGraph>&
		adjacent_nodes_iterator<DirectedGraph>::operator++()
	{
		this->increment();
		return *this;
	}

	// Defer the details to the increment() helper.
	template<typename DirectedGraph>
	adjacent_nodes_iterator<DirectedGraph>
		adjacent_nodes_iterator<DirectedGraph>::operator++(int)
	{
		auto oldIt{ *this };
		this->increment();
		return oldIt;
	}

	// Defer the details to the decrement() helper.
	template<typename DirectedGraph>
	adjacent_nodes_iterator<DirectedGraph>&
		adjacent_nodes_iterator<DirectedGraph>::operator--()
	{
		this->decrement();
		return *this;
	}

	// Defer the details to the decrement() helper.
	template<typename DirectedGraph>
	adjacent_nodes_iterator<DirectedGraph>
		adjacent_nodes_iterator<DirectedGraph>::operator--(int)
	{
		auto oldIt{ *this };
		this->decrement();
		return oldIt;
	}

}
