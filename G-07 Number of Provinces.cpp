// G-7 Number of Provinces

class Solution {
  private:
    void dfs(int node, vector<int> adjLs[], vector<int> &Vis) {
        Vis[node] = 1;
        for(int &i : adjLs[node]) {
            if(!Vis[i]) {
                dfs(i, adjLs, Vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V];
        // matrix to list
        for(int i=0; i<V; ++i) {
            for(int j=0; j<V; ++j) {
                if(adj[i][j] == 1 and i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        int provinces = 0;
        for(int i=0; i<V; ++i) {
            if(!vis[i]) {
                provinces++;
                dfs(i, adjLs, vis);
            }
        }
        
        return provinces;
    }
};
