#include <stdio.h>

// ������
struct ListNode {
    int val;  // �ڵ��ϴ洢��Ԫ��
    ListNode *next;  // ָ����һ���ڵ��ָ��
    ListNode(int x) : val(x), next(NULL) {}  // �ڵ�Ĺ��캯��
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){  // head��һ������
        // ɾ��ͷ��㣬����ͷָ��Ϊ�յļ�Ϊͷ�ڵ�
        while(head != NULL && head->val == val){    // ����ͷָ�� head ��Ϊ����ͷ�ڵ��ֵ����Ŀ��ֵ val��
        //head != NULL: ȷ������û�б����꣬���������ڽڵ㡣
        //head->val == val: ��鵱ǰͷ�ڵ��ֵ�Ƿ����Ŀ��ֵ val��
            ListNode* tmp = head;       // ����һ����ʱָ�� tmp��ָ��ǰҪɾ���Ľڵ㣨ͷ�ڵ㣩��
            head = head->next;          // ��ͷָ�� head ָ����һ���ڵ㣬����ͷ�ڵ���������Ƴ���
            delete tmp;                 // ɾ����ʱָ�� tmp ָ��Ľڵ㣬��ɾ��֮ǰ��ͷ�ڵ㣬�ͷ��ڴ�ռ䡣
        }

        // ɾ����ͷ���
        ListNode* cur = head;
        while(cur != NULL && cur->next!=NULL){      // ��ǰ����Ϊ�գ�����һ���ڵ�Ҳ��Ϊ��
            if(cur->next->val == val){      // �жϵ�ǰ�ڵ����һ���ڵ��ֵ�Ƿ����Ŀ��ֵ val��
                ListNode* tmp = cur->next;  // ����һ����ʱָ�� tmp��ָ��ǰ�ڵ����һ���ڵ㣨��Ҫɾ���Ľڵ㣩��
                cur->next = cur->next->next;    //  ����ǰ�ڵ�� next ָ��ָ�����¸��ڵ㣬������ǰ�ڵ����һ���ڵ���������Ƴ���
                delete tmp;     //  ����ǰ�ڵ�� next ָ��ָ�����¸��ڵ㣬������ǰ�ڵ����һ���ڵ���������Ƴ���
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};
/*
�����������У�ʹ�� tmp ��Ϊ����ʱ����Ҫɾ���Ľڵ㣬Ȼ���ٽ�����������Ƴ���
��������ԭ���ǣ���ɾ���ڵ�ʱ��������Ҫȷ������ʧ������ķ��ʣ�����ᵼ���ڴ�й©���߶�����������ִ���

���費ʹ�� tmp��ֱ�ӽ� cur->next ��ֵΪ cur->next->next��
Ȼ��ɾ�� cur->next �ڵ㡣�����ᵼ�������жϣ���ʧ�˶���һ���ڵ��ָ�룬
������ɾ���ڵ���޷�����������һ���ڵ㣬��Ϊ cur->next �Ѿ����޸��ˡ�

ʹ�� tmp ���Ա����������������ʱ������Ҫɾ���Ľڵ㣬
*** ���Ҵ��ڴ��н�ԭ�и�ֵ���ı���ռ�õ��ڴ��ַ��� ***
Ȼ����ɾ��������Ӱ������������ԺͶ�����ı���������
*/

// ����һ������ͷ������Ƴ��ڵ����
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
            head = dummyHead->next;
            delete dummyHead;
            return head;
        }
    }
};



// 2024-2-22 �ֶ�ʵ��
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val){
        // �½�һ������ͷ���
        ListNode* dummyHead = new ListNode(0);
        // ������ͷ������ԭ������λ
        dummyHead->next = head;
        // �½�һ������ current
        ListNode* cur = dummyHead;
        // ѭ������������ĩβ
        while(cur->next != NULL){
            // ����һ������ֵΪĿ��ֵ
            if(cur->next->val == val)
            {
                // �Ƚ���һ�����ĵ�ַȡ�������ں���ɾ��
                ListNode* tmp = cur->next;
                // ����ǰ����������¸����
                cur->next = cur->next->next;
                // �ͷ���ɾ�������ڴ�ռ�
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        // ɾ������ͷ���
        head = dummyHead->next;
        // �ͷ�����ͷ����ڴ�ռ�
        delete dummyHead;
        // ��������
        return head;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val){
        // �½�һ������ͷ���
        ListNode* dummyHead = new ListNode(5);
        // ������ͷ������ԭ������λ
        dummyHead->next = head;
        // �½�һ������ current
        ListNode* cur = dummyHead;
        // ѭ������������ĩβ
        while(cur->next != nullptr){
            // ����һ������ֵΪĿ��ֵ
            if(cur->next->val == val){
                // �Ƚ���һ�����ĵ�ַȡ�������ں���ɾ��
                ListNode* tmp = cur->next;
                // ����ǰ����������¸����
                cur->next = cur->next->next;
                // �ͷ���ɾ�������ڴ�ռ�
                delete tmp;
            }
            else{
                //����һ��㲻ΪĿ��ֵ
                cur = cur->next;
            }
        }
        // ɾ������ͷ���
        head = dummyHead->next;
        // �ͷ�����ͷ����ڴ�ռ�
        delete dummyHead;
        // ��������
        return head;
    }
};
