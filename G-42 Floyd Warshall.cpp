/*
    Floyd Warshall Algorithm, Also Known as Multi Source Shortest Path Algorithm
    Detects negative cycles and works on negative weights
    Intuition:
    How to detect -ve cycle? -> Distance from node to node is always 0, if it becomes < 0 we can say -ve cycle.
    Calculate Shortest Path Ultimate Matrix
    Explain this before explaining this algorithm
    1. why will dijkstra will not work?
    2. How to deal with -Ve cycles?
    3. Then introduce -> here comes this Floyd Warshall algo...
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == -1) {
	                matrix[i][j] = 1e9;
	            }
	            if(i == j) {
	                matrix[i][j] = 0;
	            }
	        }
	    }
	    for(int k=0; k<n; k++) {
	        for(int i=0; i<n; i++) {
	            for(int j=0; j<n; j++) {
	                matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
	            }
	        }
	    }
		
	    // To detect cycle
            for(int i=0; i<n; i++) {
	        if(matrix[i][i] < 0) {
	            cout << "NEGATIVE CYCLE" << endl;
                    return ;
	        }
	    }
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == 1e9) {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};
