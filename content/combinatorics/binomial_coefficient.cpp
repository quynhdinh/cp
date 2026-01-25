// Computes the binomial coefficient "a choose b"
  long long choose(int a, int b) {
    if (b < 0 || b > a) return 0;
    if (b > a - b) b = a - b;
    long long res = 1;
    for (int i = 1; i <= b; i++)
      res = res * (a - i + 1) / i;
    return res;
  }