/*
	1. Given Integer array height of size n.(n>=2)
	2. Return the container with most water.
	3. distance between each line/pole is 1 unit.
	4. water between two poles i,j is (j-i)*min(height[i], height[j]),so process min height block first.
	5. if (j-i) value decreases, and if min(heightp[i], height[j]) increases then max Water trapped will increase.

*/

#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
	int maxArea(vector<int>& height){
		int maxWater = 0;
		int n =height.size();
		int i=0, j=n-1;

		while(i<j){
			int water = (j-i)*min(height[i], height[j]);
			if(water>maxWater) maxWater=water;

			if(height[i]<=height[j]) i++;
			else j--;
	
		}

		return maxWater;
	
	}


};


int main(){

	Solution sol;
	
	vector<int> height1 = {1,8,6,2,5,4,8,3,7};
	cout<<"The maxArea for [1,8,6,2,5,4,8,3,7] is: "<<sol.maxArea(height1)<<"\n";
	return 0;
}
