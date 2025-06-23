#include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
// If two Middle , this gives the 2nd one

    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

// If two middle this gives the 1st one

   ListNode* middleNode1(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
    }

        if (fast->next->next == NULL)
            fast = fast->next;
   }