class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // create graph
        vector<pair<int, int>> adj[n+1];
        for(int i=0; i<m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        // distance array and parent array
        vector<int> dist(n+1, 1e9), par(n+1);
        for(int i=0; i<n; ++i) par[i] = i;
        
        // standard djikstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dist[1] = 0;
        while(!pq.empty()) {
            int dis = pq.top().first, node = pq.top().second;
            pq.pop();
            for(pair<int, int> &it : adj[node]) {
                int adjNode = it.first, wt = it.second;
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis+wt;
                    pq.push({dist[adjNode], adjNode});
                    par[adjNode] = node; // mark parent node to child node
                }
            }
        }
        if(dist[n] == 1e9) return {-1}; // not possible to reach the path
        int node = n;
        vector<int> path;
        while(par[node] != node) { // While we aren't back to source node
            path.push_back(node);
            node = par[node];
        }
        path.push_back(1); // include source node in path
        reverse(path.begin(), path.end());
        return path;
    }
};
