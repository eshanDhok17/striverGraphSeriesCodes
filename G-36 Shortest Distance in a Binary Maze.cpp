/*
    G-36 Shortest Distance in a Binary Maze
    Intuition: simple application of Dijkstra's Algorithm using Queue Data Structure since unity edge weights always stack up in increasing order inside queue.
*/
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int> (m, 1e9));
        distance[source.first][source.second] = 0; // Standing at source
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int r = p.second.first, c = p.second.second, dist = p.first;
            if(r == destination.first and c == destination.second)
            {
                return dist; // destination reached
                
            }
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    if(abs(i) == abs(j)) continue; // no diagonal traversal
                    int nr = r+i, nc = c+j;
                    if(nr>=0 and nc>=0 and nr<n and nc<m and grid[nr][nc] == 1 and distance[nr][nc] > dist + 1) // greedy way
                    {
                        distance[nr][nc] = dist + 1;
                        q.push({distance[nr][nc], {nr, nc}}); // relaxation technique and pushing candidate nto queue
                    }
                }
            }
        }
        return -1; // Cannot reach the destination
    }
};
