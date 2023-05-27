#include "common.h"
#include "sum_tree.h"

int main (int argc, char** argv)
{
    printf ("Hello world\n");

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

    return 0;
}

// EOF //
