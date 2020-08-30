/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 1st method of solving these question.....
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head==NULL)return head;
//         if(head->next==NULL and n==1) return NULL;
//         int size=0;
//         ListNode* newhead=head;
//         while(newhead!=NULL)
//         {
//             size++;
//             newhead=newhead->next;  
//         }
//         if(size==n)
//         {
//             head=head->next;
//             head->next==NULL;
//             return head;
//         }
//         ListNode*slow=head;
//         ListNode*fast=head;
//         ListNode*prev=NULL;
//         int k=n;
//         while(k--)
//         {
//             fast=fast->next; 
//         }
        
//         while(fast!=NULL)
//         {
//             prev=slow;
//             slow=slow->next;
//             fast=fast->next;
//         }
        
//         prev->next=slow->next;
//         slow->next=NULL;
//         return head;
       
//     }
// };


// 2nd method of solving the question is..............
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return head;
        if(head->next==NULL and n==1) return NULL;
        int size=0;
        ListNode* newhead=head;
        while(newhead!=NULL)
        {
            size++;
            newhead=newhead->next;  
        }
        if(size==n)
        {
            head=head->next;
           // head->next==NULL;
            return head;
        }
        ListNode* slow=head;
        ListNode* fast= head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* temp=slow->next;

        slow->next=slow->next->next;
        delete temp;
    }
};