/* Number of Distint Islands
  in this question we have to give number of distint islands, basically islands which have unique shape.
  so the tricky part for this question is to find how each island is unique. We do that through usage of geometry.
  we substract the current row by base row and base column by column to get unique islands. basically start point of island with
  every point of island and push that into a vector. if vector is duplicate that means we have only one distint island.
*/
class Solution {
  public:
  void dfs(int &row, int &col, vector<vector<int>>& grid, vector<vector<bool>>&vis,
  vector<pair<int, int>> &vec, int &br, int &bc) {
      vis[row][col] = true;
      vec.push_back({row - br, col - bc});
      int n = grid.size(), m = grid[0].size();
      for(int i=-1; i<=1; i++) {
          for(int j=-1; j<=1; j++) {
             if(abs(i) == abs(j)) continue;
             int nr = row+i, nc = col+j;
             if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1 and !vis[nr][nc]) {
                dfs(nr, nc, grid, vis, vec, br, bc);
             }
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] and grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
