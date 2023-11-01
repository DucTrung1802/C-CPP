#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Not my solution
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

TreeNode *createRandomSortedBinaryTree(int n)
{
    TreeNode *root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int randomValue = std::rand() % 100 + 1; // Generate random value between 1 and 100
        root = insert(root, randomValue);
    }
    return root;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        else if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed the random number generator

    Solution solution;
    int n = 20; // Number of nodes
    TreeNode *root = createRandomSortedBinaryTree(n);

    std::cout << "Random Binary Tree with 20 nodes (In-order traversal):" << std::endl;
    printTree(root);
    std::cout << std::endl;

    TreeNode *result = solution.insertIntoBST(root, 25);
    std::cout << "Result: " << std::endl;
    printTree(result);
    std::cout << std::endl;

    return 0;
}