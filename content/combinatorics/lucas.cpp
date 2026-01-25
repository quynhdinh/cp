// Computes C(n, k) % p using Lucas Theorem, where p is a prime number
int C[5][5];
int c(int n, int k, int p)
{
  for (int i = 0; i < p; i++)
    for (int j = 0; j <= i; j++)
      C[i][j] = j ? (C[i - 1][j - 1] + C[i - 1][j]) % p : 1;
  int res = 1;
  while (k > 0)
  {
    int nn = n % p;
    n /= p;
    int kk = k % p;
    k /= p;
    res = res * C[nn][kk] % p;
  }
  return res;
}