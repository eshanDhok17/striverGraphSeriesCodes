// Topological sort
/*
 * linear ordering of pairs u and v where if there is edge from u to v then u appears before u in that ordering.
 */
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