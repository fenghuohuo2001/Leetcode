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
            slow = slow->next;          // slow走一步
            fast = fast->next->next;    // fast走两步

            // 快慢指针相遇，此时从head和相遇点，同时查找，直到相遇
            if(slow == fast){
                // 在相遇点和头结点建立指针
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;      // 环入口
            }
        }
        return nullptr;
    }
};

class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        // 先定义快慢指针
        ListNode* fast = head;
        ListNode* slow = head;

        // 先判断有没有环，首先将单结点情况排除，随后对链表进行遍历，遍历到最后一个结点
        while(fast!= nullptr && fast->next!=nullptr){
            // 快慢指针需要运动
            slow = slow->next;
            fast = fast->next->next;

            // 当快慢指针相等时，即为相遇结点
            if(fast == slow){
                // 在头结点和相遇结点创建两个指针
                ListNode* index1 = fast;
                ListNode* index2 = head;
                // 对这两个结点进行迭代，当两个指针相遇的时候，从头结点出发的index2即为环入口
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