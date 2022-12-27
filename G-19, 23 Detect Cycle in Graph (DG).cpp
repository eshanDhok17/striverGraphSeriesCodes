// Detect Cycle in Graph (DG)
/*
	for DFS:
		we can do DFS but there arises a problem in a directed graph.
		if we have such a graph where there are some nodes which are earlier visited,
		but are not in path of a new dfs call, our algorithm for undirected graph tends to return true
		but since the new dfs call has not visited that node in it's current path then even if it's visited,
		we cant say that we have a cycle whereas we can say that there exists a cycle if we have visited nodes and
		they are in path as well in that dfs call.
		
		3 -> 4 -> 7 -> 5 -> 8
		| -> 7 ________|
		
		
	for BFS:
		to find if there exists cycle in directed graph, we use topological sort or kahn's Algorithm.
		topological sort has a property where it states that topological sort can be applied only to DAG.
		so to find cycle in directed graph, if we do topological sort for a particular graph, if the ordereing 
		is complete; if the nodes ordered are equal to the total nodes then it is acyclic else cyclic.
*/
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
