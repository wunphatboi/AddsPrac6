#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
};

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;
    for (int i = 0; i < len; i++) {
        insertPosition(i+1, array[i]);
        }
};

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->link;
        delete temp;
        }
};

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (head == nullptr || pos <= 1) {
        newNode->link = head;
        head = newNode;
        } else {
            Node* curr = head;
            int i = 1;
            while (curr->link != nullptr && i < pos - 1) {
                curr = curr->link;
                i++;
            }
            newNode->link = curr->link;
            curr->link = newNode;
            }
};

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos < 1) {
        return false;
    } else if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
        } else {
            Node* curr = head;
            int i = 1;
            while (curr->link != nullptr && i < pos - 1) {
                curr = curr->link;
                i++;
            }
            if (curr->link == nullptr) {
                return false;
            } else {
                Node* temp = curr->link;
                curr->link = temp->link;
                delete temp;
                return true;
                }
            }
};

int LinkedList::get(int pos) {
    if (head == nullptr || pos < 1) {
        return std::numeric_limits<int>::max();
    } else {
    Node* curr = head;
    int i = 1;
    while (curr != nullptr && i < pos) {
        curr = curr->link;
        i++;
    }
    if (curr == nullptr) {
    return std::numeric_limits<int>::max();
    } else {
    return curr->data;
 }}
};

int LinkedList::search(int target) {
    Node* curr = head;
    int pos = 1;
    while (curr != nullptr) {
    if (curr->data == target) {
    return pos;
    }
    curr = curr->link;
    pos++;
}
return -1;
};

void LinkedList::printList() {
std::cout << "[";
Node* curr = head;
while (curr != nullptr) {
std::cout << curr->data;
if (curr->link != nullptr) {
                    std::cout << " ";
                }
curr = curr->link;
}
std::cout << "]" << std::endl;
};