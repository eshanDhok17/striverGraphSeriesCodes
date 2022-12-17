typedef pair<int, int> pi;
class Solution {
	public:
	//Function to find the shortest distance of all the vertices from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
      // Priority queue to get minimum distance everytime on top  
      priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()) {
            int dis = pq.top().first, node = pq.top().second;
            pq.pop();
            for(vector<int> &it : adj[node]) {
                int adjNode = it[0], edgeWeight = it[1];
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
