#include "CircularLinkedList.h"

class myDCLL : public DCLL {
public:
    void insertAtTail(int value);
    void deleteFromTail();
    void insertAtHead(int value);
    void deleteFromHead();
    void display();
    void deleteFromAnyPosition(int);
    bool search(int);
};
bool myDCLL::search(int value) {
    if (tail == nullptr) {
        return false;
    }

    Node* temp = tail->next;  // Start from head

    do {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != tail->next);

    return false;
}
void myDCLL::deleteFromAnyPosition(int position) {
    if (tail == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }

    Node* temp = tail->next;  // Start from head
    int count = 1;

    while (count < position && temp != tail) {
        temp = temp->next;
        count++;
    }

    if (count != position) {
        std::cout << "Position out of range." << std::endl;
        return;
    }

    if (temp == tail->next) {  // Deleting head
        deleteFromHead();
    }
    else if (temp == tail) {  // Deleting tail
        deleteFromTail();
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}
void myDCLL::deleteFromHead() {
    if (tail == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }

    Node* temp = tail->next; 

    if (temp == tail) {  
        tail = nullptr;
    }
    else {
        tail->next = temp->next;
        temp->next->prev = tail;
    }

    delete temp;
}
void myDCLL::insertAtHead(int value) {
    Node* nn = new Node;
    nn->data = value;
    nn->prev = nullptr;
    nn->next = nullptr;

    if (tail == nullptr) {
        nn->next = nn;
        nn->prev = nn;
        tail = nn;
    }
    else {
        nn->next = tail->next;
        nn->prev = tail;
        tail->next->prev = nn;
        tail->next = nn;
    }
}
void myDCLL::insertAtTail(int value) {
    Node* nn = new Node;
    nn->data = value;
    nn->prev = nullptr;
    nn->next = nullptr;

    if (tail == nullptr) {
        nn->next = nn;
        nn->prev = nn;
        tail = nn;
    }
    else {
        nn->prev = tail;
        nn->next = tail->next;
        tail->next->prev = nn;
        tail->next = nn;
        tail = nn;
    }
}

void myDCLL::deleteFromTail() {
    if (tail == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }

    Node* temp = tail;

    if (temp->next == tail) {  // Only one node in the list
        tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = temp->next;
        temp->next->prev = tail;
    }

    delete temp;
}
void myDCLL::display() {
    if (tail == nullptr) {
        cout << "list is Empty." << endl;
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}
