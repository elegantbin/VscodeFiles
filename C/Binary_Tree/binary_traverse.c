#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct TreeNode{
    ElemType val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

//前序遍历的递归算法
void Preorder_re(TreeNode* node, ElemType* array, int* returnSize){
    if(node == NULL) return;
    array[(*returnSize)++] = node->val;
    Preorder_re(node->left, array, returnSize);
    Preorder_re(node->right, array, returnSize);
}
ElemType* Preorder(TreeNode* root,ElemType* returnSize){
    ElemType *array = (ElemType*)malloc(sizeof(ElemType)*2000);
    *returnSize = 0;
    Preorder_re(root,array,returnSize);
    return array;
}

//前序遍历的迭代算法
ElemType* preorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode Node;
    ElemType* array = (ElemType*)malloc(sizeof(ElemType)*100);
    *returnSize = 0;
    Node **stack = malloc(sizeof(Node*)*100);
    // Node *stack[100];
    int top = 0;
    Node *cur = root;
    while(cur || top > 0){
        if(cur){
            array[(*returnSize)++] = cur->val;
            stack[top++] = cur;
            cur = cur->left;
        }
        else{
            cur = stack[--top];
            cur = cur->right;
        }
    }
    return array;
}

//中序遍历的迭代方法
ElemType* inorderTraversal(struct TreeNode* root, int* returnSize) {
    ElemType* res = malloc(2000*sizeof(ElemType));
    *returnSize = 0;
    int top = 0;
    struct TreeNode *stk[2000];
    struct TreeNode *p = root;
    if(p == NULL) return res;
    
    while(p != NULL || top>0){
        if(p){
            stk[top++] = p;
            p = p->left;
        }
        else{
            p = stk[--top];
            res[(*returnSize)++] = p->val;
            p = p->right;
        }
    }
    
    return res;
}

//后序遍历的迭代方法
ElemType* postorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode Node;
    ElemType* array = (ElemType*)malloc(sizeof(ElemType)*100);
    *returnSize = 0;
    Node **stack = malloc(sizeof(Node*)*100);
    int top = 0;
    Node *cur = root;
    Node *pre = NULL;
    while(cur || top > 0){
        while(cur != NULL){
            stack[top++] = cur;
            cur = cur->left;
        }

        cur = stack[--top];

        if(cur->right == NULL || cur->right == pre){
            array[(*returnSize)++] = cur->val;
            pre = cur;
            cur = NULL;
        }
        else{
            stack[top++] = cur;
            cur = cur->right;
        }
    }
    return array;
}

//创建一个结点
TreeNode* BuyNode(ElemType x){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if(node == NULL) exit(0);
    node->val = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//创建一棵简易二叉树
TreeNode* creatTree(void){
    TreeNode* node1 = BuyNode(1);
    TreeNode* node2 = BuyNode(2);
    TreeNode* node3 = BuyNode(3);
    TreeNode* node4 = BuyNode(4);
    TreeNode* node5 = BuyNode(5);
    TreeNode* node6 = BuyNode(6);
    TreeNode* node7 = BuyNode(7);

    node1->left = node2;
    node2->left = node3;
    node2->right = node4;
    node4->left = node5;
    node4->right = node7;
    node5->right = node6;

    return node1;
}

//前序递归创建二叉树
TreeNode* createBiTree_recru(void){
    int val;
    TreeNode* root;
    scanf("%d",&val);
    if(val == -1){
        root = NULL;
    }else{
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
        if(root == NULL)  exit(0);
        root->val = val;
        root->left = createBiTree_recru();
        root->right = createBiTree_recru();
    }
    return root;
}

//后序遍历释放二叉树节点内存
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    printf("创建一个二叉树:\n");
    TreeNode* root = creatTree();
    int arraySize = 0;

    printf("前序遍历一个二叉树:\t");
    int* array1 = preorderTraversal(root, &arraySize);
    for(int i = 0; i < arraySize; i++){
        printf("%d ", array1[i]);
    }
    printf("\n");

    printf("中序遍历一个二叉树:\t");
    int* array2 = inorderTraversal(root, &arraySize);
    for(int i = 0; i < arraySize; i++){
        printf("%d ", array2[i]);
    }
    printf("\n");

    printf("后序遍历一个二叉树:\t");
    int* array3 = postorderTraversal(root, &arraySize);
    for(int i = 0; i < arraySize; i++){
        printf("%d ", array3[i]);
    }
    printf("\n");

    free(array1);
    free(array2);
    free(array3);
    freeTree(root);

    return 0;
}