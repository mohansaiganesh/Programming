/*
	1. Matrix size mxn.
	2. All are non negative numbers [0,inf).
	3. source = top left, destination = bottom-right.{sum of all numbers in the path should be minimum}.
	4. move only either down or right.

*/


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
	int minPathSum(vector<vector<int>> grid){
		int m = grid.size();
		int n = grid[0].size();
	
		//iterate the 1st row and update values
		for(int col=1; col<n; col++){
			grid[0][col] += grid[0][col-1];	
		}		

		//iterate the first column and update the values
		for(int row=1; row<m; row++){
			grid[row][0] += grid[row-1][0];
		}

		//iterate from (1,1) to (m-1, n-1)
		for(int row=1; row<m; row++){
			for(int col=1; col<n; col++){
				grid[row][col] += min(grid[row][col-1], grid[row-1][col]);
			}
	
		}
		

		return grid[m-1][n-1];
	}

};



int main(){
	Solution sol;

	vector<vector<int>> grid1 = {{1,3,1}, {1,5,1}, {4,2,1}};
	cout<<"The minimum path sum for grid1 is: "<<sol.minPathSum(grid1)<<"\n";

	
	vector<vector<int>> grid2 = {{1,2,3}, {4,5,6}};
	cout<<"The minimum path sum for grid2 is: "<<sol.minPathSum(grid2)<<"\n";

	return 0;
}