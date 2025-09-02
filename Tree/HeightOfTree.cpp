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
class heightOfTree{
    public:
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh)+1;
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