
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


// ����������Ľ���ཻ֮ǰ�ǲ�һ�������ཻ���֮���Ϊһ����Ԫ��
// ע�⽻�㲻����ֵ��ȣ�����ָ�����
// �ҳ������������������ཻ����ʼ�ڵ�
class Solution{
public:
    template <typename T>
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        // ������A����
        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }
        // ������B����
        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        // ����ָ��ͷ������������ָ��
        curA = headA;
        curB = headB;

        // ��curA��Ϊ�������ָ�룬lenAΪ�䳤��
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // �󳤶�����ĳ��Ȳ�ֵ
        int gap = lenA - lenB;

        while(gap--){
            curA = curA->next;
        }

        // ����curA��curB��������ͬ����ֱ�ӷ���
        while(curA != nullptr){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};


class Solution{
public:
    template <typename T>
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        // ������������ָ��
        ListNode* curA = headA;
        ListNode* curB = headB;
        // ��������������
        int lenA = 0, lenB = 0;
        while(curA!=nullptr){
            lenA++;
            curA = curA->next;
        }
        while(curB!=nullptr){
            lenB++;
            curB = curB->next;
        }

        // ע�� ��ʱcurA��curB��ָ��������ĩβ��Ϊ��ʵ�ֱ�������Ҫ���¸�ֵָ��ͷ���
        curA = headA;
        curB = headB;

        // ��������ֵ��עΪA���̵�ΪB
        if(lenB > lenA){
            swap(lenA, lenB);
            swap(curA, curB);
        }
        
        // ���������Ȳ�ֵ
        int gap = lenA - lenB;

        // ʹcurA��curB����
        while(gap--){       // ����Ӧ����gap--
            curA = curA->next;
        }

        // ��ʼѰ���ཻ���
        while(curA!=nullptr){
            if(curA == curB){
                return curA;
            }
            // ����
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};