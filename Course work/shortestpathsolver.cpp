#include "shortestpathsolver.h"

QList<Edge*> ShortestPathSolver::Dijkstra(const Graph &graph, Vertex *start, Vertex *end)
{
    QHash<Vertex*, int> distance;
    QHash<Vertex*, Vertex*> previous;
    QSet<Vertex*> visited;

    using PQItem = std::pair<int, Vertex*>;
    std::priority_queue<PQItem, std::vector<PQItem>, std::greater<PQItem>> prior_queue;

    for (Vertex* v : graph._vertices)
        distance[v] = INT_MAX;
    distance[start] = 0;
    prior_queue.push({0, start});

    while (!prior_queue.empty())
    {
        auto [cur_dist, u] = prior_queue.top();
        prior_queue.pop();

        if (visited.contains(u))
            continue;
        visited.insert(u);

        if (u == end) break;

        for (Edge* edge : graph._out_edges.value(u))
        {
            Vertex* v = edge->_target;
            int new_dist = cur_dist + edge->_weight;

            if (new_dist < distance[v])
            {
                distance[v] = new_dist;
                previous[v] = u;
                prior_queue.push({new_dist, v});
            }
        }
    }

    if (distance[end] == INT_MAX)
        return {};

    QList<Edge*> path;
    for (Vertex* at = end; at != nullptr; at = previous[at])
    {
        for (Edge* e : graph._in_edges[at])
            if (e->_source == previous[at])
                path.prepend(e);
    }
    //path.prepend(at);

    return path;
}
