#include <bits/stdc++.h>
using namespace std;

/*
* write the main function here
* to test the above function
* create a binary tree and call the levelOrder function
* print the result
* Example:
* Input: root = [3,9,20,null,null,15,7]
* Output: [[3],[9,20],[15,7]]
* Explanation: The binary tree is shown above.
* The level order traversal of the binary tree is [[3],[9,20],[15,7]].
* Constraints:
* The number of nodes in the tree is in the range [0, 2000].
* -1000 <= Node.val <= 1000
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0 ;i<size;i++){
                TreeNode* crr = q.front();
                q.pop();
                temp.push_back(crr->val);
                if(crr->left)q.push(crr->left);
                if(crr->right)q.push(crr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* crr = st.top();
            st.pop();
            if(crr->right)st.push(crr->right);
            if(crr->left) st.push(crr->left);
            ans.push_back(crr->val);
        }


        return ans;
    }
};
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}


int main() {
    
    // Create a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    for (const auto& level : result) {
        cout << "[";
        for (size_t i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}