# Luxury Square Hotel

**Time Limit:** 2 seconds  
**Memory Limit:** 512 MB  

## Problem Statement

You are the manager of a renowned construction company. You have to secure permits for a new square-shaped luxury hotel of height exactly \(k\). The kingdom is divided into \(t\) independent cities. In each city, the land is an \(n \times m\) grid of individual plots. On plot \((i, j)\), the local authority issues a building permit up to height \(h_{i,j}\); acquiring that permit costs exactly \(h_{i,j}\) coins.

Your hotel requires every plot in its square footprint to allow at least height \(k\). Moreover, your total budget for permits in each city is \(C\) coins.

Your task for each city is to choose a square block of plots of maximum possible side length \(s\) such that:

1. **Height constraint:**  
   \[
     \forall\;(i,j)\ \text{in the square},\quad h_{i,j} \ge k.
   \]

2. **Budget constraint:**  
   \[
     \sum_{(i,j)\,\in\,\text{square}} h_{i,j} \;\le\; C.
   \]

Among all such maximum-size squares, you also want to know:

- how many there are, and the minimum total cost among them.

---

### Input

The first line contains a single integer \(t\) \(\bigl(1 \le t \le 10\bigr)\), the number of cities (test cases).  
Each test case begins with a line containing four integers

\[
  n \quad m \quad k \quad C
\]

- \(n\), \(m\) (\(1 \le n, m \le 1000\)): the number of rows and columns of the grid,  
- \(k\) (\(1 \le k \le 10^6\)): the required hotel height,  
- \(C\) (\(1 \le C \le 10^{15}\)): your budget.

Then follow \(n\) lines, each with \(m\) integers

\[
  h_{i,1}\; h_{i,2}\;\dots\;h_{i,m}
  \quad\bigl(1 \le h_{i,j} \le 10^6\bigr),
\]

the permit heights (and costs) of the plots.

---

### Output

For each test case, output a single line with three integers:

\[
  s \quad \text{count} \quad \text{min\_cost}
\]

- \(s\) is the maximum side length of the square,  
- \(\text{count}\) is the number of such squares of size \(s\),  
- \(\text{min\_cost}\) is the minimum total permit cost among them.

If no square can be built, output



### Explanation of Example

Test Case 1:
Grid size: 4×5, Required height 𝑘=3, Budget 𝐶=50
2 3 4 3 2  
4 5 3 3 3  
3 3 3 4 1  
5 5 5 5 5

We want the largest square where: Every plot has height ≥ 3
The total cost (sum of heights in the square) is ≤ 50

The largest possible square size that meets the height requirement is 3×3.

There are 3 such squares of size 3×3 where all heights are at least 3 and the cost is within budget:
Top-left at (1,2)
Top-left at (2,1)
Top-left at (2,2)
Among them, the cheapest has a total permit cost of 31.
Hence, output: 3 3 31

Test Case 2:
Grid size: 3×3, Required height 𝑘=10, Budget 𝐶=20
5 5 5  
5 2 5  
5 5 5  

No plot in the entire grid has height ≥ 10. So, it’s impossible to place even a 1×1 square.
Hence, output: 0 0 0

