// G-10 Rotten Oranges

class Solution {
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int minTime = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        
        while(!q.empty()) {
            int row = q.front().first.first, col = q.front().first.second,
                time = q.front().second;
            minTime = max(minTime, time);
            q.pop();
            for(int i=-1; i<=1; i++)
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = row + i, nc = col + j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.push({{nr, nc}, time + 1});
                    }
                }
        }
        
        for(int i=0;i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] and grid[i][j] == 1) return -1;
         
        return minTime;
    }
};