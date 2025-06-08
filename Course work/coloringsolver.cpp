#include "coloringsolver.h"

QHash<Vertex *, int> ColoringSolver::DSatur(const Graph &graph)
{
    QHash<Vertex*, int> color;
    QHash<Vertex*, int> saturation;
    QHash<Vertex*, QSet<int>> adjacent_colors;

    using QTuple = std::tuple<int, int, Vertex*>;
    auto cmp = [](const QTuple& a, const QTuple& b)
    {
        if (std::get<0>(a) != std::get<0>(b))
            return std::get<0>(a) < std::get<0>(b);
        return std::get<1>(a) < std::get<1>(b);
    };

    std::priority_queue<QTuple, std::vector<QTuple>, decltype(cmp)> pr_queue(cmp);

    for (Vertex* v : graph._vertices)
    {
        int degree = graph._out_edges[v].size() + graph._in_edges[v].size();
        pr_queue.push(std::make_tuple(0, degree, v));
        saturation[v] = 0;
    }


    while (!pr_queue.empty())
    {
        auto [max_sat, max_deg, max_v] = pr_queue.top();
        pr_queue.pop();

        if (color.contains(max_v))
            continue;

        int min_color = 0;
        while (adjacent_colors[max_v].find(min_color) != adjacent_colors[max_v].cend())
            ++min_color;

        color[max_v] = min_color;

        for (Vertex* neighbor : GetNeighbors(graph, max_v))
            if (!color.contains(neighbor))
                if (!adjacent_colors[neighbor].contains(min_color))
                {
                    adjacent_colors[neighbor].insert(min_color);
                    ++saturation[neighbor];
                    pr_queue.push(std::make_tuple(saturation[neighbor], GetNeighbors(graph, neighbor).size(), neighbor));
                }
    }

    return color;
}

int ColoringSolver::ChromaticNumber(const Graph &graph, const QHash<Vertex *, int> &colors)
{
    int max_color = 0;
    for (Vertex* v : graph._vertices)
        if (colors[v] > max_color)
            max_color = colors[v];

    return max_color + 1;
}

QSet<Vertex *> ColoringSolver::GetNeighbors(const Graph &graph, Vertex *v)
{
    QSet<Vertex*> neighbors;
    for (Edge* e : graph._out_edges[v])
        neighbors.insert(e->_target);
    for (Edge* e : graph._in_edges[v])
        neighbors.insert(e->_source);

    return neighbors;
}
