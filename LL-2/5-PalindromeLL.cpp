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


 // Approach - 1 : Stack 

 bool isPalindrome1(ListNode* head) {

stack<int> st;

    ListNode* temp = head;

    while (temp != NULL) {
        
    
        st.push(temp->val); 
        
   
        temp = temp->next;  
    }

    temp = head;

    while (temp != NULL) {
        if (temp->val != st.top()) {
            
          
            return false; 
        }
        
      
        st.pop();         
        
        temp = temp->next; 
    }
    return true;
        
    }


// Appraoch - 2 : 


     ListNode* reverseList(ListNode* head) {
        
        ListNode* curr=head;
        ListNode* prev=NULL;  

        while(curr!=NULL)
        {
           ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }   
    return prev;    
    }

    
    bool isPalindrome2(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseList(newHead);
        return true;
    }