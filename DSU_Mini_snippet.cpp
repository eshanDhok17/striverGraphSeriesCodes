class Dsu {
public:
    vector<int> par, rank;
    Dsu(int n) {
        par.resize(n+1), rank.resize(n+1, 0);
        for(int i=0; i<n; i++) par[i] = i, rank[i] = 1;
    }
    void union(int u, int v) {
        int ultp_v = find(v), ultp_u = find(u);
        if(ultp_v == ultp_u) return ;
        if(rank[ultp_v] < rank[ultp_u]) par[ultp_v] = ultp_u;
        else if(rank[ultp_v] > rank[ultp_u]) par[ultp_u] = ultp_v;
        else par[ultp_u] = ultp_v, rank[ultp_v]++;
    }
    int find(int node) {
        if(node == par[node]) return node;
        return par[node] = find([par[node]]);
    }
};
