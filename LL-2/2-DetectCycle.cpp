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


// Approach - 1 : Hashing

bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, int> mp;
        ListNode* temp = head;

        while (temp != NULL) {
            if (mp.find(temp) != mp.end()) 
                return true;
            
            mp[temp] = 1;
            
            temp = temp->next;
        }

        return false;
    }

// Approach - 2 : Floyd's Cycle Detection / Fast Slow Method : 

bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }

        return false;

    }

