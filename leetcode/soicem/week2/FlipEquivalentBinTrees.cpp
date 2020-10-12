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
    bool traverse(TreeNode* node1, TreeNode* node2){
        if(!node1 || !node2 || (node1->val != node2->val)){
            return false;
        }
        
        bool ret = true;
        
        if(node1->left){
            if(node2->right){
                if(node1->left->val == node2->right->val){
                    ret &= traverse(node1->left, node2->right);
                } else {
                    ret &= traverse(node1->left, node2->left);
                }
            } else {
                ret &= traverse(node1->left, node2->left);
            }
        }
        
        if(node1->right){
            if(node2->left){
                if(node1->right->val == node2->left->val){
                    ret &= traverse(node1->right, node2->left);
                } else {
                    ret &= traverse(node1->right, node2->right);
                }
            } else {
                ret &= traverse(node1->right, node2->right);
            }
        }
        return ret;
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        
        if(root1 == NULL || root2 == NULL){
            return false;
        }
        
        return traverse(root1, root2);
    }
};
