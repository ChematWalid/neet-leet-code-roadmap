#include <iostream>
#include <vector>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        //the start of the sorted "merged" list is the head of the smaller list
        ListNode* head;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* curr = head;
        //compare and link the nodes ,
        //1-3-5
        //2-4-6 
        //curr will be in 1 , and l1 advances to 3 , then compare 3 and 2 , so curr's next is 2 and l2 advances to 4, so curr = 1-2
        // and l1 = 3, and l2 = 4 , and repeat
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        //one of the lists or both ended , so the next of curr is the one that didn't end , which is the rest of the list , if both ended , then that's nullptr
        curr->next = list1 ? list1 : list2;

        return head;
    }
    //this solution is O(n*k) where n is the average length of the lists and k is the number of lists , because we are merging k lists one by one , so we are traversing all the nodes in all the lists , which is n*k
    //but this isn't the most optimal
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int n = lists.size();
        for(int i = 1 ; i < n ; i++){
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }
};

int main(){
    return 0;
}