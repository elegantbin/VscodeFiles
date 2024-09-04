#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node {
    int data;
    struct Node* next;
};

// 创建一个新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 合并两个链表：A为升序，B为降序，合并为升序链表
struct Node* mergeLists(struct Node* A, struct Node* B) {
    struct Node* result = NULL;  // 合并后链表的头指针
    struct Node** lastPtrRef = &result;  // 指向结果链表最后一个节点的next指针

    // 反转链表B，使其变为升序
    struct Node* prev = NULL;
    struct Node* current = B;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    B = prev;

    // 合并链表A和反转后的链表B
    while (A != NULL && B != NULL) {
        if (A->data <= B->data) {
            *lastPtrRef = A;
            A = A->next;
        } else {
            *lastPtrRef = B;
            B = B->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    // 如果链表A还有剩余节点
    if (A != NULL) {
        *lastPtrRef = A;
    }

    // 如果链表B还有剩余节点
    if (B != NULL) {
        *lastPtrRef = B;
    }

    return result;
}

// 打印链表
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建链表A (升序)
    struct Node* A = createNode(1);
    A->next = createNode(3);
    A->next->next = createNode(5);

    // 创建链表B (降序)
    struct Node* B = createNode(10);
    B->next = createNode(6);
    B->next->next = createNode(2);

    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    // 合并链表
    struct Node* mergedList = mergeLists(A, B);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
