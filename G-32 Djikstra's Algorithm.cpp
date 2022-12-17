// Using Priority Queue
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


// Using Set
class Solution {
	public:
	//Function to find the shortest distance of all the vertices from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        set<pair<int, int>> st;
        st.insert({0, S});
        vector<int> d(V, 1e9);
        d[S] = 0;
        while(!st.empty()) {
            auto it = *(st.begin());
            int dist = it.first, node = it.second;
            st.erase(it);
            for(auto &x : adj[node]) {
                int adjNode = x[0], edgeWeight = x[1];
                if(dist + edgeWeight < d[adjNode]) {
                    if(d[adjNode] != 1e9) {
                        st.erase({d[adjNode], adjNode});
                    }
                    d[adjNode] = dist + edgeWeight;
                    st.insert({d[adjNode], adjNode});
                }
            }
        }
        return d;
    }
};
