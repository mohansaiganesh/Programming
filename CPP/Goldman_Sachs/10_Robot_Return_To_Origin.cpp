/*
	1. given string containing the letters 'U', 'L', 'D', 'R'.
	2. Return if the robot returns to origin or not.

*/

#include<iostream>


using namespace std;


class Solution{
public:
	bool judgeCircle(string moves){
		
		int x = 0, y=0;

		for(char c : moves){
			if(c=='U') y++;
			else if(c=='D') y--;
			else if(c=='R') x++;
			else if(c=='L') x--;
		}
		
		if(x==0 && y==0) return true;
		else return false;
	}


};


int main(){
	Solution sol;	
	
	cout<<"The robot returns to origin when moves='UD' : "<<sol.judgeCircle("UD")<<"\n";

	return 0;

}