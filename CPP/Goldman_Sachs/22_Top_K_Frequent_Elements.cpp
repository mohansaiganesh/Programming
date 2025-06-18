/*
	1. nums = integer array.
	2. k = integer
	3. return k most frequent elements

*/


#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;


class Solution{
public:
	vector<int> topKFrequent(vector<int>& nums, int k){
		vector<int> freqElements;

		unordered_map<int,int> freqMap;
		for(int& x : nums) freqMap[x]++;

		priority_queue<pair<int,int>> pq;

		for(pair<int,int> item : freqMap){
			pq.push({item.second,item.first});
		}
	
		for(int i=0; i<k; i++){
			if(!pq.empty()){

				freqElements.push_back(pq.top().second);
				pq.pop();
			}
		}	

		return freqElements;
	}


};



int main(){
	Solution sol;
	vector<int> nums1 = {1,1,1,2,2,3};

	vector<int> freqElements1 = sol.topKFrequent(nums1, 2);

	return 0;
}