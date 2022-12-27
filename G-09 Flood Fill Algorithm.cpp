// G-9 Flood Fill Algorithm

class Solution {
public:
    vector<vector<int>> res;
    void bfs(int row, int col, int &val, int &newColor, vector<vector<int>>& image) {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = row+i, nc = col+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==val and res[nr][nc] != newColor) {
                        res[nr][nc] = newColor;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        // res.resize(n, vector<int>(m, 0));
        res = image;
        int val =  image[sr][sc];
        res[sr][sc] = newColor;
        bfs(sr, sc, val, newColor, image);
        return res;
    }
};
