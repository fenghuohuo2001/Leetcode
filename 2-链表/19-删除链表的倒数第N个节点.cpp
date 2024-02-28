

struct ListNode{
    int val;
    ListNode* next;
    ListNode (int x): val(x), next(nullptr){}
};

// ˫ָ��ţB
// ����fastָ���slowָ��
// fastָ�����ƶ�n+1����ʹfast��slow֮�䱣֤���n
// ��fast�ƶ���fast=nullʱ��slowָ���val��Ϊɾ����val
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        // ���ƶ�fast
        while(n-- && fast!= nullptr){
            fast = fast->next;
        }
        fast = fast->next;      // ��Ҫslowָ���ɾ��������һ�����

        while(fast!= nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;  // ɾ�����

        return dummyHead->next;
    }
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        // ��������ͷ���
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;

        // ���ÿ���ָ��
        ListNode* slow = dummyhead;
        ListNode* fast = dummyhead;

        // �Ƚ�fast�ƶ�n��
        while(fast!=nullptr && n--){
            fast = fast->next;
        }
        fast = fast->next;

        // ��ͬʱ�ƶ� fast �� slow����fast�ƶ���ĩβ
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyhead->next;
    }
};