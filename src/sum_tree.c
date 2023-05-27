#include "sum_tree.h"



void sumTreeDebug (SumTree* tree)
{
    size_t layer = 0;
    size_t limit = 1;
    size_t index = 0;
    while (layer <= tree->depth)
    {
        printf ("%i ", tree->data[index]);

        ++index;
        if (index >= limit)
        {
            ++layer;
            limit = 2*limit + 1;
            printf ("\n");
        }
    }
}



uint32_t sumTreeIndex (SumTree* tree, size_t index)
{
    return tree->data[index + (1 << tree->depth) - 1];
}



bool sumTreeAllocate (SumTree* tree, size_t depth)
{
    tree->depth = depth;
    tree->used = 0;
    size_t size = (2 << depth) - 1;
    uint32_t* mem = calloc (size, sizeof (uint32_t));
    tree->data = mem;
    return !mem;
}



void sumTreeRelease (SumTree* tree)
{
    free (tree->data);
}



void sumTreeSet (SumTree* tree, size_t index, uint32_t value)
{
    // make index relative
    index += (1 << tree->depth) - 1;
    tree->data[index] = value;

    for (size_t layer = 0; layer < tree->depth; ++layer)
    {
        index = (index - 1)/2;
        size_t left = 2*index + 1;
        tree->data[index] = tree->data[left] + tree->data[left + 1];
    }

    sumTreeDebug (tree);
}



void sumTreeInsert (SumTree* tree, uint32_t value)
{
    sumTreeSet (tree, tree->used++, value);
}



void sumTreeRecalculate (SumTree* tree)
{
    size_t index = (1 << tree->depth) - 1;
    while (index--)
    {
        size_t left = 2*index + 1;
        tree->data[index] = tree->data[left] + tree->data[left + 1];
    }
}



void sumTreeRemove (SumTree* tree, size_t index)
{
    // this was a mistake, re-evaluate
    abort ();
    /*
    size_t   tailIndex = --tree->used;
    uint32_t tailValue = sumTreeIndex (tree, tailIndex);
    sumTreeSet (tree, index, tailValue);
    sumTreeSet (tree, tailIndex, 0);
    */
}



size_t sumTreeFind (SumTree* tree, uint32_t query)
{
    size_t index = 0;

    // query should be less than the total sum
    if (tree->data[0] <= query) return -1;

    for (size_t layer = 0; layer < tree->depth; ++layer)
    {
        index = 2*index + 1;
        uint32_t leftVal = tree->data[index];
        if (leftVal <= query)
        {
            query -= leftVal;
            ++index;
        }
    }

    // make the position relative to the layer
    return index - (1 << tree->depth) + 1;
}



// EOF //
