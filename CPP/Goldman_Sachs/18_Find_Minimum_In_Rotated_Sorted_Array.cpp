/*
	1. Given nums = integer array with unique elements.
	2. nums is a rotated sorted array.
	3. Return minimum element.

*/

#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
	int findMin(vector<int>& nums){
		int minNum = INT_MAX;
		int i=0, j=nums.size()-1;
		
		while(i<=j){
			int middle = (i+j)/2;
			
			if(nums[i]<=nums[middle]){//left array is sorted
				if(minNum>nums[i]) minNum=nums[i];
				i = middle+1;
			}
			else{ //right array is sorted
				if(minNum>nums[middle]) minNum=nums[middle];
				j = middle-1;

			}	

		}
		
		return minNum;
	}

};



int main(){
	Solution sol;
	vector<int> nums1 = {6,7,2,3,4,5};
	cout<<"The minimum element in [6,7,2,3,4,5] is: "<<sol.findMin(nums1)<<"\n";
	return 0;
}