#include<iostream>
#include<unordered_map>

using namespace std;


class Node{
public:
	int key, value;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(){
		value = 0;
		key = 0;
	}

	Node(int key, int value){
		this->key = key;
		this->value = value;
	}

};


class DLL{
private:
	//head and tail are dummy nodes
	Node* head=nullptr;
	Node* tail=nullptr;
public:
	DLL(){
		head = new Node();
		tail = new Node();
	
		//join head and tail
		head->right = tail;
		tail->left = head;
	}
	
	//insert node next to the head
	void attachNodeAtHead(Node* node){
		Node* nextToHead = head->right;
		
		node->left = head;
		node->right = nextToHead;

		head->right = node;
		nextToHead->left = node;

	}

	//detach node from the list
	void detachNode(Node* node){
		Node* left = node->left;
		Node* right = node->right;

		left->right = right;
		right->left = left;

		node->left = nullptr;
		node->right = nullptr;
	}

	//get the tail pointer
	Node* getTail(){
		return tail;
	}
	


};


class LRUCache{
private:
	int cap;
	unordered_map<int,Node*> ump;
	DLL dll;

public:
	LRUCache(int capacity){
		this->cap = capacity;
	}

	int get(int key){
		int value = -1;
		if(ump.count(key)){
			Node* node = ump[key];
			value = node->value;
			
			//detach node from current position and attach to the front
			dll.detachNode(node);
			dll.attachNodeAtHead(node);

		}
		return value;
	}

	void put(int key, int value){
		//if key is already present just update the dll
		if(ump.count(key)){
			Node *node = ump[key];
			node->value = value;
			//detach node and attach to the front
			dll.detachNode(node);
			dll.attachNodeAtHead(node);
		}
		else if(ump.size()<cap){
			//just create the node and add the data to ump and dll
			Node* node = new Node(key, value);
			ump[key] = node;
			
			//insert node at the front
			dll.attachNodeAtHead(node);
			
	
		}
		else{
			//eviction has to be done
			
			//detach the last node
			Node* lastNode = dll.getTail()->left;
			dll.detachNode(lastNode);

			int oldKey = lastNode->key;
			ump.erase(oldKey);
			
			ump[key] = lastNode;

			//update the lastNode data
			lastNode->value=value;
			lastNode->key = key;

			//insert at front
			dll.attachNodeAtHead(lastNode);
				

			
		}
	}



};





int main(){

	LRUCache lru(5);

	


	return 0;
}