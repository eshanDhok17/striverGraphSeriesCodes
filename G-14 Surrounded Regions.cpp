// Surrounded Regions
class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &mat, vector<vector<char>> &res) {
        int n = mat.size(), m = mat[0].size();
        vis[row][col] = true;
        res[row][col] = 'O';
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                if(abs(i) == abs(j)) continue;
                int nr = row+i, nc = col+j;
                if(nr>=0 and nr<n and nc>=0 and nc<m and mat[nr][nc] == 'O' and !vis[nr][nc]) {
                    dfs(nr, nc, vis, mat, res);
                }
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<char>> res(n, vector<char> (m, 'X'));
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0; i<n; i++) {
            if(mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, res);
                // vis[i][0] = true;
            }
            if(mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat, res);
                // vis[i][m-1] = true;
            }
        }
        for(int i=0; i<m; i++) {
            if(mat[0][i] == 'O') {
                dfs(0, i, vis, mat, res);
                // vis[0][i] = true;
            }
            if(mat[n-1][i] == 'O') {
                dfs(n-1, i, vis, mat, res);
                // vis[n-1][i] = true;
            }
        }
        mat = res;
    }
};
