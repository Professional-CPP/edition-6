
////////////////////////////////////////////////////////////////////////////
////
//// NOTE:
////   This file does not compile on itself.
////   It just contains the implementations for the find() member function.
////   You can take the code from Examples\Ch25\04_DirectedGraph
////   and add the below find() member function.
////
////////////////////////////////////////////////////////////////////////////

namespace ProCpp
{

	export
	template<typename T>
	class directed_graph
	{
	public:
		// ...

		// Finds an element in the graph.
		// Returns an end iterator if not found.
		const_iterator find(const T& node_value) const;

		// ...
 	};

	template<typename T>
	typename directed_graph<T>::const_iterator
		directed_graph<T>::find(const T& node_value) const
	{
		auto iter{ find_node(node_value) };
		return const_iterator{ iter };
	}

}


////////////////////////////////////////////////////////////////////////////
////
//// The find() member function can be tested as follows.
////
////////////////////////////////////////////////////////////////////////////

directed_graph graph;

// ... fill the graph ...

auto result{ graph.find(44) };
if (result != end(graph)) {
	println("Found 44.");
} else {
	println("Didn't find 44.");
}
