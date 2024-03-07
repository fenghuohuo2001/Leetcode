#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // �������ָ��
        int slow = 0;
        int fast = 0;
        // ����ָ�����valʱ��������Ȼ��ѭ��������ָ��
        while(fast<nums.size()){
            if(nums[fast] == val){
                fast++;
            }else{
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }

        // ����ָ�벻����valʱ��������ָ��
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
        // �������ָ��
        int slow = 0;
        int fast = 0;
        // ����ָ�����valʱ��������Ȼ��ѭ��������ָ��
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