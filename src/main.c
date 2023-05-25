#include "common.h"
#include "sum_tree.h"

int main (int argc, char** argv)
{
    printf ("Hello world\n");

    {
        SumTree tree;
        sumTreeAllocate (&tree, 2);

        sumTreeInsert (&tree, 1);
        sumTreeInsert (&tree, 2);
        sumTreeInsert (&tree, 3);
        sumTreeInsert (&tree, 4);

        sumTreeSet (&tree, 2, 7);

        printf ("-----\n");
        sumTreeRemove (&tree, 0);

        sumTreeRelease (&tree);
    }

    return 0;
}

// EOF //
