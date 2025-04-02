
Memory Structure Difference (performance contrast):

-Vector: contiguous memory storage, resulting in excellent cache locality
    Constant-time random access (O(1))

    To access an element at position i, the computer calculates:
    Copymemory_address = base_address + (i * sizeof(element))


-Deque: chunked memory model (sequence of fixed-size arrays)  
Still provides O(1) random access but with slightly more overhead than vector

    Accessing an element involves:
    1 - Determining which chunk contains the element
    2 - Calculating the offset within that chunk

    The computation looks something like:
    Copychunk_index = i / chunk_size
    offset_in_chunk = i % chunk_size
    memory_address = chunks[chunk_index] + (offset_in_chunk * sizeof(element))

---

Example Walkthrough: Sorting the Array [8, 3, 7, 2, 5, 1, 4]


### Step 1: Pair and Sort Elements
- Input array: [8, 3, 7, 2, 5, 1, 4]
- Group the elements into pairs:
  - Pair 1: (8, 3)
  - Pair 2: (7, 2)
  - Pair 3: (5, 1)
  - Unpaired element: 4 (since the array size is odd)
- Sort each pair so that the smaller element comes first:
  - Pair 1 becomes (3, 8)
  - Pair 2 becomes (2, 7)
  - Pair 3 becomes (1, 5)
- Result after Step 1:
  - pairs = [(3, 8), (2, 7), (1, 5)]
  - unpairedElement = 4


### Step 2: Extract and Sort Larger Elements Recursively
- Extract the larger elements from each pair:
  - largeElements = [8, 7, 5]
- Sort the `largeElements` vector recursively:
  - After sorting: largeElements = [5, 7, 8]
- Result after Step 2:
  - pairs = [(3, 8), (2, 7), (1, 5)]
  - largeElements = [5, 7, 8] (sorted in ascending order)


### Step 3: Rebuild the Array with Sorted Larger Elements
- Start with an empty result vector: result = []

#### Step 3 Execution:
1. Start with `largeElements[0] = 5`:
   - Find the pair `(1, 5)` in `pairs`.
   - Add `1` and `5` to `result`: result = [1, 5].
   - Remove `(1, 5)` from `pairs`: pairs = [(3, 8), (2, 7)].

2. Next, `largeElements[1] = 7`:
   - Find the pair `(2, 7)` in `pairs`.
   - Add `2` and `7` to `result`: result = [1, 5, 2, 7].
   - Remove `(2, 7)` from `pairs`: pairs = [(3, 8)].

3. Finally, `largeElements[2] = 8`:
   - Find the pair `(3, 8)` in `pairs`.
   - Add `3` and `8` to `result`: result = [1, 5, 2, 7, 3, 8].
   - Remove `(3, 8)` from `pairs`: pairs = [].


### Step 4: Insert the Unpaired Element
- The unpaired element from Step 1 is `4`.
- Use binary search to find the correct position for `4` in the `result` vector:
  - `result` before insertion: [1, 5, 2, 7, 3, 8]
  - Insert `4` between `3` and `5`.
- Result after Step 4:
  - [1, 5, 2, 7, 3, 4, 8]


### Step 5: Insert Remaining Elements into the Sorted Array
- The remaining smaller elements (2 and 3) are inserted into their correct positions relative to the other elements in the result array.
- This is done using binary search.

### Final Result:
- The `result` vector now contains [1, 2, 3, 4, 5, 7, 8], which is the fully sorted array.