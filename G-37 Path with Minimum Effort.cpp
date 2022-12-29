/*
    Intuition:
        Apply standard dijkstra's and only enter into priority queue when we have maximal
        of all difference while updating it into the distance array.
*/
typedef pair<int, pair<int, int>> pi;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = size(heights), m = size(heights[0]);
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, {0, 0}});
        while(pq.size() > 0) {
            auto it = pq.top(); 
            pq.pop();
            int r = it.second.first, c = it.second.second;
            int absDiff = it.first;
            if(r == n-1 and c == m-1) return absDiff;
            for(int i=-1; i<=1; ++i) {
                for(int j=-1; j<=1; ++j) {
                    if(abs(i) == abs(j)) continue;
                    int nr = r+i, nc = c+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m) {
                    // question states to take maximum of all difference
                        int newDiff = max(absDiff, abs(heights[nr][nc] - heights[r][c]));
                        if(newDiff < dist[nr][nc]) { // greedy dijkstra's
                            dist[nr][nc] = newDiff;
                            pq.push({newDiff, {nr, nc}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
