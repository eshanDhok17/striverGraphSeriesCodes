// Course Schedule I

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n, 0), adj[n];
        
        // creating adjacency list
	    for(int i=0; i<pre.size(); i++) {
	        adj[pre[i][0]].push_back(pre[i][1]);
	    }
        
        // Standard Toposort
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
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        cnt += 1;
	        for(int &it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    return cnt == n; // are number of courses equal to the toposort size?
    }
};


// Course Schedule II

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n, 0), adj[n], topo;
        // creating adjacency list
	    for(int i=0; i<pre.size(); i++) {
	        adj[pre[i][0]].push_back(pre[i][1]);
	    }
        
        // Standard Toposort
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
        n -= 1;
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
        if(size(topo) < n) return {};
        reverse(begin(topo), end(topo));
	    return topo;
    }
};