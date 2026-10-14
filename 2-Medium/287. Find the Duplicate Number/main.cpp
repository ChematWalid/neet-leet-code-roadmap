#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 , fast = 0;
        do{
            slow = nums[slow]; //kima slow = slow->next
            fast = nums[nums[fast]]; //kima fast = fast->next
        }while(slow != fast);
        //hadi t3tik bli kayn cycle
        //doka bash tjib el START t3 el cycle tdir hka
        //Don't ask me how tho 
        //mmb3d el start t3 el cycle hya el duplicate 
        //ana fhmt kifah wlat linked list cycle problem w g3 bs7 still problem mrnk
        int anotherSlow = 0;
        while(anotherSlow != slow){
            slow = nums[slow];
            anotherSlow = nums[anotherSlow];
        }
        return slow;
    }
};

int main(){
    return 0;
}