#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int singleNumber(vector<int>& nums){
		int singleNum = nums[0];

		for(int i=1; i<nums.size(); i++) singleNum ^= nums[i];

		return singleNum;
	}	

};




int main(){
	Solution sol;

	vector<int> nums1  = {4,1,2,1,2};
	cout<<"The single number in the array [4,1,2,1,2] is: "<<sol.singleNumber(nums1)<<"\n";

	return 0;
}