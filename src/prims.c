#include "prims.h"



Graph prims (const Graph* source)
{
#define SWAP(i,j) { GraphEdge t = edge[i]; edge[i] = edge[j]; edge[j] = t; }
#define GET_ADDED(i) ((vertexAdded[i/64] >> (i % 64)) & 1)
#define SET_ADDED(i) vertexAdded[i/64] |= (1 << (i % 64))

    Graph result =
    {
        .vertexCount = source->vertexCount,
        .edgeCount   = source->vertexCount - 1,
    };
    result.vertexWeight = malloc (result.vertexCount*sizeof (size_t));
    result.edge = malloc (result.edgeCount*sizeof (GraphEdge));
    if (!result.vertexWeight || !result.edge) printf ("oh no\n"); //TODO: actual error handling instead of just meme-ing
    memcpy (result.vertexWeight,
            source->vertexWeight,
            source->vertexCount*sizeof (size_t));

    size_t doneTil = 0;
    size_t considerTil = 0;
    size_t edgeCount = source->edgeCount;
    GraphEdge* edge = malloc (edgeCount*sizeof (GraphEdge));
    memcpy (edge, source->edge, edgeCount*sizeof (GraphEdge));
    uint64_t* vertexAdded = calloc (
            (source->vertexCount + 63)/64,
            sizeof (uint64_t));
    vertexAdded[0] = 1;

    // add all edges connecting to vertex 0 to the considered range
    for (size_t i = 0; i < edgeCount; ++i)
    {
        if ((edge[i].to == 0) || (edge[i].from == 0))
        {
            SWAP(i,considerTil);
            ++considerTil;
        }
    }

    for (size_t i = 1; i < source->vertexCount; ++i)
    {
        // find min edge
        size_t minIndex = doneTil;
        size_t minWeight = edge[doneTil].weight;
        for (size_t i = doneTil + 1; i < considerTil; ++i)
        {
            size_t newWeight = edge[i].weight;
            if (newWeight < minWeight)
            {
                minIndex = i;
                minWeight = newWeight;
            }
        }
        // add to our results
        result.edge[i - 1] = edge[minIndex];
        size_t newVertex = GET_ADDED(edge[minIndex].to) ? edge[minIndex].from : edge[minIndex].to;
        SET_ADDED(newVertex);
        // and rearrange our list
        for (size_t i = doneTil; i < considerTil; ++i)
        {
            if ((edge[i].to == newVertex) || (edge[i].from == newVertex))
            {
                SWAP(i,doneTil);
                ++doneTil;
            }
        }
        for (size_t i = considerTil; i < edgeCount; ++i)
        {
            if ((edge[i].to == newVertex) || (edge[i].from == newVertex))
            {
                SWAP(i,considerTil);
                ++considerTil;
            }
        }
    }

    free (edge);
    free (vertexAdded);

    return result;
#undef SWAP
#undef GET_BIT
#undef SET_BIT
}


