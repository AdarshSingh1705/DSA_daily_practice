#include<iostream>
#include<map>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};
 
/**====================================
        Solved using DFS which is more fast and efficient
============================================*/
// class Solution {
// public:

//     int ans = 0;
    
//    int solve(TreeNode* node, int start, TreeNode *root){
//         int l = 0, r = 0;
//         if(node->left != nullptr){
//             l = solve(node->left, start, root);
//         }
//         if(node->right != nullptr){
//             r = solve(node->right, start, root);
//         }

//         if(node->val == start){
//             ans = max(ans, max(l, r)); return -1;
//         }
//         else if(l < 0){
//             ans = max(ans, abs(l)+r); return l-1;
//         } else if(r < 0){
//             ans = max(ans, abs(r)+l); return r-1;
//         }
//         return 1 + max(l, r);
//     }

//     int amountOfTime(TreeNode* root, int start) {
//         solve(root, start, root);
//         return ans;
//     }
// TreeNode* insert(TreeNode* root, int val) {
//         if (!root) return new TreeNode(val);
//         if (val < root->val)
//             root->left = insert(root->left, val);
//         else
//             root->right = insert(root->right, val);
//         return root;
// }

// };

/*===========================================
         Solved using BFS O(n)
=============================================*/
class Solution {
public:
TreeNode* createParMap(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodetopar){

    TreeNode* res = nullptr;
    queue<TreeNode*> q;
    q.push(root);
    nodetopar[root] = nullptr;

    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();

        if(front -> val == target){
            res = front;
        }
        if(front -> left){
            nodetopar[front -> left] = front;
            q.push(front -> left);
        }
        if(front -> right){
            nodetopar[front -> right] = front;
            q.push(front -> right);
        }
    }
     return res;
}

int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &nodetopar){

    map<TreeNode*, bool> visited;
    queue<TreeNode*>q;
    q.push(root);
    visited[root] = true;
    int ans =0;

    while(!q.empty()){
        bool flag = 0;
        int size = q.size();

        for(int i=0; i<size; i++){
            TreeNode* front = q.front();
            q.pop();

            if(front ->left && !visited[front-> left]){
                flag = 1;
                q.push(front -> left);
                visited[front -> left] = 1;
            }
            if(front -> right && !visited[front -> right]){
                flag = 1;
                q.push(front -> right);
                visited[front -> right] = 1;
            }
            if (nodetopar[front] && !visited[nodetopar[front]]) {
                flag = true;
                q.push(nodetopar[front]);
                visited[nodetopar[front]] = true;
            }
        }
        if(flag == 1) ans++;
    } 
    return ans;
}

    int amountOfTime(TreeNode* root, int target) {
        map<TreeNode*, TreeNode*>nodetopar;
        TreeNode* targetNode = createParMap(root, target, nodetopar);
        int ans = burnTree(targetNode, nodetopar);

        return ans;
    }

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
};

int main() {
    int n;
    cin >> n;
    Solution Sol;
    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = Sol.insert(root, val);
    }
    int start;
    cin >> start;     

 // creating instance of the solution
    cout << Sol.amountOfTime(root, start);

    return 0;
}