/*
Source: Neal
*/
// Compresses the values in arr to be in the range [0, n)
// Usage: <int>compress_array(a);
template<typename T>
vector<int> compress_array(const vector<T> &arr) {
    int n = int(arr.size());
    vector<T> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    vector<int> compressed(n);

    for (int i = 0; i < n; i++)
        compressed[i] = int(lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin());

    return compressed;
}