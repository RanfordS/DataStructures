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

typedef struct
{
    size_t depth;
    size_t used;
    uint32_t* data;
}
SumTree;

extern bool sumTreeAllocate (SumTree* tree, size_t depth);
extern void sumTreeRelease (SumTree* tree);
extern void sumTreeSet (SumTree* tree, size_t index, uint32_t value);
extern void sumTreeInsert (SumTree* tree, uint32_t value);
extern void sumTreeRemove (SumTree* tree, size_t index);
extern size_t sumTreeFind (SumTree* tree, uint32_t query);

// EOF //
