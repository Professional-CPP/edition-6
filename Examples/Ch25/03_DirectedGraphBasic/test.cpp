import directed_graph;
import directed_graph.to_dot;
import std;

using namespace ProCpp;
using namespace std;

// Force all code to be compiled for testing.
template class directed_graph<string>;

int main()
{
	directed_graph<int> graph;
	// Insert some nodes and edges.
	graph.insert(11);
	graph.insert(22);
	graph.insert(33);
	graph.insert(44);
	graph.insert(55);
	graph.insert_edge(11, 33);
	graph.insert_edge(22, 33);
	graph.insert_edge(22, 44);
	graph.insert_edge(22, 55);
	graph.insert_edge(33, 44);
	graph.insert_edge(44, 55);
	println("{}", to_dot(graph, "Graph1"));

	// Remove an edge and a node.
	graph.erase_edge(22, 44);
	graph.erase(44);
	println("{}", to_dot(graph, "Graph1"));

	// Print the size of the graph.
	println("Size: {}", graph.size());


	// Test swapping graphs.
	directed_graph<int> otherGraph;
	otherGraph.swap(graph);

	println("After swapping:");
	println("Size: {}", graph.size());

	// Test copying graphs.
	directed_graph<int> graphCopy{ otherGraph };
	println("otherGraph == graphCopy? {}", (otherGraph == graphCopy));

	graphCopy.erase(33);
	println("otherGraph == graphCopy? {}", (otherGraph == graphCopy));

	// Test equality
	directed_graph<int> graph1;
	graph1.insert(11);
	graph1.insert(22);
	graph1.insert(33);
	graph1.insert_edge(11, 22);
	graph1.insert_edge(11, 33);
	graph1.insert_edge(22, 33);

	directed_graph<int> graph2;
	graph2.insert(22);
	graph2.insert(11);
	graph2.insert(33);
	graph2.insert_edge(22, 33);
	graph2.insert_edge(11, 22);
	graph2.insert_edge(11, 33);

	println("{}", to_dot(graph1, "graph1"));
	println("{}", to_dot(graph2, "graph2"));

	println("are equal: {}", (graph1 == graph2));

	// Test assignment of graphs.
	directed_graph<int> graph3;
	graph3 = graph2;
	println("{}", to_dot(graph3, "graph3"));

	// Test a graph with strings.
	directed_graph<string> graphStrings;
	graphStrings.insert("String 1");
	string str{ "String 2" };
	graphStrings.insert(str);
	graphStrings.insert("String 3");
	graphStrings.insert("String 4");
	graphStrings.insert_edge("String 1", str);
	graphStrings.insert_edge("String 2", str);
	graphStrings.insert_edge("String 3", str);

	println("{}", to_dot(graphStrings, "String Graph"));
}
