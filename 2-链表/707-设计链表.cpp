#include <stdio.h>
#include <iostream>


// ������
struct ListNode {
    int val;  // �ڵ��ϴ洢��Ԫ��
    ListNode *next;  // ָ����һ���ڵ��ָ��
    ListNode(int x) : val(x), next(NULL) {}  // �ڵ�Ĺ��캯��
};

class MyLinkedList {
public:
    // ��������ṹ��
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr){}
    };

    // ��ʼ������
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    // ��ȡ��index�������ֵ
    int get(int index) {
        if(index > (_size -1) || index < 0){
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    // ��������ǰ�����һ�����
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;           // ע�⣬����������Ǿ���һ������ͷ����
        _dummyHead->next = newNode;
        _size++;
    }
    
    // ������ĩβ���һ�����
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    // �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
    // ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
    // ���index��������ĳ��ȣ��򷵻ؿ�
    // ���indexС��0������ͷ������ڵ�
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        // ����index��Ӧλ��
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;      // �����½��
        cur->next = newNode;
        _size++;
    }
    // ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0){
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //delete����ָʾ�ͷ���tmpָ��ԭ����ָ���ǲ����ڴ棬
        //��delete���ָ��tmp��ֵ����ַ�����Ǿ���NULL���������ֵ��Ҳ���Ǳ�delete��
        //������ټ���һ��tmp=nullptr,tmp���Ϊ��ָ��Ұָ��
        //���֮��ĳ���С��ʹ����tmp����ָ������Ԥ����ڴ�ռ�
        tmp = nullptr;
        _size--;
    }

    void printLinkedList(){
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */