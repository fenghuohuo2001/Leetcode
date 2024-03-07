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
    
    // �Ƚ��ȳ�����������������û������
    int pop() {
        // �����е�����ֻʣһ��Ԫ��
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