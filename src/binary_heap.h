#pragma once
#include "common.h"

/* Indices | Rel     | Depth | Size
 *    0    |    0    | 0     | 1
 *  1   2  |  0   1  | 1     | 3
 * 3 4 5 6 | 0 1 2 3 | 2     | 7
 *
 * Example
 *    1
 *  2   5
 * 3 4 6 7
 */

/*! Structure representing a binary heap.
 */
typedef struct
{
    //! The total depth of the tree, the minimum is zero.
    size_t size;
    //! Number of elements used.
    size_t used;
    uint32_t* data;
}
BinaryHeap;


extern void binaryHeapDebug (const BinaryHeap* heap);
extern bool binaryHeapAllocateCount (BinaryHeap* heap, size_t count);
extern void binaryHeapRelease (BinaryHeap* heap);
extern void binaryHeapBubbleUp (BinaryHeap* heap, size_t index, uint32_t value);
extern void binaryHeapBubbleDown (BinaryHeap* heap, size_t index, uint32_t value);
extern void binaryHeapInsert (BinaryHeap* heap, uint32_t element);
extern uint32_t binaryHeapPop (BinaryHeap* heap);
