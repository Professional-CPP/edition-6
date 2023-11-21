export module directed_graph.to_dot;

import directed_graph;
import std;

namespace ProCpp
{

	// Returns a given graph in DOT format.
	export
	template <typename T>
	std::string to_dot(const directed_graph<T>& graph, std::string_view graph_name)
	{
		std::stringstream output;

		output << std::format("digraph {} {{\n", graph_name);
		for (auto&& node : graph)
		{
			auto adjacent_nodes{ graph.nodes_adjacent_to(node) };
			if (!adjacent_nodes.has_value())
			{
				output << node << '\n';
			}
			else
			{
				for (const auto& adjacent_node : *adjacent_nodes)
				{
					output << std::format("{} -> {}\n", node, adjacent_node);
				}
			}
		}
		output << "}\n";

		return std::move(output).str();
	}

}
