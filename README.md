*This project has been created as part of the 42 curriculum by <login1>, <login2>.*

## Description
push_swap sorts a list of integers using two stacks and a restricted instruction set.
It outputs the operations that sort stack a in ascending order.

## Instructions
- Build: `make`
- Run: `./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>`
- Checker (bonus): `make bonus` then `./checker <numbers...>`

## Algorithms
- Simple (O(n^2)): selection-style min extraction with rotations and pushes.
- Medium (O(n*sqrt(n))): chunk-based windowing with sqrt(n) ranges; push to b, then pull max back to a.
- Complex (O(n log n)): radix sort on index ranks.
- Adaptive: compute disorder (inversion ratio) before any moves and select:
  - disorder < 0.2: adaptive-low linear pass with swaps/rotations (O(n));
    if still unsorted, it falls back to the medium strategy for correctness.
  - 0.2 <= disorder < 0.5: medium algorithm (O(n*sqrt(n))).
  - disorder >= 0.5: complex algorithm (O(n log n)).
These thresholds follow the subject requirement and keep the operation model within the target classes.

## Bench Mode
When `--bench` is set, metrics are printed to stderr after sorting:
disorder percent (two decimals), chosen strategy + complexity, total operations,
and per-operation counts.

## Contributors
- <login1>: <contribution summary>
- <login2>: <contribution summary>

## Resources
- Donald Knuth, The Art of Computer Programming, Vol. 3 (Sorting and Searching).
- 42 push_swap subject and evaluation notes.
- AI usage: used for edge-case review, refactoring to 42 Norm (25-line limit),
  and drafting README/bench output descriptions.
