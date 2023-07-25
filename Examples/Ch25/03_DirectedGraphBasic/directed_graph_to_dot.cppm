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

		output << std::format("digraph {} {{", graph_name.data()) << std::endl;
		for (std::size_t index{ 0 }; index < graph.size(); ++index)
		{
			const auto& node_value{ graph[index] };
			const auto adjacent_nodes{ graph.get_adjacent_nodes_values(node_value) };
			if (adjacent_nodes.empty())
			{
				output << node_value << std::endl;
			}
			else
			{
				for (auto&& node : adjacent_nodes)
				{
					output << std::format("{} -> {}", node_value, node) << std::endl;
				}
			}
		}
		output << "}" << std::endl;

		return output.str();
	}

}
