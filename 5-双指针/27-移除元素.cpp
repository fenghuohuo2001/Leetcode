#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 定义快慢指针
        int slow = 0;
        int fast = 0;
        // 当快指针等于val时，跳过，然后循环更新慢指针
        while(fast<nums.size()){
            if(nums[fast] == val){
                fast++;
            }else{
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }

        // 当快指针不等于val时，更新慢指针
        // while(fast<nums.size()){
        //     if(nums[fast] != val){
        //         nums[slow] = nums[fast];
        //         slow++;
        //     }
        //     fast++;
        // }
        return slow;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 定义快慢指针
        int slow = 0;
        int fast = 0;
        // 当快指针等于val时，跳过，然后循环更新慢指针
        while(fast<nums.size()){
            if(nums[fast] == val){
                fast++;
            }else{
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};


int main(){
    int val = 3;
    vector<int> nums = {3, 2, 2, 3};
    Solution sol;
    int size = sol.removeElement(nums, val);
    cout << size << endl;
    cout << "nums: ";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }    
    cout << endl;
    return 0;
}