#include <iostream>
#include <unordered_map>

using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapOldToNew;

        Node dummy(0);
        Node* currentNew = &dummy;
        Node* currentOriginal = head;

        while (currentOriginal != nullptr) {
            currentNew->next = new Node(currentOriginal->val);
            currentNew = currentNew->next;

            mapOldToNew[currentOriginal] = currentNew;

            currentOriginal = currentOriginal->next;
        }

        Node* copy = dummy.next;

        currentOriginal = head;
        currentNew = copy;

        while (currentOriginal != nullptr) {
            currentNew->random = (currentOriginal->random == nullptr)
                ? nullptr
                : mapOldToNew[currentOriginal->random];

            currentOriginal = currentOriginal->next;
            currentNew = currentNew->next;
        }

        return copy;
    }
};

int main(){
    return 0;
}