# SingleLinkedListExample

By modifying the SingleLinkedListExample, implement a doubly linked list with the following definition

struct DNode {
	int data;
	DNode *prev;
	DNode *next;

	DNode(int d = 0) ...

};

class DList {
	DNode* head;
	DNode* tail;
	unsigned int count;
public:
	DList() {
	}

	void AddFront(int x) {
	}

	void AddBack(int x) {
	}

	bool PopFront(int& ret) {
	}

	bool PopBack(int& ret) {
	}

	Node* GetElementAtPos(unsigned int pos) {
	}

	void Print() {
	}
};
