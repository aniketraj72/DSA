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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = NULL;
    ListNode *temp = NULL;
    int carry = 0;
     while(l1 != NULL  || l2 != NULL) {
        int sum = (l1 ? l1->val: 0 )+ (l2 ? l2 -> val : 0);
        if(res == NULL) {
            res= new ListNode(sum%10); 
            temp = res; 
            carry = sum / 10;
            }
        else { 
                sum += carry;
                ListNode *t;
                t = new ListNode(sum % 10);
                carry = sum / 10;
                temp -> next = t;
                temp = temp->next;
        }
        if(carry) {
            ListNode *t;
            t = new ListNode(carry);
            temp->next = t;
        }
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
     } 
    return res;
    }
};