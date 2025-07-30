// Rearrange such that all nodes smaller than x and values bigger than x appear before x

#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
  
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 // Approach -1 : Making new Nodes

 ListNode* partition(ListNode* head, int x) {

        if (head == NULL)
            return NULL;

        ListNode* curr = head;
        ListNode* head1 = new ListNode(-1);
        ListNode* curr1 = head1;
        ListNode* head2 = new ListNode(-1);
        ListNode* curr2 = head2;
        while(curr != NULL)
        {
            if(curr->val < x)
             {
             curr1->next = new ListNode(curr->val); 
             curr1 = curr1->next;
             }

             else
             {
                curr2->next = new ListNode(curr->val);
                curr2 = curr2->next;
             }
             curr = curr->next;
        }

        curr1->next = head2->next;
        return head1->next;
        
    }

    // Approach -2 : Rearrange Links
    

     ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode* head1 = new ListNode(-1); 
        ListNode* curr1 = head1;
        ListNode* head2 = new ListNode(-1); 
        ListNode* curr2 = head2;

        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->val < x) {
                curr1->next = curr;
                curr1 = curr1->next;
            } else {
                curr2->next = curr;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

       
        curr2->next = NULL;

        
        curr1->next = head2->next;

        return head1->next;
    }