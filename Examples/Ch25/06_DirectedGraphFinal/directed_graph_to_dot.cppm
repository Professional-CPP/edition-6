export module directed_graph.to_dot;

import directed_graph;
import std;

namespace ProCpp
{

	// Returns a given graph in DOT format.
	export
	template <typename T, typename A>
	std::string to_dot(const directed_graph<T, A>& graph, std::string_view graph_name)
	{
		std::stringstream output;

		output << std::format("digraph {} {{", graph_name.data()) << std::endl;
		for (auto&& node : graph)
		{
			const auto b{ graph.cbegin(node) };
			const auto e{ graph.cend(node) };
			if (b == e)
			{
				output << node << std::endl;
			}
			else
			{
				for (auto iter{ b }; iter != e; ++iter)
				{
					output << std::format("{} -> {}", node, *iter) << std::endl;
				}
			}
		}
		output << "}" << std::endl;

		return output.str();
	}

}
