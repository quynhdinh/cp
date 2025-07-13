the number of subset of a array of size N: `2 ^ n`

the number of subarray of array of size N: $\frac{N\times (N + 1)}{2}$

the number of subarray of array of size N that length at most K: `(N - K + 2, N - K)`

Special binomial theorem

$(a + b)^n = \sum_{k=0}^{n} \binom{n}{k} a^{n-k} b^k$

Generating function

### Derangement

How many permutation `p` of `1,2,3,..,n` are there fit $\forall p_{i} \neq i$

Solve using dp

$D_{n} = (n - 1) \times (D_{n - 1} + D_{n - 2})$
