#include "common.h"
#include "sum_tree.h"
#include "binary_heap.h"
#include "priority_queue.h"

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

    return 0;
}

// EOF //
