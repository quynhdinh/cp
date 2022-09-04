// get the next mask with the same number of bits
int next_popcount(int n) {
    int c = (n & -n), r = n + c;
    return (((r ^ n) >> 2) / c) | r;
}