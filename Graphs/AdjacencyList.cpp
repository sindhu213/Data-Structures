#include <iostream>
#include <set>
#include <map>

// Implementation of undirectedGraph can follow the same principle
class DirectedGraph
{
private:
    using graph_repr =  std::map<int, std::set<int>> ;
    graph_repr graph;

public:
    DirectedGraph() {}
    DirectedGraph(const graph_repr &arg) : graph{arg} {}
    std::set<int> &operator[](int vertex) { return graph[vertex]; }
    void outputGraph() const;
};

void DirectedGraph::outputGraph() const
{
    for (const auto &[key, values] : graph)
    {
        std::cout << key << " -> ";
        for (const auto &value : values)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    DirectedGraph dg;
    dg[1] = {2,3,4};
    dg[4] = {5,6,7};

    dg.outputGraph();
    return 0;
}