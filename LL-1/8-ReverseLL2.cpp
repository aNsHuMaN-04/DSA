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


ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        // 1. Move curr to the 'left' position
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        // 2. Store connections
        ListNode* leftPrev = prev;   // Node before 'left'
        ListNode* leftNode = curr;   // Node at position 'left'

        // 3. Reverse the sublist
        ListNode* next = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 4. Reconnect the reversed part
        if (leftPrev) {
            leftPrev->next = prev;
        } else {
            head = prev; // If reversing starts at head
        }

        leftNode->next = curr;
        return head;
    }