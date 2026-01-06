*This project has been created as part of the 42 curriculum by <miissa>, <rmrad>.*

## Description
push_swap sorts a list of integers using two stacks and a restricted instruction set.
It outputs the operations (one per line) that sort stack a in ascending order.

## Instructions
- Build: `cd push_swap && make` (builds and links `push_swap/libft/` first)
- Run: `./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>`
- No arguments: outputs nothing and exits.

## Disorder Metric
Disorder is computed before any moves as the ratio of inverted pairs:
`mistakes / total_pairs` over all `i < j` where `a[i] > a[j]`.

## Strategies
- Simple (O(n^2)): repeated min extraction with rotations and pushes.
- Medium (O(n*sqrt(n))): chunk/window partitioning with sqrt(n) range size.
- Complex (O(n log n)): radix sort on index ranks.
- Adaptive: uses the required thresholds based on disorder:
  - disorder < 0.2: linear pass (swap/rotate) O(n), then fallback to medium if needed.
  - 0.2 <= disorder < 0.5: medium strategy.
  - disorder >= 0.5: complex strategy.
These thresholds match the subject requirements and keep the operation model within
its target complexity class.

## Bench Mode
When `--bench` is present, metrics are printed to stderr after sorting:
- disorder percent with two decimals
- selected strategy name and complexity class
- total operation count
- per-operation counts (sa sb ss pa pb ra rb rr rra rrb rrr)
No bench output is written to stdout.

## Contributors
- <miissa>: <>
- <rmrad>: <>

## Resources
- Donald Knuth, The Art of Computer Programming, Vol. 3 (Sorting and Searching).
- 42 push_swap subject and evaluation notes.
- AI usage: used for deep and clear understand the project,
  and drafting README.
