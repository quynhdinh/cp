/*
Source: Neal
*/
// Given a list of values,
//finds the minimum total amount of movement needed to make them all equal.
template<typename T_out, typename T_in> T_out min_equal_distance(vector<T_in> values) {
    if (values.empty())
        return 0; 
    int n = int(values.size());
    nth_element(values.begin(), values.begin() + n / 2, values.end());
    T_in median = values[n / 2];
    T_out total = 0;
 
    for (T_in x : values)
        total += abs(x - median);
 
    return total;
}
 
// Given a list of values,
// finds the minimum total amount of movement to make them contiguous (x, x + 1, x + 2, ...).
template<typename T_out, typename T_in> T_out min_contiguous_distance(vector<T_in> values) {
    if (!is_sorted(values.begin(), values.end()))
        sort(values.begin(), values.end());
 
    for (int i = 0; i < int(values.size()); i++)
        values[i] -= i;
 
    return min_equal_distance<T_out>(values);
}

/*
Application: You have a string consists of `*` and `.` size N, in one step you can swap any two of consecutive char. Find the number of steps you move every '*' consecutive to one another. 
https://codeforces.com/contest/1520/problem/E
a = []
for(int i = 0; i < N; i++){
    if(str[i] == '*') a.push_back(i);
}
answer: min_contiguous_distance(a)
/*
// harder: get K * consecutive: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
// solution(sliding window + prefix sum)
// similar: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027
// https://codeforces.com/contest/1455/problem/E
