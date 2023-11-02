#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Not my solution
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
    srand(0);
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
    {
        std::cout << "NULL"
                  << " ";
        return;
    }

    if (!root->left && !root->right)
    {
        std::cout << root->val << " ";
        return;
    }

    printTree(root->left);

    std::cout << root->val << " ";

    printTree(root->right);
}

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            TreeNode *curr = root->right;
            while (curr->left != nullptr)
            {
                curr = curr->left;
            }
            root->val = curr->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed the random number generator

    Solution solution;
    int n = 20; // Number of nodes
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Random Binary Tree with 20 nodes (In-order traversal):" << std::endl;
    printTree(root);
    std::cout << std::endl;

    TreeNode *result = solution.deleteNode(root, 3);
    std::cout << "Result: " << std::endl;
    printTree(result);
    std::cout << std::endl;

    return 0;
}