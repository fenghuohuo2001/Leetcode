/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// ����������
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

// ����˫ָ�뷨��һ��curָ��ָ��ͷ��㣬һ��pre��ʼ��ΪNULL
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

// �ݹ鷨
class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // ���Ժ�˫ָ�뷨�Ĵ�����жԱȣ����µݹ��д������ʵ��������������
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);   // �ƶ�����һ�����
    }
    ListNode* reverseList(ListNode* head) {
        // ��˫ָ�뷨��ʼ����һ�����߼�
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(nullptr, head);
    }

};

// �ݹ鷨 ��curΪ��ʱ��ѭ������
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ��Ե�����ж�
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        // �ݹ���ã���ת�ڶ�����㿪ʼ���������ע�������кܶ��ݹ����
        ListNode* last = reverseList(head->next);   
        // �ݹ麯������ʱ�����������������ڵ���2ʱ���˳����һ��ݹ����ʱ���ص����������һ�����
        
        // ��תͷ���͵ڶ�������ָ��
        head->next->next = head;
        // ��ʱhead���Ϊβ��㣬next��Ҫָ��nullptr
        head->next = nullptr;
        return last;
    }
};


class Solution{
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        // ������ĩβ
        if(cur == nullptr) return pre;
        // �ݴ���һ���������
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    ListNode* resverseList(ListNode* head){
        return reverse(nullptr, head);
    }
};