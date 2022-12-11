// Eventual Save States
/*
 * Casual DFS but check for nodes which are:
 * Are not part of cycle
 * don't start cycle
 * with the help of check array to mark such nodes
 */
class Solution {
  private:
    bool dfs(int &node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<int> adj[]) {
        check[node] = 0;
        vis[node] = 1;
        pathVis[node] = 1;
        for(int it : adj[node]) {
            if(vis[it] == 0) {
                if(dfs(it, vis, pathVis, check, adj) == 1) {
                    return true;
                }
            }
            else if(pathVis[it] == 1) {
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> res, pathVis(V, 0), vis(V, 0), check(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, vis, pathVis, check, adj);
            }
        }
        for(int i=0; i<V; i++) {
            if(check[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};