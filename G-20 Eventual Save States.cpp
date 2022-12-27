/* Eventual Save States
    for DFS:
        Casual DFS but check for nodes which are:
             * Not part of cycle
             * Don't start cycle
             * With the help of check array to mark such nodes
             
    for BFS:
        we know save nodes are nodes whch are terminal or which lead ONLY to terminal nodes.
        so we have to find such nodes which have indegree 0 or nodes which lead to nodes having indegree 0.
            * what we do is reverse the directions of graph
            * and push nodes having indegree 0 (we reversed graph so the node having no outdegree is now node having no indegree)
            * then we do toposort unntill it's possible an push only nodes having indegree 0.
            * not all nodes will be having indegrees 0 meaning those nodes will have connections from another nodes which dont
            * lead to terminal nodes, hence are not safe states.
*/
class Solution {
private:
    bool dfs(int &node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>> &graph) {
        vis[node] = 1;
        check[node] = 0;
        pathVis[node] = 1;
        for(int &it : graph[node]) {
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, check, graph) == true) {
                    return true;
                }
            }
            else if(pathVis[it]) {
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = size(graph);
        vector<int> vis(n, 0), pathVis(n, 0), check(n, 0), res;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, vis, pathVis, check, graph);
            }
        }
        for(int i=0; i<n; i++) {
            if(check[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// BFS - Topo Sort
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> res;
        vector<int> nadj[V];
        queue<int> q;
        // reverse graph
        for(int i=0; i<V; i++) 
        {
            for(int &it : adj[i])
            {
                nadj[it].push_back(i);
            }
        }
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++)
        {
            for(auto it : nadj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            res.push_back(node);
            for(int it : nadj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
