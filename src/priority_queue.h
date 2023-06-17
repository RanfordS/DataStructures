#pragma once
#include "common.h"

/*! Structure representing a priority queue.
 *  Implemented with a rolling buffer.
 */
typedef struct
{
    size_t capacity;
    size_t used;
    size_t start;
    uint32_t* data;
}
PriorityQueue;

extern void priorityQueueDebug (PriorityQueue* queue);
extern bool priorityQueueAllocateCount (PriorityQueue* queue, size_t count);
extern void priorityQueueRelease (PriorityQueue* queue);
extern void priorityQueueUnroll (const PriorityQueue* queue, uint32_t* output);
extern void priorityQueueInsert (PriorityQueue* queue, uint32_t element);
extern uint32_t priorityQueuePop (PriorityQueue* queue);

// EOF //
