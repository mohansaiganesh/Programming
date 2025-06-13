/*
	1. given sentence s.
	2. return the length of the longest consective character.

*/

#include<iostream>

using namespace std;

class Solution{
public:
	int maxPower(string s){
	
		//string has min length one
		char curr = s[0];
		int count = 1;
		
		int maxCount = 1;
		for(int i=1; i<s.size(); i++){
			if(s[i]==curr){
				count++;
				if(count>maxCount) maxCount=count;
			}
			else{
				if(count>maxCount) maxCount=count;

				curr = s[i];
				count = 1;
			}
		}

		
		
		return maxCount;


	}

};


int main(){
	Solution sol;
	
	cout<<"The longest consecutive character in 'leetcode' is: "<<sol.maxPower("leetcode")<<"\n";
	cout<<"The longest consecutive character in 'ccc' is: "<<sol.maxPower("ccc")<<"\n";

	return 0;
}