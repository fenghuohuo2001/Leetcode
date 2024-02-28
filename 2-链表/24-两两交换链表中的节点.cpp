
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


// ��ʵ�����������ĸ�Ԫ����Ϊһ�飬����������������㽻��
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        // ��������ͷ���
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next;
            ListNode* tmp1= cur->next->next->next;

            cur->next = cur->next->next;        // ��������ͷ���ָ��
            cur->next->next = tmp;              // ���µڶ�����㣨2��ָ��1��
            cur->next->next->next = tmp1;       // ���µ�һ����㣨1��ָ��3��

            cur = cur->next->next;              // ���µ�curָ����һ����������
        }

        return dummyHead->next;
    }

};