/*
	1. strs = array of strings.
	2. group the anagrams together.
	3. return vector<vector<string>>.
	4. strs.size()>0.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>


using namespace std;

class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs){
		vector<vector<string>> grouped;

		unordered_map<string, vector<string>> anagramMap;
		
		for(string& stri : strs){
			vector<int> freq(26,0);
			for(char c : stri){
				freq[c-'a']++;
			}
			string sorted = "";
			for(int x: freq) sorted=sorted+to_string(x)+"#";

			

			anagramMap[sorted].push_back(stri);

		}

		for(const pair<string, vector<string>>& item : anagramMap){
			grouped.push_back(item.second);
		}

		return grouped;
	
	}


	vector<vector<string>> groupAnagrams_using_sorting(vector<string>& strs){
		vector<vector<string>> grouped;
		unordered_map<string, vector<string>> anagramMap;
	
		
		for(string& str : strs){
			string temp = str;
			sort(temp.begin(), temp.end());
			anagramMap[temp].push_back(str);
		}

		for(const pair<string, vector<string>>& item : anagramMap){
			grouped.push_back(item.second);
		}

		return grouped;
	}

	void print(vector<string>& vec){
		cout<<"[";
		for(string& str : vec){
			cout<<str<<",";
		}
		cout<<"]";
	}

	void print(vector<vector<string>>& vecVector){
		cout<<"[";
		for(vector<string>& v : vecVector){
			print(v);
			cout<<",";
		}
		cout<<"]";

	}


};


int main(){
	Solution sol;
	vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};

	vector<vector<string>> groupedStrs1 = sol.groupAnagrams(strs1);

	sol.print(groupedStrs1);
	cout<<"\n";

	//cout<<"The grouped anagrams for ["eat","tea","tan","ate","nat","bat"] is :

	return 0;
}