// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src){
        // create graph
        vector<int> adj[n];
        for(int i=0; i<m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // dist array
        vector<int> distance(n, 1e9);
        distance[src] = 0;
        queue<int> q;
        q.push(src);
      
      // Begin Breadth first search
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int &it : adj[node]) {
              
                // if distance is less than earlier visited distance,
                // we save that distance and push that node to explore
                // more shorter paths
                if(distance[it] > distance[node] + 1) {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        
        // mark distances which are impossible to reach as -1
        for(int &i : distance) {
            if(i == 1e9) {
                i = -1;
            }
        }
        return distance;
    }
};
