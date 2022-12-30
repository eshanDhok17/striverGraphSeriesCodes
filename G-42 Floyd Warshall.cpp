/*
    Floyd Warshall Algorithm, Also Known as Multi Source Shortest Path Algorithm
    Detects negative cycles and works on negative weights
    Intuition:
    How to detect -ve cycle? -> Distance from node to node is always 0, if it becomes < 0 we can say -ve cycle.
    Calculate Shortest Path Ultimate Matrix
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
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == 1e9) {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};
