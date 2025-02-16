auto takeSmall = [&]() -> int{
    assert(!empty(S));
    int small = *begin(S);
    S.erase(begin(S));
    return small;
};
auto takeBig = [&]() -> int{
    assert(!empty(S));
    int big = *prev(end(S));
    S.erase(prev(end(S)));
    return big;
};

map<int, int> cnt;
int m_size = 0;
auto dec = [&](int x){
    if(--cnt[x] == 0){
        cnt.erase(x);
        m_size--;
    }
};
auto inc = [&](int x){
    if(cnt[x]++ == 0)
        m_size++;
};