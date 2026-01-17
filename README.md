*This project has been created as part of the 42 curriculum by miissa, rmrad.*

# push_swap

## Description
**push_swap** is a program that sorts a list of integers using **two stacks** and a **restricted set of operations**. The goal is to sort stack `a` in ascending order while minimizing the number of operations. The program outputs the required operations (one per line) to stdout. This project emphasizes **algorithmic thinking**, **data structure manipulation**, and **optimization** under strict constraints.

## Instructions

### Build
```bash
cd push_swap
make
```

### Run
```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```

- `<numbers...>`: one or more integers (space-separated, can be quoted).  
- Flags:  
  - `--simple` → use the simple O(n²) strategy.  
  - `--medium` → use medium O(n*√n) strategy.  
  - `--complex` → use complex O(n log n) strategy.  
  - `--adaptive` (default) → automatically selects the best strategy based on the input’s disorder.  
  - `--bench` → prints sorting statistics to `stderr` instead of `stdout`.  

**Note:** If no arguments are provided, the program outputs nothing and exits.

## Disorder Metric
Disorder is calculated **before any moves** as:  
\[
\text{disorder} = \frac{\text{number of inverted pairs}}{\text{total pairs}}
\]  
Where an **inverted pair** is any `(i, j)` such that `i < j` and `a[i] > a[j]`. This value, between `0.0` (sorted) and `1.0` (completely reversed), is used by the **adaptive strategy**.

## Sorting Strategies

### Simple (O(n²))
- Repeatedly finds the **minimum element**, pushes it to the auxiliary stack, and rotates as needed.  
- Best suited for **small lists** (≤ 5 elements).

### Medium (O(n·√n))
- Divides the list into **chunks** of size roughly √n.  
- Pushes chunks to stack `b`, then reinserts them in order.  
- Efficient for **medium-sized lists**.

### Complex (O(n log n))
- Uses **radix sort** on element **indices**, not raw values.  
- Works efficiently for **large lists**.

### Adaptive
- Chooses the strategy automatically based on the **disorder**:  
  - `disorder < 0.2` → linear pass with swaps/rotations, fallback to medium if needed.  
  - `0.2 ≤ disorder < 0.5` → medium strategy.  
  - `disorder ≥ 0.5` → complex strategy.  
This ensures the **number of operations** stays minimal while matching the input characteristics.

## Bench Mode
When `--bench` is used, **metrics are printed to `stderr`** after sorting:  
- Disorder as a **percentage with two decimals**  
- Selected strategy name and complexity class  
- Total number of operations  
- Count of each operation: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`  

> No sorting operations are printed to `stdout` when bench mode is active.

## Technical Choices & Algorithms
1. **Stacks**:  
   - `t_stack` implemented as a **doubly linked list** for O(1) push/pop at both ends.  
   - Each node stores both the **value** and the **index** in the sorted array.  

2. **Indexing**:  
   - Original values are mapped to **indices** in the sorted array.  
   - This simplifies complex strategies (like radix sort) to work in **O(n log n)**.  

3. **Disorder Calculation**:  
   - Measures **inversions** between all element pairs.  
   - Used for **adaptive strategy selection**.  

4. **Sorting Algorithms**:  
   - **Simple**: linear min extraction and push.  
   - **Medium**: chunk partitioning (based on √n) for efficient partial sorting.  
   - **Complex**: radix sort on **index ranks**, achieving O(n log n).  

5. **Memory Management**:  
   - Dynamic arrays used during parsing.  
   - Full cleanup in case of errors to prevent memory leaks.

## Resources 
- 42 Push_swap subject 
- AI assistance was used to **explain the used algorithms how they work**, and **improve README content**.

## Contributors
- **miissa**: project implementation and project structure and debugging
- **rmrad**: project implementation and debugging
