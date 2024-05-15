function<void(int, int)> dfs2 = [&](int V, int pV){
    int sum1=0, sum2=0;
    for(auto v: edges[V]){
        if(v == pV) continue;
        dfs2(v, V);
        sum1 += dp2[v];
        sum2 += max(dp1[v], dp2[v]);
    }
    dp1[V] = mark[V] + sum1;
    dp2[V] = sum2;
};
dfs2(0, -1);
