export module directed_graph:const_adjacent_nodes_iterator_impl;

import std;

namespace ProCpp
{

	template<typename DirectedGraph>
	class const_adjacent_nodes_iterator_impl
	{
	public:
		using value_type = typename DirectedGraph::value_type;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = const value_type*;
		using reference = const value_type&;
		using iterator_type = std::set<std::size_t>::const_iterator;

		// Bidirectional iterators must supply a default constructor.
		// In this case, the default-constructed iterator serves as an
		// end iterator.
		const_adjacent_nodes_iterator_impl() = default;

		// No transfer of ownership of graph.
		explicit const_adjacent_nodes_iterator_impl(iterator_type it, const DirectedGraph* graph);

		reference operator*() const;

		// Return type must be something to which -> can be applied.
		// Return a pointer to a node, to which the compiler
		// will apply -> again.
		pointer operator->() const;

		const_adjacent_nodes_iterator_impl& operator++();
		const_adjacent_nodes_iterator_impl operator++(int);

		const_adjacent_nodes_iterator_impl& operator--();
		const_adjacent_nodes_iterator_impl operator--(int);

		// The following are ok as member functions because we don't
		// support comparisons of different types to this one.
		bool operator==(const const_adjacent_nodes_iterator_impl& rhs) const;
		bool operator!=(const const_adjacent_nodes_iterator_impl& rhs) const;

	protected:
		iterator_type m_adjacentNodeIterator;
		// If nullptr, then this instance is an end iterator.
		const DirectedGraph* m_graph{ nullptr };
	};

	template<typename DirectedGraph>
	const_adjacent_nodes_iterator_impl<DirectedGraph>::const_adjacent_nodes_iterator_impl(
		iterator_type it, const DirectedGraph* graph)
		: m_adjacentNodeIterator{ it }, m_graph{ graph }
	{
	}

	// Return a reference to the node.
	template<typename DirectedGraph>
	typename const_adjacent_nodes_iterator_impl<DirectedGraph>::reference
		const_adjacent_nodes_iterator_impl<DirectedGraph>::operator*() const
	{
		// Return a reference to the actual node, not the index to the node.
		return (*m_graph)[*m_adjacentNodeIterator];
	}

	// Return a pointer to the actual node, so the compiler can
	// apply -> to it to access the actual desired field.
	template<typename DirectedGraph>
	typename const_adjacent_nodes_iterator_impl<DirectedGraph>::pointer
		const_adjacent_nodes_iterator_impl<DirectedGraph>::operator->() const
	{
		return &((*m_graph)[*m_adjacentNodeIterator]);
	}

	template<typename DirectedGraph>
	const_adjacent_nodes_iterator_impl<DirectedGraph>&
		const_adjacent_nodes_iterator_impl<DirectedGraph>::operator++()
	{
		++m_adjacentNodeIterator;
		return *this;
	}

	template<typename DirectedGraph>
	const_adjacent_nodes_iterator_impl<DirectedGraph>
		const_adjacent_nodes_iterator_impl<DirectedGraph>::operator++(int)
	{
		auto oldIt{ *this };
		++*this;
		return oldIt;
	}

	template<typename DirectedGraph>
	const_adjacent_nodes_iterator_impl<DirectedGraph>&
		const_adjacent_nodes_iterator_impl<DirectedGraph>::operator--()
	{
		--m_adjacentNodeIterator;
		return *this;
	}

	template<typename DirectedGraph>
	const_adjacent_nodes_iterator_impl<DirectedGraph>
		const_adjacent_nodes_iterator_impl<DirectedGraph>::operator--(int)
	{
		auto oldIt{ *this };
		--*this;
		return oldIt;
	}

	template<typename DirectedGraph>
	bool const_adjacent_nodes_iterator_impl<DirectedGraph>::operator==(
		const const_adjacent_nodes_iterator_impl<DirectedGraph>& rhs) const
	{
		if (!m_graph && !rhs.m_graph)
		{
			// They are both end iterators.
			return true;
		}
		return (m_graph == rhs.m_graph &&
			m_adjacentNodeIterator == rhs.m_adjacentNodeIterator);
	}

	template<typename DirectedGraph>
	bool const_adjacent_nodes_iterator_impl<DirectedGraph>::operator!=(
		const const_adjacent_nodes_iterator_impl<DirectedGraph>& rhs) const
	{
		return !(*this == rhs);
	}

}
