#include "mincostflowsolver.h"

QPair<int, int> MinCostFlowSolver::MinCostFlow(const Graph &graph, Vertex *source, Vertex *sink, int required_flow)
{
    int total_flow = 0;
    int total_cost = 0;
    QHash<Vertex*, int> potentials;

    for (Vertex* v : graph._vertices)
        potentials[v] = 0;

    for (Edge* e : graph._edges)
    {
        e->_flow = 0;
        if(!e->reverse)
        {
            e->reverse = new Edge(e->_target, e->_source, Qt::black, 0, -e->_price);
            e->reverse->reverse = e;
        }
        e->reverse->_flow = 0;
    }

    while (total_flow < required_flow)
    {
        auto [path, dist] = MinCostFlowSolver::BellmanFord(graph, source, sink, potentials);

        if (path.isEmpty())
            break;

        int flow = INT_MAX;
        for (Edge* e : path)
            flow = qMin(flow, e->_weight - e->_flow);
        flow = qMin(flow, required_flow - total_flow);

        for (Edge* e : path)
        {
            e->_flow += flow;
            e->reverse->_flow -= flow;
            total_cost += flow * e->_price;
        }

        total_flow += flow;

        for (Vertex* v : graph._vertices)
            if (dist[v] != INT_MAX)
                potentials[v] += dist[v];
    }

    return {total_flow, total_cost};
}

QPair<QList<Edge *>, QHash<Vertex *, int> > MinCostFlowSolver::BellmanFord(const Graph &graph, Vertex *source, Vertex *sink, QHash<Vertex *, int> &pot)
{
    QHash<Vertex*, int> dist;
    QHash<Vertex*, Edge*> pred;

    for (Vertex* v : graph._vertices)
        dist[v] = INT_MAX / 2;
    dist[source] = 0;

    bool relaxed = true;
    int iteration = 0;
    const int max_iteration = graph._vertices.size();

    while (relaxed && iteration++ < max_iteration)
    {
        relaxed = false;

        for (Edge* e : graph._edges)
        {
            if (e->_flow == e->_weight)
                continue;

            int pot_price = e->_price + pot[e->_source] - pot[e->_target];

            if (dist[e->_source] + pot_price < dist[e->_target])
            {
                dist[e->_target] = dist[e->_source] + pot_price;
                pred[e->_target] = e;
                relaxed = true;
            }
        }

        for (Edge* e : graph._edges)
        {
            e = e->reverse;

            if (e->_flow == e->_weight)
                continue;

            int pot_price = e->_price + pot[e->_source] - pot[e->_target];

            if (dist[e->_source] + pot_price < dist[e->_target])
            {
                dist[e->_target] = dist[e->_source] + pot_price;
                pred[e->_target] = e;
                relaxed = true;
            }
        }
    }

    if (dist[sink] >= INT_MAX / 4 || relaxed)
        return {{}, dist};

    QList<Edge*> path;
    Vertex* current = sink;
    while (current != source)
    {
        Edge* e = pred[current];
        path.prepend(e);
        current = e->_source;
    }

    return {path, dist};
}
