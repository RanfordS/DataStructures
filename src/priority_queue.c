#include "priority_queue.h"
#include <stdint.h>



void priorityQueueDebug (PriorityQueue* queue)
{
#if 0
    printf ("cap = %lu, used = %lu, start = %lu\n", queue->capacity, queue->used, queue->start);
    size_t p = queue->start;
    for (size_t i = 0; i < queue->used; ++i)
    {
        printf ("%i ", queue->data[p]);
        if (queue->capacity <= ++p) p = 0;
    }
    printf ("\n\n");
#else
    size_t head = queue->start;
    size_t tail = (head + queue->used - 1) % queue->capacity;
    if (head <= tail)
    {
        for (size_t i = 0; i < queue->capacity; ++i)
        {
            if ((head <= i) && (i <= tail))
            {
                if (i == head) printf ("^");
                printf ("%i ", queue->data[i]);
            }
            else
            {
                printf ("- ");
            }
        }
    }
    else
    {
        for (size_t i = 0; i < queue->capacity; ++i)
        {
            if ((head <= i) || (i <= tail))
            {
                if (i == head) printf ("^");
                printf ("%i ", queue->data[i]);
            }
            else
            {
                printf ("- ");
            }
        }
    }
    printf ("\n\n");
#endif
}



bool priorityQueueAllocateCount (PriorityQueue* queue, size_t count)
{
    queue->data = malloc (count * sizeof (uint32_t));
    if (!queue->data) return true;
    queue->capacity = count;
    queue->used = 0;
    queue->start = 0;
    return false;
}



void priorityQueueRelease (PriorityQueue* queue)
{
    free (queue->data);
}



void priorityQueueUnroll (const PriorityQueue* queue, uint32_t* output)
{
    size_t sourceIndex = queue->start;
    size_t outputIndex = 0;

    while ((sourceIndex < queue->capacity)
        && (outputIndex < queue->used))
    {
        output[outputIndex++] = queue->data[sourceIndex++];
    }
    sourceIndex = 0;
    while  (outputIndex < queue->used)
    {
        output[outputIndex++] = queue->data[sourceIndex++];
    }
}



void priorityQueueInsert (PriorityQueue* queue, uint32_t element)
{
    size_t headIndex = queue->start;
    // IMPORTANT! The tail index may exceed the bounds of the array,
    // use `% queue->capacity` to account for it.
    // Alternative is to do search on the regions separately, which sounds quite
    // nice actually.
    // Maybe try it later.
    size_t tailIndex = headIndex + queue->used - 1;
    uint32_t headValue = queue->data[headIndex];
    uint32_t tailValue = queue->data[tailIndex % queue->capacity];

    // special case: element is new head
    if (element <= headValue)
    {
        if (headIndex == 0)
        {
            queue->start = queue->capacity - 1;
        }
        else
        {
            --queue->start;
        }
        queue->data[queue->start] = element;
        ++queue->used;
        priorityQueueDebug (queue);
        return;
    }

    // special case: element is new tail
    if (tailValue <= element)
    {
        queue->data[(tailIndex + 1) % queue->capacity] = element;
        ++queue->used;
        priorityQueueDebug (queue);
        return;
    }

    // known: headValue < element < tailValue

    // binary search
    while ((tailIndex - headIndex) > 1)
    {
        size_t midIndex = (tailIndex + headIndex)/2;
        uint32_t midValue = queue->data[midIndex % queue->capacity];

        if (midValue < element)
        {
            headIndex = midIndex;
            headValue = midValue;
        }
        else if (element < midValue)
        {
            tailIndex = midIndex;
            tailValue = midValue;
        }
        else
        {
            // the middle value matches with the element,
            // we've found a place!
            headIndex = midIndex;
            break;
        }
    }
    ++headIndex;

    // make space
    tailIndex = queue->start + queue->used;
    for (size_t i = tailIndex; headIndex < i; --i)
    {
        queue->data[i % queue->capacity] = queue->data[(i - 1) % queue->capacity];
    }
    queue->data[headIndex % queue->capacity] = element;
    ++queue->used;
    priorityQueueDebug (queue);
}



uint32_t priorityQueuePop (PriorityQueue* queue)
{
    uint32_t result = queue->data[queue->start];
    --queue->used;
    queue->start = (queue->start + 1) % queue->capacity;
    printf ("popped %u\n", result);
    priorityQueueDebug (queue);
    return result;
}



// EOF //
