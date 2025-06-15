/*
	1. Given array nums containing distinct numbers.
	2. the array is rotated.
	3. Search an element in the rotated array, return its index. If not found, return -1.

*/


#include<iostream>
#include<vector>


using namespace std;

class Solution{
public:
	int search(vector<int>& nums, int target){
		int index = -1;

		int low = 0;
		int high = nums.size()-1;

		while(low<=high){
			int mid = (low+high)/2;
			if(nums[mid] == target){
				index=mid;
				break;
			}

			//select the sorted array and search for the target
			if(nums[low]<=nums[mid]){ //left array is sorted
				if(target>=nums[low] && target<nums[mid]){
					high = mid-1;
				}
				else{
					low = mid+1;	
				}
			}
			else{ //right array is sorted
				if(target>nums[mid] && target<=nums[high]){ 
					low = mid+1;
				}
				else{
					high = mid-1;
				}

			}
	
		}

		
		

		return index;
	
	}

	
};


int main(){
	Solution sol;
	vector<int> nums1 = {4,5,6,7,0,1,2};
	cout<<"The index of '5' in the nums1 is: "<<sol.search(nums1,5)<<"\n";
	return 0;
}
