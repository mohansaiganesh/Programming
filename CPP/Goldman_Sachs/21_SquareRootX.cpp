/*
	1. x = non negative integer
	2. return square root of x, rounded down to nearest integer.
*/

#include<iostream>

using namespace std;


class Solution{
public:
	int mySqrt(int x){
		//int root = 0;
			
		if(x<=1) return x;
		
		int low = 1;
		int high = x/2;

		long int mid = 0;

		while(low<=high){
			mid = (low+high)/2;
			if(mid*mid == x) return mid;
			else if(mid*mid<x) low=mid+1;
			else high=mid-1;
		}

		
		
		return high;
		
	}

};


int main(){
	Solution sol;
	cout<<"The square root of 8 rounded to nearest integer is: "<<sol.mySqrt(8)<<"\n";
	return 0;
}