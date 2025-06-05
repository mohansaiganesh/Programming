#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution{
public:
	int trap_using_extra_space(vector<int>& height){
		//Initialize leftMaxArr, rightMaxArr, leftMax, rightMax
		int leftMax = 0, rightMax = 0;	
		int n = height.size();

		//int leftMaxArr[n] = {0};
		//int rightMaxArr[n] = {0};	
		
		vector<int> leftMaxArr(n, 0);
		vector<int> rightMaxArr(n, 0);
		

		//parse from left to right and store the max in leftMaxArr
		for(int i=0; i<n; i++){
			leftMax = max(leftMax, height[i]);
			leftMaxArr[i] = leftMax;
		}
		

		//parse from right to left and store the max in rightMaxArr
		for(int i=n-1; i>=0; i--){
			rightMax = max(rightMax, height[i]);
			rightMaxArr[i] = rightMax;
		}

		int water = 0;

		for(int i=0; i<n; i++){
			water += min(leftMaxArr[i], rightMaxArr[i]) - height[i];
		}

		return water;
	}


	//method 2 --- using 2 pointer approach, Time complexity - O(n), Space complexity - O(1)
	int trap_using_two_pointer(vector<int>& height){
		
		int left = 0;
		int right = height.size()-1;
		int leftMax = 0, rightMax = 0;
		int water = 0;
		
		while(left<right){
			//keep right as stable boundary, move left
			if(height[right]>= height[left]){
				leftMax = max(height[left], leftMax);
				water += leftMax - height[left];
				left++;
			}
			else{
				rightMax = max(rightMax, height[right]);
				water += rightMax - height[right];
				right--;
			}

			//keep left as stable boundary, move right
		}
	
	return water;
	}
	


};



int main(){
	Solution sol;
	vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout<<"water trapped in height1(trap_using_extra_space): "<< sol.trap_using_extra_space(height1)<< "\n";

	cout<<"water trapped in height1(trap_using_two_pointer): "<< sol.trap_using_two_pointer(height1)<<"\n";
	
	return 0;
}