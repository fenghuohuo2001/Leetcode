#include <vector>
#include <deque>
#include <iostream>
using namespace std;


// ʹ�ö��н���
class Solution1 {
private:
    // ���嵥������
    class MyQueue{
    public:
        deque<int> que;
        // ÿ�ε���ʱ���Ƚϵ�ǰҪ��������ֵ�Ƿ���ڶ��г���Ԫ�ص���ֵ���������򵯳�
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }

        // ��push����ֵ�������Ԫ�أ��򽫶��к�˵���ֵ������ֱ��push����ֵС�ڶ������Ԫ��Ϊֹ
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }

        // ��ѯ��ǰ����������ֵ��ֱ�ӷ��ض���ǰ��Ҳ����front�Ϳ�����
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
            que.pop(nums[i-k]);     // ֻ�е�������Ϊmaxʱ���Ż�ִ�е�������������Ч
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
            // ֻ����queue�ǿպ͵�����Ԫ��Ϊ���Ԫ��ʱ��ִ��
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }

        void push(int value){
            // ֻ�зǿյ�ʱ�򣬺ʹ������Ԫ��ʱ��ִ��  // Ϊʲôʹ��front��ʱ������Ԫ�ص���
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);       // Ӧ�ý�С��Ԫ�ط���back
        }

        int front(){
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        MyQueue que;
        vector<int> result;
        // ���Ƚ�����������k
        for(int i=0; i<k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        // ����������Ҫͳ��ÿ�ε�result
        
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