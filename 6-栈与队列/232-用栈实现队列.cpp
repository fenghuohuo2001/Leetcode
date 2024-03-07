// 用栈实现队列的各找操作
/*
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
*/
# include <stack>
using namespace std;

class MyQueue{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue(){

    }
    // 压入一个元素
    void push(int x){
        stIn.push(x);
    }
    // 栈是先进后出，而队列是先进先出
    int pop(){
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());     // 将栈stInd栈顶放入另外一个栈的栈底                                               stOut
                stIn.pop();                 // 下一个栈顶
            }
        }
        int result = stOut.top();           // 取出出栈的栈顶
        stOut.pop();                        // 出栈栈顶刷新
        return result;                      // 返回结果
    }

    // 用于查看栈顶元素，但不将其弹出。
    // 它的逻辑是先将栈顶元素弹出，然后再将其推回栈中，并返回栈顶元素的值。
    int peek(){
        int res = this->pop();
        stOut.push(res);
        return res;
    }


    // 判断是否为空
    bool empty(){
        return stIn.empty() && stOut.empty();
    }

};



class MyQueue{
public: 
    stack<int> stIn;
    stack<int> stOut;

    MyQueue(){}

    void push(int x){
        stIn.push(x);
    }

    int pop(){
        // 当stOut为空时，导出数据
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek(){
        int res = this->pop();      // pop是从stOut弹出
        stOut.push(res);
        return res;
    }

    bool empty(){
        return stIn.empty() && stOut.empty();
    }

};