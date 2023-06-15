#pragma once
#include "common.h"

/* Indices | Rel     | Depth | Size
 *    0    |    0    | 0     | 1
 *  1   2  |  0   1  | 1     | 3
 * 3 4 5 6 | 0 1 2 3 | 2     | 7
 *
 * Example
 *    10
 *  3    7
 * 1 2  3 4
 */

/*! Structure representing a sum tree.
 *  Note that any leaf with a value of zero will be unreachable.
 */
typedef struct
{
    //! The total depth of the tree, the minimum is zero.
    size_t depth;
    uint32_t* data;
}
SumTree;

/*! Prints a simple debug message showing the structure of the tree.
 */
extern void sumTreeDebug (const SumTree* tree);

/*! Gets a pointer to the leaf section of the tree data.
 *  Useful for doing lots of reads or writes as it bypasses index calculations
 *  and tree corrections.
 *  Use `sumTreeRecalculate` to correct the tree after changes.
 */
extern uint32_t* sumTreeLeafPointer (const SumTree* tree);

/*! Allocates the given tree with the given depth.
 *  Release with `sumTreeRelease` to prevent memory leaks.
 */
extern bool sumTreeAllocateLayers (SumTree* tree, size_t depth);

/*! Allocates the given tree with the given number of leaf nodes.
 *  Release with `sumTreeRelease` to prevent memory leaks.
 */
extern bool sumTreeAllocateCount (SumTree* tree, size_t count);

/*! Releases/frees the memory allocated by the tree.
 */
extern void sumTreeRelease (SumTree* tree);

/*! Sets the specified leaf node to the given value and recalculates the tree
 *  accordingly.
 */
extern void sumTreeSet (SumTree* tree, size_t index, uint32_t value);

/*! Recalculates the whole tree, useful when using `sumTreeLeafPointer` for
 *  multiple writes.
 */
extern void sumTreeRecalculate (SumTree* tree);

/*! Find the leaf index corresponding to the given query.
 *  Note that query should be less than the total sum (`tree->data[0]`) and will
 *  return -1 if not.
 */
extern size_t sumTreeFind (const SumTree* tree, uint32_t query);

// EOF //
