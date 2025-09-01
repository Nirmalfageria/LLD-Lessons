#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRU{

    int capacity;
    class Node{
        public:
        int key ;
        int value;
        Node* head;
        Node* tail;

        Node(int k ,int v){
            key =k;
            value = v;
            head = NULL;
            prev = NULL;
        }
    };

    unordered_map<int,Node*>m;
Node* head;
Node* tail;
    void addnode(Node* node){
        node->next = head;
        head->prev = node;
        head = node;
    }

    void removenode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
      
    }
void movehead(Node* node){
    removenode(node);
addnode(node);
}

Node* poptail(){
    Node * prev = tail->prev;
    removenode(tail);
    return prev;
}
public:

LRU(int cap){
capacity = cap;
head = new Node(0,0);
tail = new Node(0,0);
head->next = tail;
tail->prev = head;
}

int get(int key){
    
}
};