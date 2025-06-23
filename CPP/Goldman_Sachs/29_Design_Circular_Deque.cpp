#include<iostream>
#include<vector>



using namespace std;


class Node{
public:
	Node *left=nullptr, *right = nullptr;
	int value;

	Node(){
		value = 0;
	}

	Node(int value){
		this->value = value;
	}
};


class MyCircularDeque{
private:
	int capacity;
	int size;
	Node *head=nullptr, *tail = nullptr;


public:
	MyCircularDeque(int k){
		capacity = k;
		size = 0;
		
		//dummy nodes
		head = new Node();
		tail = new Node();

		//join dummy nodes
		head->right = tail;
		tail->left = head;
	}

	bool insertFront(int value){
		if(size==capacity) return false;
		
		Node* node = new Node(value);
		
		Node* next = head->right;
		node->left = head;
		node->right = next;

		head->right = node;
		next->left = node;

		size++;
		
		return true;
		
	}

	bool insertLast(int value){
		if(size==capacity) return false;
		
		Node *node = new Node(value);

		Node *prev = tail->left;
		node->left = prev;
		node->right = tail;

		prev->right = node;
		tail->left = node;
		
		size++;
	
		return true;

	}

	bool deleteFront(){
		if(size==0) return false;
		
		Node *node = head->right;
	
		//detach node and attach to left and right
		Node *prev = node->left;
		Node *next = node->right;

		prev->right = next;
		next->left = prev;

		node->left = nullptr;
		node->right = nullptr;

		delete node;
		size--;
		
		
		return true;

	}

	bool deleteLast(){

		if(size==0) return false;
		
		Node *node = tail->left;

		Node *prev = node->left;
		Node *next = node->right;

		prev->right = next;
		next->left = prev;

		node->left = nullptr;
		node->right = nullptr;
		
		delete node;
	
		size--;
		return true;

	}

	int getFront(){
	
		if(size==0) return -1;

		return head->right->value;

	}

	int getlast(){
		if(size==0) return -1;

		return tail->left->value;
	}
	
	bool isFull(){
		if(size!=capacity) return false;

		return true;
	}
	
	bool isEmpty(){
		if(size!=0) return false;

		return true;
	}
	


};




class MyCircularDequeArrayImpl{
private:
	int capacity;
	int size = 0;
	vector<int> cd;
	int front = 0;
	int last = 0;

public:
	MyCircularDequeArrayImpl(int k) : cd(k), capacity(k){
	}

	bool insertFront(int value){
		if(size==capacity) return false;

		front = (front-1+capacity)%capacity;
		cd[front] = value;

		size++;
		return true;
	}

	bool insertLast(int value){

		if(size==capacity) return false;

		cd[last] = value;
		last = (last+1+capacity)%capacity;
		
		size++;
		return true;

	}

	bool deleteFront(){
		if(size==0) return false;
		
		front = (front+1+capacity)%capacity;
		size--;		

		return true;

	}

	bool deleteLast(){
		if(size==0) return false;

		last = (last-1+capacity)%capacity;
		size--;

		return true;

	}

	int getFront(){
		if(size==0) return -1;
		return cd[front];
	}

	int getLast(){
		if(size==0) return -1;
		
		return cd[(last-1+capacity)%capacity];

	}

	bool isEmpty(){
		if(size!=0) return false;
		
		return true;
	}

	bool isFull(){
		if(size!=capacity) return false;
		return true;
	}


};






int main(){
	MyCircularDeque mcd(3);

	MyCircularDequeArrayImpl mcdai(3);

		
	return 0;
}