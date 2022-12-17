/* Topological Sort
 * linear ordering of pairs u and v where if there is edge from u to v then u appears before u in that ordering.
 */

// DFS
class Solution {
  private:
      void dfs(int &node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
          vis[node] = 1;
          for(int it : adj[node]) {
              if(!vis[it]) {
                  dfs(it, vis, adj, st);
              }
          }
          st.push(node);
          return ;
      }
  
	public:
      vector<int> topoSort(int n, vector<int> adj[])  {
          vector<int> res, vis(n, 0);
          stack<int> st;
          for(int i=0; i<n; i++) {
              if(!vis[i]) {
                  dfs(i, vis, adj, st);
              }
          }
          while(!st.empty()) {
              res.push_back(st.top());
              st.pop();
          }
          return res;
      }
};

// BFS - Kahn's Algorithm

class Solution {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[])  {
	    vector<int> topo, indegree(n, 0);
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
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        topo.push_back(node);
	        for(int &it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
};
