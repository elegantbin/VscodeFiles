// 题目描述: 二叉树中的 路径 被定义为一条节点序列，列中每对相邻节点之间都存在一条边。
// 同一个节点在一条路径序列中 至多出现一次 。该路径至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。以先序遍历给定一个二叉树的根节点root，返回其最大路径和。
// 输入描述以先序遍历给定二叉树根节点为 root =[1,2,3,4,5]。
// 数据范围为[-1000,1000] 输出描述则最大路径和就是5->2->1->3.路径和为5+2+1+3=11
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to build the binary tree from preorder input
TreeNode* buildTree(int* preorder, int* index, int size) {
    if (*index >= size || preorder[*index] == -1) {
        (*index)++;
        return NULL;
    }

    TreeNode* root = createNode(preorder[*index]);
    (*index)++;
    root->left = buildTree(preorder, index, size);
    root->right = buildTree(preorder, index, size);

    return root;
}

//对于二叉树中的一个节点，该节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
// maxpath 是一个全局变量，这是可以工作的，但全局变量的使用在编程中通常需要小心，特别是在多线程环境中。
// 全局变量会被整个程序共享，容易引发难以调试的错误。如果在同一程序中处理多个二叉树，可能会导致结果错误。

int maxgain(struct TreeNode* root, int* maxpath){
    if(root == NULL) return 0;

    //如果子节点的最大贡献值为正，则计入该节点的最大路径和，
    //否则不计入该节点的最大路径和
    int left_gain = fmax(maxgain(root->left, maxpath),0);
    int right_gain = fmax(maxgain(root->right, maxpath),0);
    // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    int newpath = root->val + left_gain + right_gain;
    //更新最大路径
    *maxpath = fmax(newpath, *maxpath);
    //返回节点的最大贡献值
    return root->val + fmax(left_gain, right_gain);
}

int maxPathSum(struct TreeNode* root) {
    int maxpath = INT_MIN;
    maxgain(root, &maxpath);
    return maxpath;
}

int main() {
    int preorder[] = {0}; // -1 represents NULL
    int size = sizeof(preorder) / sizeof(preorder[0]);
    int index = 0;

    TreeNode* root = buildTree(preorder, &index, size);
    
    int result = maxPathSum(root);
    printf("Maximum Path Sum: %d\n", result);

    return 0;
}
