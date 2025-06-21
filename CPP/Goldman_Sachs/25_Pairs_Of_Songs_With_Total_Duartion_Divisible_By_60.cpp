#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution{
public:
	int numPairsDivisibleBy60(vector<int>& time){
		int count =0;
   		unordered_map<int, int> freqMap;

		//iterate time vector and apply mod to each element, do 60 - modResult and check whether it is present in map, else push to map
		int temp = 0;
		for(int& x : time){
			temp = 60-(x%60);
			if(freqMap.count(temp)){
				count+= freqMap[temp];
			}

			if(x%60==0) freqMap[60]++;
			else freqMap[x%60]++;

		}
		

	
		return count;	

	}


};


int main(){
	Solution sol;
	vector<int> time1 = {60,60,60};
	cout<<"The number of pairs in [60,60,60] that are divisible by 60: "<<sol.numPairsDivisibleBy60(time1)<<"\n";

	vector<int> time2 = {30,20,150,100,40};
	cout<<"The number of pairs in [30,20,150,100,40] that are divisible by 60: "<<sol.numPairsDivisibleBy60(time2)<<"\n";
	

	return 0;
}