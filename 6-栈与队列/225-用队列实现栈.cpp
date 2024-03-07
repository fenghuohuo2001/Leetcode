#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> queueIn;
    queue<int> queueOut;

    MyStack() {

    }
    
    void push(int x) {
        queueIn.push(x);
    }
    
    // 先进先出，在这里两个队列没有意义
    int pop() {
        // 将队列弹出到只剩一个元素
        int size = queueIn.size();
        size -= 1;
        while(size--){
            queueOut.push(queueIn.front());
            queueIn.pop();
        }
        int result = queueIn.front();
        queueIn.pop();
        queueIn = queueOut;
        while(!queueOut.empty()){
            queueOut.pop();
        }
        return result;
    }
    
    int top() {
        return queueIn.back();
    }

    
    bool empty() {
        return queueIn.empty();
    }
};