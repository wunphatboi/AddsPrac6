#ifndef NODE_H
#define NODE_H
class Node {
private:
int data;
Node* link;
public:
Node(int num);
friend class LinkedList;
};
#endif