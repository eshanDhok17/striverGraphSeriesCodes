// Detect Cycle in Graph (DAG)

// DFS
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

// BFS

class Solution {
  public:
    // Function to detect cycle in a directed graph
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> indegree(n, 0);
	    for(int i=0; i<n; i++) {
	        for(int &it : adj[i]) {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<n; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        cnt += 1;
	        for(int &it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    return (cnt == n)? false : true;
    }
};