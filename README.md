# Push Swap

## Overview

`push_swap` is a project that involves sorting a stack of integers using a limited set of operations. The goal is to print out the -lowest amount of- steps needed to sort the list. This project is part of the curriculum at 42 coding school.

## Algorithm

The `push_swap` project uses a combination of sorting algorithms to achieve the goal of sorting the stack efficiently. The main algorithm for longer lists involves the following steps:

1. **Initialization**: The stacks `a` and `b` are initialized. Stack `a` contains the integers to be sorted, and stack `b` is initially empty.

2. **Array Conversion and Sorting**: The stack `a` is converted to an array and sorted. This pre-sorted array is used to determine the chunk boundaries.

3. **Chunk Division**: The stack is divided into chunks based on the sorted array. The number of chunks is determined dynamically using the Longest Increasing Subsequence (LIS) algorithm. The LIS algorithm helps in identifying the longest increasing subsequence in the stack, which can be used to determine the optimal chunk sizes for sorting.

4. **Chunk Sorting**: Each chunk is sorted individually. The elements of each chunk are pushed to stack `b` using a smart rotation strategy to minimize the number of operations. The smart rotation strategy involves rotating the stack to bring the target element to the top before pushing it to stack `b`.

5. **Handling Remaining Elements**: After sorting the chunks, the remaining elements in stack `a` are handled. The smallest elements are pushed to stack `b` using the smart rotation strategy.

6. **Final Sorting**: The elements in stack `b` are sorted and pushed back to stack `a`. The largest elements are pushed back first, using a smart rotation strategy to bring the largest element to the top of stack `b` before pushing it to stack `a`.

## Usage

To compile and run the project, use the following commands:

```sh
make
./push_swap [list-of-unsorted-ints]
```

