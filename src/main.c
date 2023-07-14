#include "common.h"
#include "sum_tree.h"
#include "binary_heap.h"
#include "priority_queue.h"
#include "prims.h"

int main (int argc, char** argv)
{
    printf ("SumTree\n");

    {
        SumTree tree;
        sumTreeAllocateCount (&tree, 4);
        
        printf ("\n");

        sumTreeSet (&tree, 0, 1);
        sumTreeSet (&tree, 1, 2);
        sumTreeSet (&tree, 2, 3);
        sumTreeSet (&tree, 3, 4);

        sumTreeSet (&tree, 2, 7);

        printf ("-----\n");

        sumTreeRelease (&tree);
    }

    printf ("BinaryHeap\n");

    {
        BinaryHeap heap;
        binaryHeapAllocateCount (&heap, 8);
        
        printf ("\n");

        binaryHeapInsert (&heap, 5);
        binaryHeapInsert (&heap, 3);
        binaryHeapInsert (&heap, 4);
        binaryHeapInsert (&heap, 1);

        binaryHeapPop (&heap);

        binaryHeapInsert (&heap, 8);

        binaryHeapPop (&heap);
        
        binaryHeapInsert (&heap, 8);
        binaryHeapInsert (&heap, 2);
        binaryHeapInsert (&heap, 2);

        printf ("-----\n");

        binaryHeapRelease (&heap);
    }

    printf ("PriorityQueue\n");

    {
        PriorityQueue queue;
        priorityQueueAllocateCount (&queue, 8);
        
        printf ("\n");

        priorityQueueInsert (&queue, 4);
        priorityQueueInsert (&queue, 5);
        priorityQueueInsert (&queue, 2);
        priorityQueueInsert (&queue, 3);
        priorityQueueInsert (&queue, 3);

        priorityQueuePop (&queue);

        priorityQueueInsert (&queue, 1);

        for (int i = 0; i < 3; ++i) priorityQueueInsert (&queue, 8);
        for (int i = 0; i < 3; ++i) priorityQueuePop (&queue);

        printf ("-----\n");

        priorityQueueRelease (&queue);
    }

    printf ("Prims\n");

    {
        Graph graph;
        graphAllocate (&graph, 5, 6);
        {
            size_t i = 0;
            graph.edge[i].from = 0;
            graph.edge[i].to   = 1;
            graph.edge[i].weight = 3;
            ++i;
            graph.edge[i].from = 1;
            graph.edge[i].to   = 2;
            graph.edge[i].weight = 4;
            ++i;
            graph.edge[i].from = 2;
            graph.edge[i].to   = 3;
            graph.edge[i].weight = 5;
            ++i;
            graph.edge[i].from = 3;
            graph.edge[i].to   = 4;
            graph.edge[i].weight = 6;
            ++i;
            graph.edge[i].from = 1;
            graph.edge[i].to   = 3;
            graph.edge[i].weight = 1;
            ++i;
            graph.edge[i].from = 2;
            graph.edge[i].to   = 4;
            graph.edge[i].weight = 8;
        }
        printf ("Source graph:\n");
        for (size_t i = 0; i < graph.edgeCount; ++i)
        {
            printf ("edge[%lu] from %lu to %lu with weight %lu\n",
                    i,
                    graph.edge[i].from,
                    graph.edge[i].to,
                    graph.edge[i].weight);
        }
        
        printf ("\nMinimum Spanning Tree:\n");
        
        Graph min = prims (&graph);
        for (size_t i = 0; i < min.edgeCount; ++i)
        {
            printf ("edge[%lu] from %lu to %lu with weight %lu\n",
                    i,
                    min.edge[i].from,
                    min.edge[i].to,
                    min.edge[i].weight);
        }

        printf ("\n-----\n");
        graphRelease (&graph);
        graphRelease (&min);
    }

    return 0;
}

// EOF //
