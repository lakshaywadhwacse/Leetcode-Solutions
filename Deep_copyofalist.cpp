/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node * temp=head;
        while(temp!=NULL)
        {
            Node * n= new Node(temp->val);
            n->next=temp->next;
            temp->next=n;
            
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        
        temp=head;
        Node* new_tail=NULL;
        Node* new_head=NULL;
        while(temp!=NULL)
        {
            Node* copy=temp->next;
            if(new_head==NULL)
            {
                new_head=copy;
                new_tail=copy;
                temp->next=copy->next;
                copy->next=NULL;
            }
            else
            {
                temp->next=copy->next;
                copy->next=NULL;
                new_tail->next=copy;
                new_tail=copy;
                
            }
            temp=temp->next;
        }
        
        return new_head;
    }
};