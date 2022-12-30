/*
    Prim's Algorithm
    helps us find the sum of edge weights of MST.
    -> We need:
        1. Graph/ AdjList/ AdjMatrix
    -> We use:
        1. Priority Queue (min heap)
        2. Visited Array
*/

class Solution {
    typedef pair<int,int> pi;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int sum = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int>vis(V, 0);
        pq.push({0, 0}); // if they ask MST, add parent i.e. {wt, {node, par}}
        while(pq.size() > 0) {
            auto it = pq.top(); pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto &it : adj[node]) {
                int adjNode = it[0], edW = it[1];
                if(!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};
