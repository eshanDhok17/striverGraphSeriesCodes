/* 
 * Detect a cycle in undirected graph
*/

// BFS
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int &node, int par, vector<int> adj[], vector<bool> &vis) {
        queue<pair<int, int>> q;
        q.push({node, par});
        vis[node] = true;
        while(!q.empty()) {
            int node = q.front().first, par = q.front().second;
            q.pop();
            for(int& it : adj[node]) {
                if(vis[it] == false) {
                    q.push({it, node});
                    vis[it] = true;
                }
                else if(it != par) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(vis[i] == false) {
                if(bfs(i, -1, adj, vis) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

//  DFS
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
