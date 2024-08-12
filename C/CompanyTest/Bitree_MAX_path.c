// 题目描述: 二叉树中的 路径 被定义为一条节点序列，列中每对相邻节点之间都存在一条边。
// 同一个节点在一条路径序列中 至多出现一次 。该路径至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。以先序遍历给定一个二叉树的根节点root，返回其最大路径和。
// 输入描述以先序遍历给定二叉树根节点为 root =[1,2,3,4,5]。
// 数据范围为[-1000,1000] 输出描述则最大路径和就是5->2->1->3.路径和为5+2+1+3=11
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Helper function to find the maximum path sum in the binary tree
int maxPathSumHelper(TreeNode* root, int* maxSum) {
    if (root == NULL) return 0;

    int leftMax = maxPathSumHelper(root->left, maxSum);
    int rightMax = maxPathSumHelper(root->right, maxSum);

    int currentMax = root->val;
    if (leftMax > 0) currentMax += leftMax;
    if (rightMax > 0) currentMax += rightMax;

    if (currentMax > *maxSum) {
        *maxSum = currentMax;
    }

    return root->val > root->val + (leftMax > 0 ? leftMax : 0) ? root->val : root->val + (leftMax > 0 ? leftMax : 0) > root->val + (rightMax > 0 ? rightMax : 0) ? root->val + (leftMax > 0 ? leftMax : 0) : root->val + (rightMax > 0 ? rightMax : 0);
}

// Main function to find the maximum path sum
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}

int main() {
    int preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1}; // -1 represents NULL
    int size = sizeof(preorder) / sizeof(preorder[0]);
    int index = 0;

    TreeNode* root = buildTree(preorder, &index, size);
    
    int result = maxPathSum(root);
    printf("Maximum Path Sum: %d\n", result);

    return 0;
}
