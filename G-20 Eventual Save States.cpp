// Eventual Save States
/*
 * Casual DFS but check for nodes which are:
 * Are not part of cycle
 * don't start cycle
 * with the help of check array to mark such nodes
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
