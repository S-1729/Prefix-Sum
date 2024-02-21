class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        
        for(int startCol=0;startCol<m;startCol++){
            for(int j=startCol;j<m;j++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int row=0;row<n;row++){
                    sum+= matrix[row][j] - (startCol>0?matrix[row][startCol-1]:0);
                    ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};

/*
	Given a matrix and a target, return the number of non-empty submatrices that sum to target.
	A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
	Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
	
	Example 1:
	Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
	Output: 4
	Explanation: The four 1x1 submatrices that only contain 0.
	
	Example 2:
	Input: matrix = [[1,-1],[-1,1]], target = 0
	Output: 5
	Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

	T.C : O(n*m*m)
	S.C : O(n)
*/
