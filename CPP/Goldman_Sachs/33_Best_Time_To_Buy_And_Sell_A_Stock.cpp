#include<iostream>
#include<vector>


using namespace std;

class Solution{
public:
	int maxProfit(vector<int>& prices){
		int maxPro = 0;	
		int currMin = prices[0];
		
		for(int i=1; i<prices.size(); i++){
			if(prices[i]>currMin){
				maxPro = max(maxPro, prices[i]-currMin);
			}
			else currMin = prices[i];		
		}
		

		return maxPro;
	}

};


int main(){
	
	vector<int> prices1 = {7,1,5,3,6,4};
	Solution sol;

	cout<<"The max profit in [7,1,5,3,6,4] is: "<<sol.maxProfit(prices1)<<"\n";

	return 0;
}