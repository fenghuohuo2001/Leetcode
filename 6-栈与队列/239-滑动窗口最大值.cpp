#include <vector>
#include <deque>
#include <iostream>
using namespace std;


// 使用队列解题
class Solution1 {
private:
    // 定义单调队列
    class MyQueue{
    public:
        deque<int> que;
        // 每次弹出时，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }

        // 若push的数值大于入口元素，则将队列后端的数值弹出，直到push的数值小于队列入口元素为止
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }

        // 查询当前队列里的最大值，直接返回队列前端也就是front就可以了
        int front(){
            return que.front(); 
        }

    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for(int i=0; i<k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k; i<nums.size(); i++){
            que.pop(nums[i-k]);     // 只有当弹出的为max时，才会执行弹出，否则函数无效
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};



class Solution{
private:
    class MyQueue{
    public:
        deque<int> que;

        void pop(int value){
            // 只有在queue非空和弹出的元素为最大元素时才执行
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }

        void push(int value){
            // 只有非空的时候，和大于最大元素时才执行  // 为什么使用front的时候会造成元素递增
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);       // 应该将小的元素放在back
        }

        int front(){
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        MyQueue que;
        vector<int> result;
        // 首先将队列填满到k
        for(int i=0; i<k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        // 当填满后，需要统计每次的result
        
        for(int i=k; i<nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}