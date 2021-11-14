struct DSU{
        vector<int> par;
        vector<int> rank;
        DSU(int n){
            par.resize(n); 
            iota(begin(par), end(par), 0); 
            rank.resize(n); 
            fill(rank.begin(), rank.end(), 1); 
        }
        int find(int x){
            while(x != par[x]){
                x = par[x];
            }
            return x;
        }
        bool unite(int x, int y){
            int px = find(x);
            int py = find(y);
            if(px == py) return false;
            if(rank[px] > rank[py]) swap(px, py);
            par[px] = py;
            rank[py] += rank[px];
            return true;
        }   
    };
