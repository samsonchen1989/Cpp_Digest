#include <iostream>
#include <cassert>
#include <time.h>
#include <vector>

#include "MemoryPool.tcc"
#include "StackAlloc.h"

#define ELEMS 1000000
#define REPS  50

int main()
{
    clock_t start;

    StackAlloc<int, std::allocator<int> > stackDefault;
    start = clock();
    for (int j = 0; j < REPS; j++) {
        assert(stackDefault.empty());
        for (int i = 0; i < ELEMS / 4; i++) {
            stackDefault.push(i);
            stackDefault.push(i);
            stackDefault.push(i);
            stackDefault.push(i);
        }

        for (int i = 0; i < ELEMS / 4; i++) {
            stackDefault.pop();
            stackDefault.pop();
            stackDefault.pop();
            stackDefault.pop();
        }
    }

    std::cout << "Default Allocator Time: ";
    std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

    StackAlloc<int, MemoryPool<int> > stackPool;
    start = clock();
    for (int j = 0; j < REPS; j++)
      {
        assert(stackPool.empty());
        for (int i = 0; i < ELEMS / 4; i++) {
          // Unroll to time the actual code and not the loop
          stackPool.push(i);
          stackPool.push(i);
          stackPool.push(i);
          stackPool.push(i);
        }
        for (int i = 0; i < ELEMS / 4; i++) {
          // Unroll to time the actual code and not the loop
          stackPool.pop();
          stackPool.pop();
          stackPool.pop();
          stackPool.pop();
        }
      }
      std::cout << "MemoryPool Allocator Time: ";
      std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";
}