# Editorial — Luxury Square Hotel  
*by Harshil Goel, May 2025*

This problem can be broken down into three major parts:

1. Determine whether there exists a square of side $s$ with all heights $\ge k$.  
2. Calculate the cost of any given $s\times s$ square efficiently.  
3. Find the largest possible square that meets the budget constraint $\le C$.  

---

## 1. Maximal Square Dynamic Programming (Height Constraint)

We first identify the squares that satisfy the height requirement. Define a DP array `dp[i][j]`, where `dp[i][j]` stores the size of the largest square whose bottom-right corner is at $(i,j)$ and every cell in that square has height $\ge k$. We compute:

$$
\mathrm{dp}[i][j] = 
\begin{cases}
0, & \text{if } h[i][j] < k,\\
1 + \min\bigl(\mathrm{dp}[i-1][j],\,\mathrm{dp}[i][j-1],\,\mathrm{dp}[i-1][j-1]\bigr), & \text{otherwise.}
\end{cases}
$$

Each `dp[i][j]` gives the maximal side length of a height-compliant square ending at cell $(i,j)$.

**Time Complexity:** $O(n \cdot m)$

---

## 2. Prefix Sums (Cost Constraint)

To compute the cost of any square in $O(1)$, build a 2D prefix-sum array `sumH[i][j]`:

$$
\mathrm{sumH}[i][j]
= \sum_{x=1}^{i} \sum_{y=1}^{j} h[x][y].
$$

Then the cost of the square from $(x_1,y_1)$ to $(x_2,y_2)$ is

$$
\mathrm{cost}
= \mathrm{sumH}[x_2][y_2]
- \mathrm{sumH}[x_1-1][y_2]
- \mathrm{sumH}[x_2][y_1-1]
+ \mathrm{sumH}[x_1-1][y_1-1].
$$

**Time Complexity:**  
- Preprocessing: $O(n\cdot m)$  
- Each cost query: $O(1)$

---

## 3. Binary Search for Optimal Square Size

We binary-search the answer $s$ in the range $[1, \min(n,m)]$. For each candidate $s$:

1. Traverse all $(i,j)$ with `dp[i][j] ≥ s`.  
2. For each, compute its cost via the prefix sums.  
3. If **any** has cost $\le C$, then $s$ is feasible; otherwise it’s too large.

After finding the maximum feasible $s$, do one more pass to:

- **Count** all $s\times s$ squares with cost $\le C$.  
- **Track** the minimum cost among them.

**Total Time Complexity:** $O\bigl(n\cdot m\cdot \log\min(n,m)\bigr)$

---