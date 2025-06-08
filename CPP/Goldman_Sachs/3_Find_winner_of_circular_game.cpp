/*
	1. 1 based indexing.
	2. number of friends = n
	3. count to eliminate = k


*/



#include<iostream>


using namespace std;



class Solution{
public:
	int findTheWinnerRecursive(int n, int k){
		//n= 5, k=3

		// 1, 2, 3, 4, 5
		//after elimination 1, 2, 4, 5
		
		// 1, 2, 3, 4, 5 ---> 3, 4, 0, 1, 2  ----> (y+(k-1))%5 + 1 
		// f(5,3) ---> f(4,3)

		//f(n,k) = (f(n-1,k) + (k-1))%n + 1; --- recurrence relation


		//Base case
		if(n==1)
		return 1;

		return (findTheWinnerRecursive(n-1, k) + (k-1))%n + 1;


	}


	int findTheWinnerIterative(int n, int k){
	
		int winner = 1;
		
		for(int i=2; i<=n; i++){
			winner = (winner+(k-1))%i + 1;
		}

		return winner;
		
	}


};




int main(){
	Solution sol;

	cout<<"The winner of circular game when n=5 and k=2 is: "<<sol.findTheWinnerRecursive(5, 2)<<"\n";
	cout<<"The winner of circular game when n=6 and k=5 is: "<<sol.findTheWinnerRecursive(6, 5)<<"\n";


	cout<<"\n";

	cout<<"The winner of circular game when n=5 and k=2 is: "<<sol.findTheWinnerIterative(5, 2)<<"\n";
	cout<<"The winner of circular game when n=6 and k=5 is: "<<sol.findTheWinnerIterative(6, 5)<<"\n";


	

	
	return 0;

}