class Solution {
public:
    // 17:45 time BFS
    void bfs(int row, int col, vector<int> &temp, vector<vector<bool>> &vis, vector<vector<int>> &land) {
        int last_vis_x = row, last_vis_y = col, n = land.size(), m = land[0].size(); 
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            last_vis_x = row, last_vis_y = col;
            q.pop();
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = row+i, nc = col+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and land[nr][nc] == 1) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        temp.push_back(last_vis_x);
        temp.push_back(last_vis_y);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<int>> res;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(land[i][j] == 1 and !vis[i][j]) {
                    vis[i][j] = true;
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    bfs(i, j, temp, vis, land);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
