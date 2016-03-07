//============================================================================
// Name        : LinkedListExample.cpp
// Author      : atc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;

	Node(int d = 0) {
		data = d;
		next = NULL;
	}
};

class List {
	Node* head;
	unsigned int count;
public:
	List() {
		head = NULL;
		count = 0;
	}

	void AddFront(int x) {
		if (head == NULL) {
			head = new Node(x);
		}
		else {
			Node* tmp = head;
			head = new Node(x);
			head->next = tmp;
		}
		count++;
	}

	void AddBack(int x) {
		if (head == NULL) {
			head = new Node(x);
		}
		else {
			Node* p;
			for (p = head; p->next != NULL; p = p->next);

			p->next = new Node(x);
		}
		count++;
	}

	bool PopFront(int& ret) {
		if (head == NULL) return false;
		Node* tmp = head;
		head = tmp->next;
		ret = tmp->data;
		delete tmp;
		count--;
		return true;
	}

	bool PopBack(int& ret) {
		if (head == NULL) return false;
		Node* p;
		Node* prev = head;
		for (p = head; p->next != NULL; p = p->next) prev = p;
		ret = p->data;
		if (prev == p) {
			head = NULL;
		}
		else {
			prev->next = NULL;
		}
		delete p;
		count --;
		return true;
	}

	Node* GetElementAtPos(unsigned int pos) {
		if (pos >= count) return NULL;
		int idx = 0;
		for (Node* p = head; p->next!=NULL; p=p->next)
			if (idx++ == pos) return p;
	}

	void Print() {
		cout << "List with " << count << " Elements:" << endl;
		for (Node* p = head; p!= NULL; p = p->next) {
			cout << p->data << " ";
		}
		cout << endl;
	}
};

int main() {
	List l;

	l.AddFront(6);
	l.AddFront(4);
	l.AddBack(13);
	l.AddFront(5);
	l.AddFront(3);
	l.AddBack(12);

	l.Print();

	//int ret;
	//while (l.PopBack(ret)) cout << ret << endl;

	Node* p = l.GetElementAtPos(13);
	if (p!=NULL)
	cout << p->data << endl;
	else cout << "Not Found" << endl;

	l.Print();
	return 0;
}
