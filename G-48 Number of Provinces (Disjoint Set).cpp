class DisjointSet {
public:
	vector<int> rank, parent;
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		for(int i = 0; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int findPar(int node) {
		if(node == parent[node]) {
			return node;
		}
        return parent[node] = findPar(parent[node]);
	}
	void unionByRank(int u, int v) {
		int ulp_u = findPar(u), ulp_v = findPar(v);
		if(ulp_u == ulp_v) return ;
		if(rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}
        else if (rank[ulp_u] > rank[ulp_v]) {
			parent[ulp_v] = ulp_u;
		}
        else {
			parent[ulp_u] = ulp_v;
			rank[ulp_v]++;
		}
	}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = size(isConnected);
        DisjointSet ds(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] == 1) {
                    // this means there is an edge b/w i and j
                    ds.unionByRank(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(ds.parent[i] == i) cnt++;
        }
        return cnt;
    }
};
