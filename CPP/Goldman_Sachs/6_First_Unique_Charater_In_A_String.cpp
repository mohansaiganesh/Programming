/*
	1. Given string s.
	2. Find first non repeating character in it.
	3. if found return index, if not return -1.
	4. length of string is greater than equal to 1.

*/

#include<iostream>
#include<unordered_map>


using namespace std;

class Solution{
public:
	int firstUniqChar(string s){
		int res = -1;
		unordered_map<char, int> freqMap;
	
		for(int i=0; i<s.size(); i++){
			freqMap[s[i]]++;
		}

		for(int i=0; i<s.size(); i++){
			if(freqMap[s[i]] == 1){
				res = i;
				break;
			}
		}
		

		return res;
	}

	int firstUniqChar_using_array(string s){
		int res = -1;
		
		int freqMap[26] = {0};
		
		for(int i=0; i<s.size(); i++){
			freqMap[s[i]-'a']++;
		}

		for(int i=0; i<s.size(); i++){
			if(freqMap[s[i]-'a'] == 1){
				res = i;
				break;
			}
		}	

		return res;	

	}

};


int main(){
	Solution sol;

	cout<<"The first unique character in the string 'leetcode' is: "<<sol.firstUniqChar("leetcode")<<"\n";
	cout<<"The first unique character in the string 'loveleetcode' is: "<<sol.firstUniqChar("loveleetcode")<<"\n";

	cout<<"The first unique character in the string 'leetcode' using the method firstUniqChar_using_array is: "<<sol.firstUniqChar_using_array("leetcode")<<"\n";

	return 0;
}