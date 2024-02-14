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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode* temp=head;

        int c=1;
        //length 
        while(temp->next!=NULL){
               c++;
                temp=temp->next;   
            }
                ListNode* tail=temp;

        temp=head;
            if(k==c)
                return head;
        else if(k>c)
            k=k%c;
        int pos=c-k;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        
            tail->next=head;
        head=temp->next;
            temp->next=NULL;

        
        return head;
    }
};