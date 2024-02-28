#include <iostream>

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 逐个赋值链表节点
void assignList(ListNode* head, int* arr, int n) {
    if (n == 0) 
        return;
    head->val = *arr;
    if (n > 1) {
        head->next = new ListNode(0);
        // 由于数组是连续存储的变量，因此在地址上+1就是指向下一个数组元素
        assignList(head->next, arr + 1, n - 1);
    }
}

// 打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 创建链表头节点
    ListNode* head = new ListNode(0);

    // 逐个赋值链表节点
    assignList(head, arr, n);

    // 打印链表
    std::cout << "链表初始值：" << std::endl;
    printList(head);

    return 0;
}
