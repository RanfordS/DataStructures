#include "binary_heap.h"



static size_t layerOfIndex (size_t index)
{
    size_t layer = 0;
    size_t capacity = 1;
    while (capacity <= index)
    {
        ++layer;
        capacity = 2*capacity + 1;
    }
    return layer;
}



void binaryHeapDebug (const BinaryHeap* heap)
{
    size_t layer = 0;
    size_t limit = 1;
    size_t index = 0;

    bool onNewLine = true;
    while (index < heap->used)
    {
        printf ("%i ", heap->data[index]);

        ++index;
        if (index >= limit)
        {
            ++layer;
            limit = 2*limit + 1;
            printf ("\n");
            onNewLine = true;
        }
        else onNewLine = false;
    }
    if (!onNewLine) printf ("\n");
    printf ("\n");
}



bool binaryHeapAllocateCount (BinaryHeap* heap, size_t count)
{
    heap->data = malloc (count*sizeof (uint32_t));
    heap->used = 0;
    heap->size = count;
    return !heap->data;
}



void binaryHeapRelease (BinaryHeap* heap)
{
    free (heap->data);
}



void binaryHeapBubbleUp (BinaryHeap* heap, size_t index, uint32_t value)
{
    while (true)
    {
        size_t parent = (index - 1)/2;
        if (parent == SIZE_MAX/2) break;

        if (value < heap->data[parent])
        {
            heap->data[index] = heap->data[parent];
            index = parent;
        }
        else break;
    }

    heap->data[index] = value;
}



void binaryHeapBubbleDown (BinaryHeap* heap, size_t index, uint32_t value)
{
    while (true)
    {
        size_t child = 2*index + 1;
        if (heap->used <= child) break;

        // if we have more than one child, we must choose the lesser one
        if (heap->used != child + 1)
        {
            if (heap->data[child + 1] < heap->data[child]) ++child;
        }

        if (heap->data[child] < value)
        {
            heap->data[index] = heap->data[child];
            index = child;
        }
        else break;
    }

    heap->data[index] = value;
}



void binaryHeapInsert (BinaryHeap* heap, uint32_t element)
{
    size_t index = heap->used++;
    binaryHeapBubbleUp (heap, index, element);
    binaryHeapDebug (heap);
}



uint32_t binaryHeapPop (BinaryHeap* heap)
{
    uint32_t result = heap->data[0];
    size_t tailIndex = --heap->used;
    binaryHeapBubbleDown (heap, 0, heap->data[tailIndex]);
    printf ("popped %u\n", result);
    binaryHeapDebug (heap);
    return result;
}




// EOF //
