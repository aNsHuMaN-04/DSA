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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == NULL) {
                if (prevLast != NULL)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;

            ListNode* newHead = reverseLinkedList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }


        ListNode* getKthNode(ListNode* temp, int k) {
        k--;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
