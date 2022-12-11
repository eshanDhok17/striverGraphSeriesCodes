/* Alien Dictionary
 * Toposort, ordering not possible when,
 * Cyclic dependancy and bigger word is before smaller word.
 */

class Solution{
  private:
    vector<int> topoSort(int n, vector<int> adj[])  {
	    vector<int> topo, indegree(n, 0);
	    for(int i=0; i<n; i++) {
	        for(int &it : adj[i]) {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<n; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        topo.push_back(node);
	        for(int &it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
	
  public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=0; i<N-1; i++) {
            string s1 = dict[i], s2 = dict[i+1];
            int size = min(s1.size(), s2.size());
            for(int j=0; j<size; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto it : topo) {
            ans += char(it + 'a');
        }
        return ans;
    }
};
