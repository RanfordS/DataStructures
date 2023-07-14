#include "graph.h"


bool graphAllocate (Graph* graph, size_t vertexCount, size_t edgeCount)
{
    graph->vertexCount = vertexCount;
    graph->edgeCount = edgeCount;
    graph->vertexWeight = malloc (vertexCount*sizeof (size_t));
    graph->edge = malloc (edgeCount*sizeof (GraphEdge));
    if (graph->vertexWeight && graph->edge) return false;
    free (graph->vertexWeight);
    free (graph->edge);
    return true;
}

void graphRelease (Graph* graph)
{
    free (graph->vertexWeight);
    free (graph->edge);
}

// EOF //
