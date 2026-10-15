#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //i noticed that this and the previous problem use easy problems as a helper function to solve the hard
    ListNode* reverseList(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;

        while (curr != nullptr && count < k) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        int count = 0;
        //count the number of nodes in the list
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }

        curr = head;
        //while there are at least k nodes left to reverse
        while (count >= k) {
            //find the node after the current group
            next = curr;
            for (int i = 0; i < k; i++) {
                next = next->next;
            }

            //reverse the next k nodes
            ListNode* newHead = reverseList(curr, k);

            //connect the previous part of the list to the reversed part
            if (prev != nullptr) {
                prev->next = newHead;
            } else {
                head = newHead;
            }

            //move prev to the end of the reversed part
            prev = curr;

            //move curr to the next part of the list
            curr = next;
            count -= k;
        }

        //connect the last part of the list that is less than k nodes to the end of the reversed part
        if (prev != nullptr) {
            prev->next = curr;
        }

        return head;
    }
};

int main(){
    return 0;
}