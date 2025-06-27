#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Appraoch -1 : Using Map

    Node* copyRandomList(Node* head) {
     unordered_map<Node*, Node*> mpp;
     Node* temp = head;
    
    while(temp != NULL){
    
        Node* newNode = new Node(temp->val);

        mpp[temp] = newNode;

        temp = temp->next;
    }
    
    temp = head;
  
    while(temp != NULL){
   
        Node* copyNode = mpp[temp];
        
        copyNode->next = mpp[temp->next];
     
        copyNode->random = mpp[temp->random];
     
        temp = temp->next;
    }
    
    return mpp[head];
}

// Approach -2 : 

