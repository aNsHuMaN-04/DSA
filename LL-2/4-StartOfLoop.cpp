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

// Aproach - 1 : Using Hashing

  ListNode *detectCycle1(ListNode *head) {
        
    ListNode* temp = head;
    
    unordered_map<ListNode*, int> mp;
    
    while(temp!=NULL){
    
        if(mp.count(temp)!=0){ // we don't use mp[temp] != 0 becuz if it is !=0 then it inserts it 
                               // Therefore for check we always use .count
            return temp;
        }
    
        mp[temp] ++;
        temp = temp->next;
    
    }

    return NULL; 
}


// Approach -2 : Floyd's Method / Fast Slow Method

ListNode* hasCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return slow;    // or return fast (same thing) just return the Intersection Point
        }

        return NULL;

}

ListNode *detectCycle(ListNode *head) 
{
        ListNode* slow = head;
        ListNode* fast = hasCycle(head); // Initiate fast with the intersection point
        

    if(fast == NULL)   // No Loop
    return NULL;
   
   while(slow != fast)
   {
    slow = slow->next;
    fast = fast->next;
   }
  
return slow; // or return fast
}
