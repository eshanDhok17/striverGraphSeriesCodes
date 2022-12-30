class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 1e5;
        queue<pair<int, int>> q;
        q.push({start, 0});
        // declaring array of size 1e5 because after doing modulo the number will lie in range of 0 - 99999
        vector<int> d(100000, 1e9);
        d[start] = 0; // standing/ starting at this number
        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto &it : arr) {
                // Multiplying the number and then adding only if the current steps
                // for the num is greater, Greedy dijkstra's/ Relaxation technique 
                int num = (it * node) % mod;
                if(steps + 1 < d[num]) {
                    d[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
