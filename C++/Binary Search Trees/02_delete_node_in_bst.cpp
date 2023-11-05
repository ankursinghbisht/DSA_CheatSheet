/*
Idea:
3 cases while delete a node:
- it is a leaf node, delete independently
- has one child, delete node, and replace it with it's child
- has 2 children, finding immediate successor/predecessor, replacing and deleting the original location of successor/predecessor.
*/

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

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        //base case
        if (root == NULL)
            return root;

        // Recursive calls for ancestors of node to be deleted
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        //reached the node to be deleted
        if (!root->left)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // if both children exist
        else
        {
            TreeNode* parentOfSuccessor = root, * successor = root->right;

            //finding successor
            while (successor->left)
            {
                parentOfSuccessor = successor;
                successor = successor->left;
            }

            // Delete successor.  Since successor  is always left child of its parent  we can safely make successor's right
            // right child as left of its parent.  If there is no succ, then assign  succ->right to succParent->right
            if (parentOfSuccessor != root)
                parentOfSuccessor->left = successor->right;
            else
                parentOfSuccessor->right = successor->right;

            //copy successor to root
            root->val = successor->val;

            delete successor;
            return root;
        }
    }
};