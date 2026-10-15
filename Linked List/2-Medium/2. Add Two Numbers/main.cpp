#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //2 solutions , convert to int and sum then back to list , or add inplace
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* currentResult = &dummy;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            currentResult->next = new ListNode(sum % 10);
            currentResult = currentResult->next;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(!l2 && l1){
            int sum = l1->val + carry;
            currentResult->next = new ListNode(sum % 10);
            currentResult = currentResult->next;
            carry = sum / 10;
            l1 = l1->next;
        }
        while(!l1 && l2){
            int sum = l2->val + carry;
            currentResult->next = new ListNode(sum % 10);
            currentResult = currentResult->next;
            carry = sum / 10;
            l2 = l2->next;
        }
        if(carry != 0){
            currentResult->next = new ListNode(carry);
        }
        return dummy.next;
    }
};


int main(){
    return 0;
}