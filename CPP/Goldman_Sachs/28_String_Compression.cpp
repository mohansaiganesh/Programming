/*
	1. Given array chars, of size atleast one.
	2. Update chars such that character followed by the frequency in the same array chars.
	3. Return length of final chars array(valid).

*/


#include<iostream>

#include<vector>


using namespace std;


class Solution{
public:

	string compress(const string& sequence){
		string compressedString = "";
		int n = sequence.size();

		if(n==0) return compressedString;

		char currChar = sequence[0];
		int count = 1;

		compressedString += currChar;

		for(int i=1; i<n; i++){
			if(sequence[i]==currChar){
				count++;
			}
			else{
				compressedString += to_string(count);

				currChar = sequence[i];
				count = 1;

				compressedString += currChar;
			}
		
		}
		
		compressedString += to_string(count);
		

		return compressedString;

	}


	int compress_inplace(vector<char>& chars){
		int count = 0;
		int index = 0;

		char prevChar = chars[0];
		count = 1;
		index = 1;

		for(int j=1; j<chars.size();j++){
			if(chars[j] == prevChar){
				count++;
			}
			else{
				
				if(count>1){
					string countStr = to_string(count);
					for(char c : countStr){
						chars[index] = c;
						index++;
					}
				}

				prevChar = chars[j];
				count = 1;
		
				chars[index] = chars[j];
				index++;
			}

		}

		if(count>1){//add count to the array, only if count greater than 1
			string countStr = to_string(count);
			for(char c : countStr){
				chars[index] = c;
				index++;
			}	
		}


		return index;

	}
};


int main(){
	Solution sol;
	vector<char> chars1 = {'a','a','b','b','c','c','c'};
	cout<<"The length of the compressed ['a','a','b','b','c','c','c'] is: "<<sol.compress_inplace(chars1)<<"\n";
	cout<<"The compressed version of 'aabbccc' is: "<<sol.compress("aabbccc")<<"\n";

	cout<<"The compressed version of 'a' is: "<<sol.compress("a")<<"\n";

	cout<<"The compressed version of 'abc' is: "<<sol.compress("abc")<<"\n";
	
	vector<char> chars2 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	cout<<"The length of the compressed ['a','b','b','b','b','b','b','b','b','b','b','b','b'] is: "<<sol.compress_inplace(chars2)<<"\n";

	//for(char c : chars2) cout<<c<<" ";

	return 0;
}


