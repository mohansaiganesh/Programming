/*
	1. Given 2 sorted arrays. num1 and num2.
	2. return median of sorted arrays.
	3. length of num1 =m and num2 =n;
	4. the value of m,n lies in [0,1000] and m+n lies in [1,2000].

*/


#include<iostream>
#include<vector>
#include<climits>


using namespace std;

class Solution{
public:
	void increment_indices(int& index, int& ij, vector<int>& nums12, int& m, int& n, int& med1, int& med2){
		if(index == (int)(m+n)/2 - 1) med1 = nums12[ij];
		if(index == (int)(m+n)/2){
			med2 = nums12[ij];
		}
		ij++;
		index++;

	}
	
	double findMedianSortedArrays_using_iteration(vector<int>& nums1, vector<int>& nums2){
		double res = 0.0;
		int m = nums1.size();
		int n = nums2.size();

		//we need the values of (m+n)/2 and (m+n)/2 - 1
		int med1 = 0;
		int med2 = 0;
		
		int i=0, j=0;

		int index = 0;
		
		while(i<m && j<n){
			if(nums1[i]<nums2[j]){
				//cout<<nums1[i]<<"\n";
				increment_indices(index, i, nums1, m, n, med1, med2);
			}
			else{
				//cout<<nums2[j]<<"\n";
				increment_indices(index, j, nums2, m, n, med1, med2);
			}

		}

		while(i<m){
			//cout<<nums1[i]<<"\n";
			increment_indices(index, i, nums1, m, n, med1, med2);
		}

		while(j<n){
			//cout<<nums2[j]<<"\n";
			increment_indices(index, j, nums2, m, n, med1, med2);
		
		}

		if((m+n)%2) res = med2;
		else{
			res = (med1+med2)/2.0;
		}
	
		//cout<<"med1: "<<med1<<", med2: "<<med2<<"\n";

		return res;
	}



	double findMedianSortedArrays_using_BinarySearch(vector<int>& nums1, vector<int>& nums2){
		double res = 0.0;
		
		//find the minimum length vector
		vector<int>& X = (nums1.size() < nums2.size()) ? nums1 : nums2;
		vector<int>& Y = nums1.size() < nums2.size() ? nums2 : nums1;
	
		int x = X.size();
		int y = Y.size();

		
		//median is the middle value, so it divides merged array into 2 partitions.Lets say leftPart and rightPart

		//binary search on X to find the leftPart
		int low = 0;
		int high = x;
		while(low<=high){
			int partitionX = (low+high)/2;
			int partitionY = (x+y+1)/2 - partitionX;

			int maxOfLeftX = partitionX == 0 ? INT_MIN : X[partitionX-1];
			int maxOfLeftY = partitionY ==0 ? INT_MIN : Y[partitionY-1];

			int minOfRightX = partitionX == x ? INT_MAX : X[partitionX];
			int minOfRightY = partitionY == y ? INT_MAX : Y[partitionY];


			if(maxOfLeftX <= minOfRightY && maxOfLeftY <= minOfRightX){
				//we found the block
				if((x+y)%2) res = max(maxOfLeftX, maxOfLeftY);
				else res = (max(maxOfLeftX, maxOfLeftY) + min(minOfRightX, minOfRightY) )/2.0;
				break;
				
			}
			else if(maxOfLeftX > minOfRightY) high = partitionX - 1;
			else low = partitionX + 1;
			
		}		

		return res;
	}


};

int main(){

	Solution sol;

	vector<int> nums1 = {1,3,4,7,8,9,10};
	vector<int> nums2 = {2,5,6};
	cout<<"The median of 2 arrays nums1 and nums2 is: "<<sol.findMedianSortedArrays_using_BinarySearch(nums1, nums2)<<"\n";


	return 0;
}
