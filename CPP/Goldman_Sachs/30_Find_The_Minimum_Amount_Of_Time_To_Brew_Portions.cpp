#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
	long long int minTime(vector<int>& skill, vector<int>& mana){
		long long int time = 0;

		vector<long long int> endTimes(skill.size(), 0);

		//for single potion
		endTimes[0] = skill[0]*mana[0];
		for(int j=1; j<skill.size(); j++){
			endTimes[j] = endTimes[j-1] + mana[0]*skill[j];

		}




		//handling multiple potions
		vector<long long int> cumTimes(skill.size(), 0);

		long long int startTime = 0;

		for(int i=1; i<mana.size(); i++){
			startTime = endTimes[0];
			cumTimes[0] = mana[i]*skill[0];
			for(int j=1; j<skill.size(); j++){
				cumTimes[j] = cumTimes[j-1] + mana[i]*skill[j];
			}

			for(int j=0; j<cumTimes.size()-1; j++){
				if(endTimes[j+1]-cumTimes[j]>startTime){
					startTime = endTimes[j+1]-cumTimes[j];
				}
			}

			//update the endTimes vector using the startTime
			for(int j=0; j<endTimes.size(); j++){
				endTimes[j] = startTime + cumTimes[j];
			}
			

		}




		
		

		return endTimes[skill.size()-1];
	}	

};



int main(){
	Solution sol;

	vector<int> skill1 = {1,5,2,4};
	vector<int> mana1 = {5,1,4,2};

	cout<<"The minimum amount of time taken to brew the potions for skill [1,5,2,4] ana mana [5,1,4,2] is: "<<sol.minTime(skill1, mana1)<<"\n";
	
	return 0;
}







