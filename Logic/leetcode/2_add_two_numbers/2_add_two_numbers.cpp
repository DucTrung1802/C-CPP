#include <iostream>

using namespace std;

/**
 * MY OWN SOLUTION !
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    ListNode *head = new ListNode();
    ListNode *result;
    ListNode *current;
    int overflow = 0;
    int sum = 0;
    bool initialized = false;

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *current_1 = l1;
        ListNode *current_2 = l2;

        if (!l1 || !l2)
        {
            return nullptr;
        }

        do
        {
            if (current_1 && current_2)
            {
                this->sum = current_1->val + current_2->val;
            }
            else if (current_1 && !current_2)
            {
                this->sum = current_1->val;
            }
            else if (!current_1 && current_2)
            {
                this->sum = current_2->val;
            }
            else
            {
                if (overflow)
                {
                    this->sum = 0;
                }
                else
                {
                    return this->result;
                }
            }

            ListNode *temp = new ListNode();

            if (this->sum + overflow >= 10)
            {
                temp->val = (sum + this->overflow) % 10;
                this->overflow = 1;
            }

            else
            {
                temp->val = sum + this->overflow;
                this->overflow = 0;
            }

            if (!initialized)
            {
                this->head->val = temp->val;
                this->result = this->head;
                this->current = this->head;
                initialized = true;
            }
            else
            {
                this->current->next = temp;
                this->current = this->current->next;
            }

            if (current_1)
            {
                if (current_1->next)
                {
                    current_1 = current_1->next;
                }
                else
                {
                    current_1 = nullptr;
                }
            }

            if (current_2)
            {
                if (current_2->next)
                {
                    current_2 = current_2->next;
                }
                else
                {
                    current_2 = nullptr;
                }
            }

        } while (l1->next || l2->next || overflow);

        return this->result;
    }
};

void printLinkedList(ListNode *head)
{
    ListNode *current = head; // Start at the head of the list

    while (current != nullptr)
    {
        std::cout << current->val << " "; // Print the current node's data
        current = current->next;          // Move to the next node
    }

    std::cout << std::endl; // Print a newline after the list
}

int main()
{
    Solution solution;
    ListNode a_1(5);

    ListNode b_1(5);

    ListNode *result = solution.addTwoNumbers(&a_1, &b_1);
    printLinkedList(result);
}