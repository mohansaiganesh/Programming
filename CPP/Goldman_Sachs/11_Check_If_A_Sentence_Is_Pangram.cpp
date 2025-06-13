/*
	1. all lowercase letters should occur atleast once
	2. return true, if found else false.
	
*/

#include<iostream>


using namespace std;

class Solution{
public:
	bool checkIfPangram(string sentence){
		int count = 0;
		int alphabets[26] = {0};

		for(char c : sentence) alphabets[c-'a']=1;
	
		for(int x : alphabets)
		if(x==1) count++;

		if(count==26) return true;
		return false;
	}

};


int main(){
	Solution sol;
	cout<<"The sentence 'thequickbrownfoxjumpsoverthelazydog' is a pangram: "<<sol.checkIfPangram("thequickbrownfoxjumpsoverthelazydog")<<"\n";
	return 0;
}