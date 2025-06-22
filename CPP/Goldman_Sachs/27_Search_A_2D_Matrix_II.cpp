/*

	1. Given a matrix of size mxn.
	2. each row is sorted in ascending order from left to right.
	3. each column is sorted in ascending order from top to bottom.
	4. search for an target element and return true if found, else return false.
	

*/

#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target){
		bool found = false;

		//inorder to search elment efficiently, we have to eliminate the unnecessary portions at each step
		
		int m = matrix.size();
		int n = matrix[0].size();
		
		//start at top right corner
		int row = 0;
		int col = n-1;

		
		while(row<m && col>=0){

			if(target == matrix[row][col]){
				found = true;
				break;
			}
			else if(target < matrix[row][col]){ //eliminate column
				col--;
			}
			else{ //eliminate row
				row++;
			}

		}
		
		
		

		return found;
	}	

};


int main(){
	Solution sol;
	vector<vector<int>> matrix1 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	cout<<"The element 5 is present in the matrix [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]: "<<sol.searchMatrix(matrix1, 5)<<"\n";
	
	return 0;
}

