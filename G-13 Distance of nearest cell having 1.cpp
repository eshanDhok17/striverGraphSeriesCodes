// G-13 Distance of nearest cell having 1
class Solution {
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid) {
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> res(n, vector<int>(m, 0));
	    vector<vector<bool>> vis(n, vector<bool>(m, false));
	    queue<pair<pair<int, int>, int>> q;
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if(grid[i][j] == 1) {
	                q.push({{i, j}, 0});
	                vis[i][j] = true;
	            }
	        }
	    }
	    
	    while(!q.empty()) {
	        int row = q.front().first.first, col = q.front().first.second,
	            dist = q.front().second;
	            q.pop();
	            res[row][col] = dist;
	        for(int i=-1; i<=1; i++) {
	            for(int j=-1; j<=1; j++) {
	                if(abs(i) == abs(j)) continue;
	                int nr = row + i, nc = col + j;
	                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc]) {
	                    q.push({{nr, nc}, dist+1});
	                    vis[nr][nc] = true;
	                }
	            }
	        }
	    }
	    return res;
	}
};