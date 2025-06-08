#ifndef GRAPH_H
#define GRAPH_H
#pragma once

#include <QHash>
#include <QVector>
#include <QList>
#include <QSet>
#include <QPair>
#include <QMap>

#include <climits>
#include <queue>

#include <QFile>
#include <QDataStream>

#include "vertex.h"
#include "edge.h"

const int int_max = 2147483647;

class Graph
{
public:
    //auto cmp[](Vertex* a, Vertex* b) {return a->_index > b->_index; }
    QSet<Vertex*> _vertices;
    QSet<Edge*> _edges;

    QList<Vertex*> _sources;
    QList<Vertex*> _targets;

    QHash<Vertex*, QList<Edge*>> _out_edges;
    QHash<Vertex*, QList<Edge*>> _in_edges;

    std::priority_queue<int> index_queue;
public:
    Graph();
    ~Graph()
    {
        for (Vertex* v : _vertices.toList())
            RemoveVertex(v);

        _vertices.clear();
        _edges.clear();
        _sources.clear();
        _targets.clear();
        _out_edges.clear();
        _in_edges.clear();

        // delete _vertices;
        // delete _edges;
        // delete _sources;
        // delete _targets;
        // delete _out_edges;
        // delete _in_edges;
    }
    void AddVertex(Vertex* v)
    {
        if (!index_queue.empty())
        {
            v->_index = index_queue.top();
            index_queue.pop();
        }
        else
            v->_index = _vertices.size();

        _vertices.insert(v);
    }
    void AddEdge(Edge* e)
    {
        _edges.insert(e);
        _out_edges[e->_source].append(e);
        _in_edges[e->_target].append(e);
    }
    void RemoveVertex(Vertex* v)
    {
        index_queue.push(v->_index);

        if (!_vertices.contains(v))
            return;

        for (Edge* e : _out_edges[v])
            RemoveEdge(e);

        for (Edge* e : _in_edges[v])
            RemoveEdge(e);

        _vertices.remove(v);
        _out_edges.remove(v);
        _in_edges.remove(v);

        delete v;
    }
    void RemoveEdge(Edge *e)
    {
        if (!_edges.contains(e))
            return;

        Vertex* source = e->_source;
        Vertex* target = e->_target;

        _out_edges[source].removeAll(e);
        _in_edges[target].removeAll(e);

        _edges.remove(e);

        delete e;
    }

    int SaveToBinary(const QString& file_name)
    {
        QFile file(file_name);
        if (!file.open(QIODevice::WriteOnly))
            return 1;

        QDataStream out(&file);
        out.writeRawData("GRPH", 4);
        out << static_cast<qint16>(1);
        out << static_cast<qint32>(_vertices.size());
        out << static_cast<qint32>(_edges.size());

        for (Vertex* v : _vertices)
        {
            out << static_cast<quint32>(v->_index);
            out << static_cast<float>(v->x());
            out << static_cast<float>(v->y());

            QByteArray name = v->GetName().toUtf8();
            out << static_cast<qint32>(name.size());
            out.writeRawData(name.constData(), name.size());
        }

        for (Edge* e : _edges)
        {
            out << static_cast<qint32>(e->_source->_index);
            out << static_cast<qint32>(e->_target->_index);
            out << static_cast<float>(e->_weight);
            out << static_cast<float>(e->_price);
        }

        return 0;
    }

    int LoadFromBinary(const QString& file_name)
    {
        QFile file(file_name);
        if (!file.open(QIODevice::ReadOnly))
            return 1;

        QDataStream in(&file);
        char magic[5]{};
        in.readRawData(magic, 4);
        if (strcmp(magic, "GRPH") != 0)
            return 2;

        quint16 version;
        in >> version;
        if (version != 1)
            return 3;

        quint32 v_count, e_count;
        in >> v_count >> e_count;

        QHash<quint32, Vertex*> vertex_map;

        for (quint32 i = 0; i < v_count; ++i)
        {
            quint32 index;
            float x, y;
            quint32 name_length;

            in >> index >> x >> y >> name_length;
            char* name_buffer = new char[name_length + 1];
            in.readRawData(name_buffer, name_length);
            name_buffer[name_length] = '\0';
            QString name = QString::fromUtf8(name_buffer);
            delete[] name_buffer;

            Vertex* v = new Vertex(x, y, name);
            AddVertex(v);
            v->_index = index;
            vertex_map[index] = v;
        }

        for (quint32 i = 0; i < e_count; ++i)
        {
            quint32 source_index, target_index;
            float weight, curve_type;
            in >> source_index >> target_index >> weight >> curve_type;

            Vertex* source = vertex_map[source_index];
            Vertex* target = vertex_map[target_index];

            Edge* e = new Edge(source, target, Qt::black, weight, curve_type);
            AddEdge(e);
        }

        return 0;
    }
};

#endif // GRAPH_H
