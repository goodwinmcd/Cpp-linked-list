#include <iostream>

class LinkedList{
	struct Node{
		int data;
		Node *nextNode;
	};
	public:
	  LinkedList();
	  ~LinkedList();
	  void addNode(int value);
	  void deleteFront();
	  int getValue(int index);
	private:
	  Node *headPointer;
	  int size;
};

	LinkedList::LinkedList(){
		headPointer=NULL;
		size=0;
	}
	LinkedList::~LinkedList(){
	}

	void LinkedList::addNode(int value){
		Node *newNode=new Node();
		newNode->data=value;
		newNode->nextNode=headPointer;
		headPointer=newNode;
		size++;
	}

	void LinkedList::deleteFront(){
		Node *pointerToFrontNode=headPointer;
		headPointer=headPointer->nextNode;
		delete pointerToFrontNode;
		size--;
	}	

	int LinkedList::getValue(int index){
		if(index>=size){
			std::cout<<"The list is not that large"<<std::endl;
			exit(1);
		}
		else{
			Node *traverse=headPointer;
			for(int i=0;i<index;i++){
				traverse=traverse->nextNode;
			}
		return traverse->data;
		}
	}

int main(){
	LinkedList list;
	list.addNode(5);
	list.addNode(4);
	std::cout<<"The node value is: "<<list.getValue(0)<<std::endl;
	list.deleteFront();
	std::cout<<"The node value is: "<<list.getValue(0)<<std::endl;
	return 0;
}
