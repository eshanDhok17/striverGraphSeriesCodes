// Drected Cycle Detection using DFS

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int &node, bool vis[], bool pathVis[], vector<int> adj[]) {
        vis[node] = true;
        pathVis[node] = true;
        
        for(int &otherNodes : adj[node]) {
            if(!vis[otherNodes]) {
                if(dfs(otherNodes, vis, pathVis, adj) == true)
                    return true;
            }
            else if(pathVis[otherNodes]) {
                return true;
            }
        }
        pathVis[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        bool vis[V] = {0};
        bool pathVis[V] = {0};
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
