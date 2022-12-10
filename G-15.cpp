// Number of Enclaves
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int enclaves = 0;
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1) {
                vis[i][0] = true;
                grid[i][0] = 0;
                q.push({i, 0});
            }
            if(grid[i][m-1] == 1) {
                grid[i][m-1] = 0;
                vis[i][m-1] = true;
                q.push({i, m-1});
            }
        }
        for(int i=0; i<m; i++) {
            if(grid[0][i] == 1) {
                grid[0][i] = 0;
                vis[0][i] = true;
                q.push({0, i});
            }
            if(grid[n-1][i] == 1) {
                grid[n-1][i] = 0;
                vis[n-1][i] = true;
                q.push({n-1, i});
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = row+i, nc = col+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc] == 1 and !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        grid[nr][nc] = 0;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1) enclaves++;
        
        return enclaves;
    }
};