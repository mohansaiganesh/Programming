/*
	1. nums = integer array. nums.size()>=1.
	2. k = integer
	3. return kth largest element, not the distinct element
	4. solve without sorting
	5. 

*/

#include<iostream>
#include<queue>


using namespace std;

class Solution{
public:
	int findKthLargest(vector<int>& nums, int k){
		int res = nums[0];
		//create min heap
		priority_queue<int, vector<int>, greater<int>> minHeap;
		
		for(int& num : nums){
			if(minHeap.size()<k) minHeap.push(num);
			
			else{
				if(num > minHeap.top()){
					minHeap.push(num);
					minHeap.pop();
				}
			}
			
		}
		res = minHeap.top();
		return res;
	}	
};

int main(){
	
	Solution sol;

	vector<int> nums1 = {3,2,1,5,6,4};
	cout<<"The 2nd Largest number in '{3,2,1,5,6,4}' is: "<<sol.findKthLargest(nums1, 2)<<"\n";

	vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
	cout<<"The 4th Largest number in '{3,2,3,1,2,4,5,5,6}' is: "<<sol.findKthLargest(nums2, 4)<<"\n";

	return 0;
}