#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;



class Solution{
public:
	int subarraySum(vector<int>& nums, int k){
		int count = 0;
		unordered_map<int,int> checkMap;
		checkMap[0] = 1;

		vector<int> cumSum(nums.size(),0);

		cumSum[0] = nums[0];
		for(int i=1; i<nums.size(); i++)
			cumSum[i] = cumSum[i-1]+nums[i];


		for(int i=0; i<cumSum.size(); i++){
			if(checkMap.count(cumSum[i]-k)){
				count += checkMap[cumSum[i]-k];
			}
			
			checkMap[cumSum[i]]++;
		}
	
		return count;
	
	}

};






int main(){
	vector<int> nums1 = {1,2,3};
	Solution sol;
	cout<<"The number of subarrays whose sum=3 in [1,2,3] is: "<<sol.subarraySum(nums1, 3)<<"\n";

	vector<int> nums2 = {1,1,1};
	cout<<"The number of subarrays whose sum=2 in [1,1,1] is: "<<sol.subarraySum(nums2, 2)<<"\n";
	return 0;
}