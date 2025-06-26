
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


 // Approach -1 : 

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        while (headA != NULL) {
            ListNode* temp = headB;
            while (temp != NULL) {
                if (headA == temp) return headA;
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;
    }


// Approach -2 : Set

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;

        while (headA != NULL) {
            st.insert(headA);
            headA = headA->next;
        }

        while (headB != NULL) {
            if (st.find(headB) != st.end()) return headB;
            headB = headB->next;
        }

        return NULL;
    }


// Approach - 3 : Constant Space 


ListNode* intersectionPresent3(ListNode* head1,ListNode* head2) {
 int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;


}

int getDifference(ListNode* head1,ListNode* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}


// Approach - 4 : 

ListNode *getIntersectionNode4(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }