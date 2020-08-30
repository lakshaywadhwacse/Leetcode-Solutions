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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head==NULL || head->next==NULL) return head;
//         ListNode* newhead=swapPairs(head->next->next);
//         ListNode* temp= head->next;
//         temp->next=head;
//         head->next=newhead;
//         return temp;
//     }
// };

// 2nd method....................
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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head==NULL) return NULL;
//         if(head->next==NULL) return head;
//         ListNode* first=head;
//         ListNode*  second=head->next;
//         while(first and second)
//         {
//             if(second!=NULL)
//             {
//                  int t= first->val;
//                  first->val=second->val;
//                  second->val=t;
                
//             }
           
            
//             if(second->next!=NULL)
//             {
//                 first=first->next->next;
//                 second=second->next->next;
//             }
//             else
//             {
//                 second=second->next;
//             }
            
//         }
        
//         return head;
          
//     }
// };