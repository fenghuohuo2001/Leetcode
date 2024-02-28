struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    template <typename T>
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    ListNode* detectCycle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;          // slow��һ��
            fast = fast->next->next;    // fast������

            // ����ָ����������ʱ��head�������㣬ͬʱ���ң�ֱ������
            if(slow == fast){
                // ���������ͷ��㽨��ָ��
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;      // �����
            }
        }
        return nullptr;
    }
};

class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        // �ȶ������ָ��
        ListNode* fast = head;
        ListNode* slow = head;

        // ���ж���û�л������Ƚ����������ų�������������б��������������һ�����
        while(fast!= nullptr && fast->next!=nullptr){
            // ����ָ����Ҫ�˶�
            slow = slow->next;
            fast = fast->next->next;

            // ������ָ�����ʱ����Ϊ�������
            if(fast == slow){
                // ��ͷ����������㴴������ָ��
                ListNode* index1 = fast;
                ListNode* index2 = head;
                // �������������е�����������ָ��������ʱ�򣬴�ͷ��������index2��Ϊ�����
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};