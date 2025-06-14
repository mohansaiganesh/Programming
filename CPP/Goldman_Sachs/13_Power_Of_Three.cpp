/*
	1. Given integer, return true if it is a power of three, else false.

*/

#include<iostream>

using namespace std;

class Solution{
public:
	bool isPowerOfThree(int n){
		if(n<=0) return false;

		int rem = 0;

		while(n){
			rem = n%3;
			if(rem && n!=1){
				return false;	
			}
			n = n/3;
		}

		if(rem==1) return true;
		return false;
	
	}

	bool isPoweOfThree_using_Logarithm(int n){
		if(n<=0) return false;
		
		double logVal = log10(n)/log10(3);

		return fabs(round(logVal) - logVal) < 1e-10;

	}

	

};


int main(){
	Solution sol;
	cout<<"The number '27' is a power of 3: "<<sol.isPowerOfThree(27)<<"\n";
	return 0;
}
