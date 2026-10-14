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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    //since recommended time comlexity is O(n) , then my first intuition is to reverse , remove , then reverse again
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);
        ListNode* prev = nullptr;
        
    }
};

int main(){
    return 0;
}