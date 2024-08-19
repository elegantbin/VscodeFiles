// 从小到大排序；
// 交换数据时不能操作节点变量，而是交换节点中的数据；
// 第一步：将给定的数组 const int value[10] = {10, 35, 5, 20, 15, 4, 8, 71, 22, 12} 转换为单向链表；
// 第二步：对链表进行冒泡排序，并输出排序后的结果；
// 要求编译运行，输出正确的排序结果。
#include <stdio.h>
#include <stdlib.h>

// 定义单向链表节点
struct Node {
    int data;
    struct Node* next;
};

// 创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 将数组转换为单向链表
struct Node* arrayToLinkedList(const int arr[], int size) {
    struct Node* head = createNode(arr[0]);  // 创建头节点
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

// 冒泡排序实现（链表）
void bubbleSortLinkedList(struct Node* head) {
    if (head == NULL) return;

    struct Node* iNode;
    struct Node* jNode;
    int temp;

    for (iNode = head; iNode->next != NULL; iNode = iNode->next) {
        for (jNode = head; jNode->next != NULL; jNode = jNode->next) {
            if (jNode->data > jNode->next->data) {
                // 交换节点中的数据
                temp = jNode->data;
                jNode->data = jNode->next->data;
                jNode->next->data = temp;
            }
        }
    }
}

// 打印链表
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    const int value[10] = {10, 35, 5, 20, 15, 4, 8, 71, 22, 12};  // 数组

    // 第一步：将数组转换为单向链表
    struct Node* head = arrayToLinkedList(value, 10);

    // 第二步：对链表进行冒泡排序
    bubbleSortLinkedList(head);

    // 输出排序后的链表
    printf("排序后的链表为:\n");
    printLinkedList(head);

    return 0;
}
