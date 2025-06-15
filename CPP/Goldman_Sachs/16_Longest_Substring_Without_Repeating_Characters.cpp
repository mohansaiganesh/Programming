/*
	1. given a string 's'.
	2. return the length of longest string without repeating characters.

*/


#include<iostream>
#include<unordered_set>

using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int length = 0;

		if(s.size() == 0) return length;

		unordered_set<char> contains;

		
		contains.insert(s[0]);
		int i = 0;
		length = 1;

		for(int j=1; j<s.size(); j++){
			
			//check if the element at j is already present in the set. Remove all the elements till the set doesn't contain s[j].
			while(contains.count(s[j])){
				contains.erase(s[i]);
				i++;
			}	
	
			contains.insert(s[j]);

			int windowLength = j-i+1;

			length = max(length, windowLength);
		

		}		
		
		

		return length;
	}

};

int main(){
	Solution sol;

	cout<<"The length of longest substring in 'abcabcbb' is: "<<sol.lengthOfLongestSubstring("abcabcbb")<<"\n";

	return 0;
}