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
    // this uses 3 algorithms , find middle (which is easy) , reverse list , which is also easy ,but could be medium if no extra space , and merge which easy
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        //first find the half and store the prev of it so i can reverse everything after it
        ListNode* half = head;
        ListNode* prev = nullptr;
        ListNode* fastHalf = head;
        while(fastHalf && fastHalf->next){
            prev = half;
            half = half->next;
            fastHalf = fastHalf->next->next;
        }

        prev->next = nullptr; // make it null to disconnect the halfs so there will be no cycles (for example in 1-2-3-4-5 , if we do prev->next = reverseList(half) , 5->2 and 2->5)
        half = reverseList(half);
        ListNode* curr = head;
        ListNode* currNext = nullptr;
        ListNode* halfNext = nullptr;
        //From 1 2 3 4 -> 1 2 4 3 , half is 4
        //now we merge 
        bool firstTurn = true;
        while(curr && half){
            if(firstTurn){
                currNext = curr->next;
                curr->next = half;
                curr = currNext;
            }else{
                halfNext = half->next;
                half->next = curr;
                half = halfNext;
            }
            firstTurn = !firstTurn;
        }
    }
};




int main(){
    return 0;
}