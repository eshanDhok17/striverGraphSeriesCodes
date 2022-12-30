/*
  Bellman Ford Algorithm: Complexity is (E * V)
  Works for negative Edge weights, unlike dijkstra's and increased runtime complexity from E * log(V) to E * V
  Some points:
    1. Applicable to directed graphs, if there is undirected graph, we add bi directed edges.
    2. States that relax all edges n-1 times sequentially.
    3. In n-1 Iterations we will definitely get our answer. I could come up with an explanation by myself of why so.
    4. dosent work - weighted cycles because on 6th iteration, we still reduce the distances wtih technique with relaxation, hence giving WA.
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i=0; i<V; i++) {
            if(i < V-1) {
                for(auto &it : edges) {
                    int u = it[0], v = it[1], wt = it[2];
                    if(dist[u] != 1e8 and dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
            if(i == V-1) {
                for(auto &it : edges) {
                    int u = it[0], v = it[1], wt = it[2];
                    if(dist[u] != 1e8 and dist[u] + wt < dist[v]) {
                        return {-1};
                    }
                }
            }
        }
        return dist;
    }
};
