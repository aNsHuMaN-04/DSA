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
 
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        
        ListNode* head = NULL;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        
        ListNode* curr = head;

       
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

      
        if (list1 != NULL) curr->next = list1;
        if (list2 != NULL) curr->next = list2;

        return head;
    }