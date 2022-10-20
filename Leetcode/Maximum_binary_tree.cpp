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
        
        TreeNode* construct(vector<int>& nums,int start,int end){
                if(start<=end){
                        int maxValue = INT_MIN ,maxIndex = -1;
                for(int i=start;i<=end;i++){
                        if(maxValue<nums[i]){
                                maxValue = nums[i];
                                maxIndex = i;
                        }
                }
                TreeNode* root = new TreeNode(maxValue);
                root->left = construct(nums,start,maxIndex-1);
                root->right = construct(nums,maxIndex+1,end);
                return root;
                }
                return NULL;
                
        }
        
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = construct(nums,0,nums.size()-1);
            return root;
    }
};
