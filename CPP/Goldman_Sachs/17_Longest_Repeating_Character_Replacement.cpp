#include<iostream>


using namespace std;

class Solution{
public:
	int characterReplacement(string s, int k){
		int length = 0;
		int freq[26] = {0};

		if(s.size()==0) return length;

		freq[s[0]-'A']++;
		length = 1;
		int i = 0;
		int maxFreq = 1;

		for(int j = 1; j<s.size(); j++){
			freq[s[j]-'A']++;

			if(freq[s[j]-'A'] > maxFreq) maxFreq=freq[s[j]-'A'];

			//shrink the window if condition fails
			while((j-i+1) - maxFreq > k){
				freq[s[i]-'A']--;
				i++;
			}

			length = max(length, j-i+1);

			
			
		}

		

		return length;
	}

};

int main(){
	Solution sol;
	cout<<"The longest string that can be achieved using the k=1 in AABABBA is: "<<sol.characterReplacement("AABABBA", 1)<<"\n";

	return 0;
}

