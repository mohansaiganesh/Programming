#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;


class Solution{
public:
	int getLargestOutlier(vector<int>& nums){
		int res = 0;
		vector<int> numsCopy = nums;

		
		unordered_map<int, int> freqMap;
		int sum = 0;

		for(int x : numsCopy){
			freqMap[x]++;
			sum+=x;
		}

		sort(numsCopy.begin(), numsCopy.end());

		for(int i=numsCopy.size()-1; i>=0; i--){
			int temp = sum - numsCopy[i];
			
			freqMap[numsCopy[i]]--;
			if(temp%2==0 && freqMap[temp/2]>0){
				res = numsCopy[i];
				break;
			}

			freqMap[numsCopy[i]]++;
		}
		return res;
	
	}

};

int main(){
	Solution sol;
	vector<int> v1 = {2,3,5,10};
	cout<<"The largest outlier in [2,3,5,10] is : "<<sol.getLargestOutlier(v1)<<"\n";

	vector<int> v2 = {-2,-1,-3,-6,4};
	cout<<"The largets outlier in [-2,-1,-3,-6,4] is :"<<sol.getLargestOutlier(v2)<<"\n";

	return 0;
}