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

 int getLength(ListNode* head) {
        int n = 0;
        while (head != NULL) {
            n++;
            head = head->next;
        }
        return n;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, NULL);

        int n = getLength(head);
        int baseSize = n / k;
        int extra = n % k;

        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (curr == NULL) {
                result[i] = NULL;
                continue;
            }

            result[i] = curr;
            int partSize = baseSize + (extra > 0 ? 1 : 0);
            if (extra > 0) extra--;

            for (int j = 1; j < partSize; j++) {
                if (curr != NULL) curr = curr->next;
            }

            if (curr != NULL) {
                ListNode* nextPart = curr->next;
                curr->next = NULL;
                curr = nextPart;
            }
        }

        return result;
    }