#include<iostream>
#include<climits>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct Info {
        int size;
        int minVal;
        int maxVal;
        bool isBST;
    };

    int maxSize = 0;

    Info solve(TreeNode* root) {
        if (root == NULL) {
            return Info{0, INT_MAX, INT_MIN, true};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->val, left.minVal);
        curr.maxVal = max(root->val, right.maxVal);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal && root->val < right.minVal) {
            curr.isBST = true;
            maxSize = max(maxSize, curr.size);
        } else {
            curr.isBST = false;
        }

        return curr;
    }

    int largestBSTSubtree(TreeNode* root) {
        solve(root);
        return maxSize;
    }

    TreeNode* insertBinaryTree(TreeNode* root, int data) {
            TreeNode* newNode = new TreeNode(data);

            // If tree is empty
            if (!root) return newNode;

            // Use queue for level order insertion
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();

                // Insert in the left child if empty
                if (!temp->left) {
                    temp->left = newNode;
                    return root;
                } else {
                    q.push(temp->left);
                }

                // Insert in the right child if empty
                if (!temp->right) {
                    temp->right = newNode;
                    return root;
                } else {
                    q.push(temp->right);
                }
            }
            return root;
    }

};

int main(){

    int n;
    cin >> n;
    Solution sol;
    TreeNode* root = nullptr;

    for(int i=0; i< n; i++){
        int val;
        cin >> val;
        root = sol.insertBinaryTree(root, val);
    }

    cout << "Largest BST-subtree is: " << sol.largestBSTSubtree(root) << endl;

    return 0;
}