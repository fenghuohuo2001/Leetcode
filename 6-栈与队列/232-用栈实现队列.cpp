// ��ջʵ�ֶ��еĸ��Ҳ���
/*
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false
*/
# include <stack>
using namespace std;

class MyQueue{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue(){

    }
    // ѹ��һ��Ԫ��
    void push(int x){
        stIn.push(x);
    }
    // ջ���Ƚ���������������Ƚ��ȳ�
    int pop(){
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());     // ��ջstIndջ����������һ��ջ��ջ��                                               stOut
                stIn.pop();                 // ��һ��ջ��
            }
        }
        int result = stOut.top();           // ȡ����ջ��ջ��
        stOut.pop();                        // ��ջջ��ˢ��
        return result;                      // ���ؽ��
    }

    // ���ڲ鿴ջ��Ԫ�أ��������䵯����
    // �����߼����Ƚ�ջ��Ԫ�ص�����Ȼ���ٽ����ƻ�ջ�У�������ջ��Ԫ�ص�ֵ��
    int peek(){
        int res = this->pop();
        stOut.push(res);
        return res;
    }


    // �ж��Ƿ�Ϊ��
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
        // ��stOutΪ��ʱ����������
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
        int res = this->pop();      // pop�Ǵ�stOut����
        stOut.push(res);
        return res;
    }

    bool empty(){
        return stIn.empty() && stOut.empty();
    }

};