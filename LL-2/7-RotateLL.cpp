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


int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int len = length(head);
        k = k % len;
        if (k == 0)
            return head;

        int stop = len - k - 1;
        ListNode* curr = head;
        for (int i = 0; i < stop; i++) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;

        ListNode* temp = newHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;
        return newHead;
    }