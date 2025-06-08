#include "isomorphismsolver.h"

QList<QPair<Vertex *, Vertex *> > IsomorphismSolver::VF2Algorithm(const Graph &graph1, const Graph &graph2)
{
    QList<QPair<Vertex*, Vertex*>> accordance;

    if (!CheckBasicInvariants(graph1, graph2))
        return accordance;

    QMap<Vertex*, Vertex*> mapping;
    QSet<Vertex*> used;

    if (IsomorphismBacktracking(graph1, graph2, mapping, used, graph1._vertices.toList()))
        for (auto it = mapping.begin(); it != mapping.end(); ++it)
            accordance.append(qMakePair(it.key(), it.value()));

    return accordance;
}

bool IsomorphismSolver::CheckBasicInvariants(const Graph &graph1, const Graph &graph2)
{
    if (graph1._vertices.size() != graph2._vertices.size())
        return false;
    if (graph1._edges.size() != graph2._edges.size())
        return false;

    QList<QPair<int, int>> degrees1, degrees2;
    for (Vertex* v : graph1._vertices)
        degrees1.append(qMakePair(graph1._out_edges[v].size(), graph1._in_edges[v].size()));
    for (Vertex* v : graph2._vertices)
        degrees2.append(qMakePair(graph2._out_edges[v].size(), graph2._in_edges[v].size()));

    std::sort(degrees1.begin(), degrees1.end());
    std::sort(degrees2.begin(), degrees2.end());

    if (degrees1 != degrees2)
        return false;

    return true;
}

bool IsomorphismSolver::IsomorphismBacktracking(const Graph &graph1, const Graph &graph2, QMap<Vertex *, Vertex *> &mapping, QSet<Vertex *> used, QList<Vertex *> unassigned)
{
    if (unassigned.isEmpty())
        return VerifyIsomorphism(graph1, graph2, mapping);

    Vertex* v = unassigned.takeFirst();

    QList<Vertex*> candidates = FindCandidates(graph1, graph2, mapping, used, v);

    for (Vertex* candidate : candidates)
    {
        mapping[v] = candidate;
        used.insert(candidate);

        if (IsomorphismBacktracking(graph1, graph2, mapping, used, unassigned))
            return true;

        mapping.remove(v);
        used.remove(candidate);
    }

    unassigned.prepend(v);
    return false;
}

QList<Vertex *> IsomorphismSolver::FindCandidates(const Graph &graph1, const Graph &graph2, const QMap<Vertex *, Vertex *> &mapping, const QSet<Vertex *> used, Vertex *v)
{
    QList<Vertex*> candidates;

    int out_degree = graph1._out_edges[v].size();
    int in_degree = graph1._in_edges[v].size();

    QMap<Vertex*, bool> adj_out_limitations;
    for (Edge* e : graph1._out_edges[v])
        if (mapping.contains(e->_target))
            adj_out_limitations[mapping[e->_target]] = true;

    QMap<Vertex*, bool> adj_in_limitations;
    for (Edge* e : graph1._in_edges[v])
        if (mapping.contains(e->_source))
            adj_in_limitations[mapping[e->_source]] = true;

    for (Vertex* other_v : graph2._vertices)
    {
        if (used.contains(other_v))
            continue;

        if (graph2._out_edges[other_v].size() != out_degree ||
            graph2._in_edges[other_v].size() != in_degree)
            continue;

        bool satisfies_limitations = true;

        for (auto it = adj_out_limitations.begin(); it != adj_out_limitations.end(); ++it)
        {
            Vertex* reqired_adj = it.key();

            bool is_adjacent = false;
            for (Edge* e : graph2._out_edges[other_v])
                if (e->_target == reqired_adj)
                {
                    is_adjacent = true;
                    break;
                }

            if (!is_adjacent)
            {
                satisfies_limitations = false;
                break;
            }
        }

        for (auto it = adj_in_limitations.begin(); it != adj_in_limitations.end(); ++it)
        {
            if(!satisfies_limitations)
                break;

            Vertex* reqired_adj = it.key();

            bool is_adjacent = false;
            for (Edge* e : graph2._in_edges[other_v])
                if (e->_source == reqired_adj)
                {
                    is_adjacent = true;
                    break;
                }

            if (!is_adjacent)
            {
                satisfies_limitations = false;
                break;
            }
        }

        if (satisfies_limitations)
            candidates.append(other_v);
    }

    return candidates;
}

bool IsomorphismSolver::VerifyIsomorphism(const Graph &graph1, const Graph &graph2, const QMap<Vertex *, Vertex *> &mapping)
{
    for (Edge* e : graph1._edges)
    {
        Vertex* mapped_source = mapping[e->_source];
        Vertex* mapped_target = mapping[e->_target];

        bool mapped_found = false;
        for (Edge* other_e : graph2._out_edges[mapped_source]) {
            if (other_e->_target == mapped_target) {
                mapped_found = true;
                break;
            }
        }

        if (!mapped_found)
            return false;
    }

    return true;
}
