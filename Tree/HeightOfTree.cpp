#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class heightOfTree{
    public:
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh)+1;
    }
};
/*
 * Balanced Binary Tree Leetcode 110
    * Given a binary tree, determine if it is height-balanced.
    * For this problem, a height-balanced binary tree is defined as:
    * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
    * Example 1:
    * Input: root = [3,9,20,null,null,15,7]
    * Output: true 
 */
class BalancedBinaryTree {
public:
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh==-1 || rh ==-1)return -1;
    if(abs(lh-rh) > 1)return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)>=0;
    }
};
// Diameter of Binary Tree Leetcode 543 
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//example : 
// Input: root = [1,2,3,4,5]
// Output: 4 
class DiameterOfBinaryTree {
public:
    int height(TreeNode* r,int &maxi){
        if(r==NULL)return 0;
        int lh = height(r->left,maxi);
        int rh = height(r->right,maxi);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi =-1;
        height(root,maxi);
        return maxi;
    }
};

/*
* Binary Tree Maximum Path Sum Leetcode 124
* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
* The path sum of a path is the sum of the node's values in the path.
* Given the root of a binary tree, return the maximum path sum of any non-empty path.
* Example 1:
* Input: root = [1,2,3]
* Output: 6
* Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
* Example 2:
* Input: root = [-10,9,20,null,null,15,7]
* Output: 42
* Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
* Constraints:
* The number of nodes in the tree is in the range [1, 3 * 10^4].
* -1000 <= Node.val <= 1000
*/
/*
* Approach:
* We will use a recursive function to calculate the maximum path sum.
* We will keep track of the maximum path sum found so far using a reference variable.
* For each node, we will calculate the maximum path sum that can be obtained by including the node and its left and right subtrees.
* We will return the maximum path sum that can be obtained by including the node and one of its subtrees.
* We will also consider the case where we do not include the node and only consider its subtrees.
* The time complexity of this approach is O(n) where n is the number of nodes in the tree.

*/
class BinaryTreeMaximumPathSum {
public:
    int maxp(TreeNode* ro,int &maxi){
        if(ro==NULL){
            return 0;
        }
        int l=max(maxp(ro->left,maxi),0);
        int r=max(maxp(ro->right,maxi),0);
        maxi = max(maxi,l+r+ro->val);
        return ro->val +max(r,l);        
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e6;
        maxp(root,maxi);
        return maxi;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);
    root->right->right = new TreeNode(7);

    heightOfTree ht;
    cout<<ht.height(root)<<endl;
    BalancedBinaryTree sol;
    cout<<sol.isBalanced(root)<<endl;

    return 0;
}