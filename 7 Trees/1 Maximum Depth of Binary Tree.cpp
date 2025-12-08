#include <bits/stdc++.h>
using namespace std;

/* Approach: DFS (Recursive) 
*/

class Solution {
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
    };

    int maxDepth(TreeNode* root) {

        // Base Case: If the node is NULL, depth is 0
        // This happens when we go beyond leaf nodes
        if (root == nullptr)
            return 0;

        // Recursively find the depth of left subtree
        int leftDepth = maxDepth(root->left);

        // Recursively find the depth of right subtree
        int rightDepth = maxDepth(root->right);

        // The depth of the current node is:
        // 1 (for current node) + max(left subtree depth, right subtree depth)
        return 1 + max(leftDepth, rightDepth);
    }
};


/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 3

    Example 2:
    Input: root = [1,null,2]
    Output: 2
*/