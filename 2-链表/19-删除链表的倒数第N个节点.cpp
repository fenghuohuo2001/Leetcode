

struct ListNode{
    int val;
    ListNode* next;
    ListNode (int x): val(x), next(nullptr){}
};

// 双指针牛B
// 定义fast指针和slow指针
// fast指针先移动n+1步，使fast和slow之间保证差距n
// 当fast移动到fast=null时，slow指向的val即为删除的val
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        // 先移动fast
        while(n-- && fast!= nullptr){
            fast = fast->next;
        }
        fast = fast->next;      // 需要slow指向待删除结点的上一个结点

        while(fast!= nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;  // 删除结点

        return dummyHead->next;
    }
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        // 设置虚拟头结点
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;

        // 设置快慢指针
        ListNode* slow = dummyhead;
        ListNode* fast = dummyhead;

        // 先将fast移动n步
        while(fast!=nullptr && n--){
            fast = fast->next;
        }
        fast = fast->next;

        // 再同时移动 fast 和 slow，将fast移动到末尾
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyhead->next;
    }
};