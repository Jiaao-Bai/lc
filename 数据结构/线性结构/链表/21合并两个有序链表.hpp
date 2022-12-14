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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode new_head, *p = &new_head;
        while(l1!=nullptr||l2!=nullptr){
            if(l1==nullptr){
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                continue;
            }
            if(l2==nullptr){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
                continue;
            }
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
                p = p->next;        
            }else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        return new_head.next;
    }
};