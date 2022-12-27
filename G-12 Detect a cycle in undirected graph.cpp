/*
 * Detect a cycle in undirected graph
 * DFS
*/
class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &vis) {
        vis[node] = true;
        for(int &next : adj[node]) {
            if(!vis[next]) {
                if(dfs(next, node, adj, vis)) return true;
            }
            else if(next != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        for(int i=0; i<V; ++i) {
            if(!vis[i])
                if(dfs(i, -1, adj, vis)) return true;
        }
        return false;
    }
};