/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        
        Node* pseudoHead= new Node(0,NULL, head, NULL);
        Node* curr;
        Node* prev = pseudoHead;
        stack<Node*> s;
        s.push(head);
        while(!s.empty())
        {
            curr=s.top();
            s.pop();
            prev->next=curr;
            curr->prev=prev;
            
            if(curr->next!=NULL)
            {
                s.push(curr->next);
            }
            if(curr->child!=NULL)
            {
                s.push(curr->child);
                curr->child=NULL;
            }
            
            prev=curr;
        }
        
        pseudoHead->next=NULL;
        head->prev=NULL;
        return head;
        
    }
};