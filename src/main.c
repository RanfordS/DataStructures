#include "common.h"
#include "sum_tree.h"
#include "binary_heap.h"

int main (int argc, char** argv)
{
    printf ("SumTree\n");

    {
        SumTree tree;
        sumTreeAllocateCount (&tree, 4);

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

        binaryHeapInsert (&heap, 5); binaryHeapDebug (&heap);
        binaryHeapInsert (&heap, 3); binaryHeapDebug (&heap);
        binaryHeapInsert (&heap, 4); binaryHeapDebug (&heap);
        binaryHeapInsert (&heap, 1); binaryHeapDebug (&heap);

        binaryHeapInsert (&heap, 8); binaryHeapDebug (&heap);
        binaryHeapInsert (&heap, 8); binaryHeapDebug (&heap);

        binaryHeapInsert (&heap, 2); binaryHeapDebug (&heap);
        binaryHeapInsert (&heap, 2); binaryHeapDebug (&heap);

        binaryHeapRelease (&heap);
    }

    return 0;
}

// EOF //
