/*
2020.5.14
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pResult = new ListNode;
        ListNode *pCurrentNum =pResult;
        int carryBit = 0;

        while(l1!=NULL||l2!=NULL||carryBit!=0){

            pCurrentNum->next = new ListNode;
            pCurrentNum = pCurrentNum->next;
            
            if(l1!=NULL){
                pCurrentNum->val += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                pCurrentNum->val += l2->val;
                l2 = l2->next;
            }
            if(carryBit!=0){
                pCurrentNum->val += carryBit;
                carryBit = 0;
            }

            if(pCurrentNum->val >= 10){
                pCurrentNum->val -= 10;
                carryBit = 1;
            }
        }
        pCurrentNum->next = NULL;
        pCurrentNum = pResult->next;
        delete(pResult);
        return pCurrentNum;
    }
};