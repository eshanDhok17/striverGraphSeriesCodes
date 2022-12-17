// BiPartite Graph

// BFS
class Solution {
public:
    bool bfs(int &node, int parent, vector<int> &color, vector<int> adj[]) {
        queue<int> q;
        q.push(node);
        int fg = 0;
        color[node] = fg;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int it : adj[node]) {
                if(color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) {
	            if(bfs(i, -1, color, adj) == false) {
                  return false;
              }
	        }
	    }
	    return true;
	}
};

// DFS
class Solution {
public:
    bool dfs(int &node, bool col, vector<int> &color, vector<int> adj[]) {
        color[node] = col;
        for(int it : adj[node]) {
            if(color[it] == -1) {
                if(!dfs(it, !col, color, adj)) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) return false;
	        }
	    }
	    return true;
	}
};
