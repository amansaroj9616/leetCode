/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {

        InoderTraversal(root);

        return buildBalanceBST(0,sortedValue.size( ) -1);



        
    }

    private:
    vector<int>sortedValue;

    void InoderTraversal(TreeNode* node){
        if(!node){
        return ;
        }
       InoderTraversal(node->left);
        sortedValue.push_back(node->val);
        InoderTraversal(node->right);
    }
    TreeNode* buildBalanceBST(int left , int right){
        if(left>right){
            return nullptr;
        }
        int mid=left+(right-left)/2;

         TreeNode* leftSubtree = buildBalanceBST(left, mid - 1);
        TreeNode* rightSubtree = buildBalanceBST(mid + 1, right);
        return new TreeNode(sortedValue[mid], leftSubtree, rightSubtree);
    }

};