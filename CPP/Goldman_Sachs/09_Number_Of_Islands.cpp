/*
	1. Given mxn grid, '1' represents land and '0' represents water
	2. return the number of islands.

*/

#include<iostream>
#include<vector>


using namespace std;

class Solution{
public:
	//marks the island to '0'
	void dfs(int i, int j, vector<vector<char>>& grid, int& m, int& n, vector<int>& row_dir, vector<int>& col_dir){		

		grid[i][j] = '0';

		for(int k=0; k<4; k++){
			int new_row = i+row_dir[k];
			int new_col = j+col_dir[k];
			
			if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && grid[new_row][new_col] == '1')
				dfs(new_row, new_col, grid, m, n, row_dir, col_dir);
			
		}
		
		
	}

	int numIslands(vector<vector<char>>& grid){
		int count = 0;
		int m = grid.size(), n = grid[0].size();

		vector<int> row_dir = {-1,0,1,0};
		vector<int> col_dir = {0,1,0,-1};

		//copy of the grid
		vector<vector<char>> gridCopy = grid;
		
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(gridCopy[i][j]=='1'){
					count++;
					dfs(i, j, gridCopy, m, n, row_dir, col_dir);
				}
			}
		}
		
		return count;
	}

};


int main(){
	Solution sol;
	
	vector<vector<char>> grid1 = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
	cout<<"The number of islands for grid1 is: "<<sol.numIslands(grid1)<<"\n";

	vector<vector<char>> grid2 = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
	cout<<"The number of islands for grid2 is: "<<sol.numIslands(grid2)<<"\n";

	return 0;
}