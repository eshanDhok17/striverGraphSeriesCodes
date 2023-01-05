// Leetcode -  Number of Operations to Make Network Connected - DSU
class ds {
public:
    vector<int> par, rank;
    // constructor
    ds(int &n) {
        par.resize(n+1, 0);
        rank.resize(n+1);
        for(int i=0; i<n; i++)
            par[i] = i, rank[i] = 1;
    }
    int findPar(int &node) {
        if(node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }
    void UbyRank(int &u, int &v) {
        int ulp_u = findPar(u), ulp_v = findPar(v);
        if(ulp_u == ulp_v) return ;
        else if(rank[ulp_u] < rank[ulp_v]) {
            par[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            par[ulp_v] = ulp_u;
        }
        else {
            par[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        ds d(n);
        int extraCable = 0;
        for(auto&it : connections) {
            int u = it[0], v = it[1];
            if(d.findPar(u) == d.findPar(v)) extraCable++;
            else d.UbyRank(u, v);
        }
        int computerGroups = 0;
        for(int i=0; i<n; i++) {
            if(d.par[i] == i) computerGroups++;
        }
    // for mst we want n-1 edges for n nodes to make all computers connected
        int res = computerGroups - 1;
        if(extraCable >= res) {
            return res;
        }
        return -1;
    }
};
