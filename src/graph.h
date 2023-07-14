#pragma once
#include "common.h"

typedef struct
{
    size_t from;
    size_t to;
    size_t weight;
}
GraphEdge;

typedef struct
{
    size_t  vertexCount;
    size_t* vertexWeight;
    size_t  edgeCount;
    GraphEdge* edge;
}
Graph;

extern bool graphAllocate (Graph* graph, size_t vertexCount, size_t edgeCount);
extern void graphRelease (Graph* graph);
