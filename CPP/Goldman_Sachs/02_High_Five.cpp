/*
	1. List of scores
	2. score format -- [id, score]
	3. return average of top 5 scores for each id(sorted in ascending order)

*/


#include<iostream>
#include<vector>
#include<map>
#include<queue>


using namespace std;


class Solution{
public:
	vector<vector<int>> high_five(vector<vector<int>>& scores){

		//create hashmap for student ids(key=id, value=correspoding index in vector)
		map<int, int> idToIndexMap;
		
		for(int i=0; i<scores.size(); i++){
			idToIndexMap[scores[i][0]] = 0;
		}

		//iterate the map and update the values of each key
		int mapSize = 0;
		for(auto& item : idToIndexMap){
			item.second = mapSize;
			mapSize++;
		}

				
		//vector of priority queues (min heap), size of vector depends on the size of hashmap
		vector<priority_queue<int, vector<int>, greater<int>>> studentRecords(mapSize);

		//iterate through the scores and push into the corresponding studentRecords, such that each record should have only 5 marks
		for(int i=0; i<scores.size(); i++){
			int index = idToIndexMap[scores[i][0]];
			int marks = scores[i][1];
			auto& studentRecord = studentRecords[index];

			if(studentRecord.size()<5)
				studentRecord.push(marks);

			else{
				if(marks > studentRecord.top()){
					studentRecord.push(marks);
					studentRecord.pop();
				}	
			}

			
		
		}




		//calculate average for each index and append to the result vector
		vector<vector<int>> result;

		for(auto& item : idToIndexMap){
			
			int average = 0;
			int index = item.second;
			auto& studentRecord = studentRecords[index];
			//cout<<"studentRecord size: "<<studentRecord.size()<<"\n";
			
			while(!studentRecord.empty()){
				average += studentRecord.top();
				//cout<<"studentRecord.top(): "<<studentRecord.top()<<"\n";
				studentRecord.pop();
			}
			average = average/5;
			result.push_back({item.first, average});
	
		}
		
		return result;
	}


};



int main(){

	vector<vector<int>> scores1 = {{1,91}, {1,92}, {2,93}, {2,97}, {1,60}, {2,77}, {1,65}, {1,87}, {1,100}, {2,100}, {2,76}};

	Solution sol;
	
	vector<vector<int>> result = sol.high_five(scores1);

	for(auto& record : result){
		cout<<record[0]<<" "<<record[1]<<"\n";
	}

	return 0;
}
