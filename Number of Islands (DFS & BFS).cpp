// Number of Islands

// DFS
class Solution {
  public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis[row][col] = true;
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int nr = row+i, nc = col+j;
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc] == '1' and !vis[nr][nc]) {
                    dfs(nr, nc, vis, grid);
                }
            }
        }
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' and vis[i][j] == false) {
                    dfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
