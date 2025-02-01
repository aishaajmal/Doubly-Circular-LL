#include <iostream>
#include "Node.h"
using namespace std;
class DCLL {
protected:
	Node* tail;
	Node* head;
public:
	virtual void insertAtTail(int) = 0;
	virtual void insertAtHead(int) = 0;
	virtual void deleteFromHead() = 0;
	virtual void deleteFromTail() = 0;
	virtual void deleteFromAnyPosition(int)=0;
	virtual bool search(int value) = 0;
	DCLL();

};
DCLL::DCLL() {
	tail = nullptr;
	head = nullptr;
}