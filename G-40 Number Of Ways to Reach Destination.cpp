/*
    Wrong Intuition: 
      We will calculate shortest distance first, then we will count how many times we reach to destination from source.
      Problem is: there might be two paths ending at one point which is then leading to destination, by doing the algorithm mentioned above,
                  we omit 1 path from those 2 paths and hence cnt reduces from 4 to 3 which is wrong answer.
     
    Correct Intuition:
      maintain a distance[] as well as ways[] array where we count ways. Src can be reached only in 1 way that is by already being there.
      For others, we mark them while peforming dijkstra's.
*/
// GFG
typedef pair<int, int> pi;
class Solution {
  public:
    int countPaths(int &n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
      
        // Graph Creation
        vector<pi> adj[n];
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        // distance and ways array
        vector<int> dist(n, 1e9), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.first;
            int distWt = top.second;
            for(auto &it : adj[node]) {
                int adjNode = it.first, wt = it.second;
                if(wt + distWt < dist[adjNode]) {
                    dist[adjNode] = wt + distWt;
                    pq.push({adjNode, dist[adjNode]});
                    ways[adjNode] = ways[node];
                }
                // if we have another shortest distance, add the shortest distance into ways[] of current node
                else if(wt + distWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        int ans = ways[n-1];
        return ans == 1e9? -1 : ans % mod;
    }
};

// LeetCode
class Solution {
public:
    typedef pair<long long, long long> pi;
    int countPaths(int &n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pi> adj[n];
        for(long long i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, 1e18), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            long long node = top.second, distWt = top.first;
            for(auto &it : adj[node]) {
                int adjNode = it.first, wt = it.second;
                if(1LL*((long long)wt + (long long)distWt) < dist[adjNode]) {
                    dist[adjNode] = 1LL*((long long)wt + (long long)distWt);
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(1LL*((long long)wt + (long long)distWt) == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
