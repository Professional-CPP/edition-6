
////////////////////////////////////////////////////////////////////////////
////
//// NOTE:
////   This file does not compile on itself.
////   It just contains the implementations for the find() member functions.
////   You can take the code from 06_DirectedGraphFinal and add the
////   below find() member functions to test them.
////
////////////////////////////////////////////////////////////////////////////

namespace ProCpp
{

	export
	template<typename T, typename A = std::allocator<T>>
	class directed_graph
	{
	public:
		// ...

		// Find an element in the graph.
		// Returns an end iterator if not found.
		iterator find(const T& node_value);
		const_iterator find(const T& node_value) const;

		// ...
 	};


    template<typename T, typename A>
	typename directed_graph<T, A>::iterator
		directed_graph<T, A>::find(const T& node_value)
	{
		auto iter{ find_node(node_value) };
		return iterator{ iter, this };
	}

	template<typename T, typename A>
	typename directed_graph<T, A>::const_iterator
		directed_graph<T, A>::find(const T& node_value) const
	{
		return const_cast<directed_graph*>(this)->find(node_value);
	}

}
