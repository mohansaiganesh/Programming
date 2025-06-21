/*
	1. Given mxn matrix.
	2. each row is sorted in non decreasing order.
	3. and 1st element of each row is greater than last element of previous row.
	4. It means 2d matrix can be flattened.
	5. Search for a target and return true if present, else return false.

*/


#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target){
		bool found = false;
		int m = matrix.size();
		int n = matrix[0].size();

		int low = 0, high = m*n-1;
	
		int i=0, j=0, mid=0, curr=0;

		while(low<=high){
			mid = (low+high)/2;
			i = mid/n;
			j = mid%n;

			curr = matrix[i][j];
			
			if(curr == target){
				found =true;
				break;
			}
			else if(curr>target){
				high = mid-1;
			}
			else
				low = mid+1;

		}


		return found;
	}

};



int main(){
	Solution sol;
	vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}} ;
	cout<<"The element 3 is present in [[1,3,5,7],[10,11,16,20],[23,30,34,60]]: "<<sol.searchMatrix(matrix1, 3)<<"\n";
	return 0;
}