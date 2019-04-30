#include <iostream>

using namespace std;

template <class T>
class List;

template <class T>
class Node{
	public:
	T data;
	Node(T new_data){
		data = new_data;
		next = NULL;
	}	
	private:
	Node<T> *next;

	//define List class as friend so that List can access *next ptr in a node
	friend class List<T>; 
};

template <class T>
class List{
	public:

	//default constructor
	List(){
		head = NULL;
	}

	//destructor
	~List(){
		if(head != NULL){
			Node<T> *cur = head;
			Node<T> *temp;
			while(cur != NULL){
				temp = cur;
				cur = cur->next;
				delete temp;
			}		
			cout << "List Destructor Called." << endl;
		}
	}

	//add new node to head of the list
	void add(T data){
		Node<T> *ptr = new Node<T>(data);
		ptr->next = head;
		head = ptr;
	}

	//print list from head to tail
	void print(){
		if(head == NULL)
			{cout << "List is Empty" << endl;}
		else{
			Node<T> *current = head;
			while(current != NULL){
				cout << current->data << endl;
				current = current->next;
			}
		}
	}
	private:
		Node<T> *head;
};

int main(){
	List<int> list1;

	list1.add(5);
	list1.add(2);
	list1.add(4);

	list1.print();

	List<double> list2;

	list2.add(5.3);
	list2.add(2.1);
	list2.add(4.7);

	list2.print();	

	return 0;
}