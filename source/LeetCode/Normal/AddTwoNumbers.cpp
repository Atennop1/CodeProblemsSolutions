#include "Declarations.h"

namespace LeetCodeNormal
{
    Solutions::ListNode* Solutions::AddTwoNumbers(ListNode *first, ListNode *second)
    {
        auto *result = new ListNode();
        ListNode *current_node = result;
        int carry = 0;

        while (first != nullptr || second != nullptr)
        {
            int sum = carry;
            if (first != nullptr)
                sum += first->value;

            if (second != nullptr)
                sum += second->value;

            current_node->value = sum % 10;
            carry = sum / 10;

            if ((first == nullptr || first->next == nullptr) && (second == nullptr || second->next == nullptr))
                break;

            current_node->next = new ListNode();
            current_node = current_node->next;

            if (first != nullptr)
                first = first->next;

            if (second != nullptr)
                second = second->next;
        }

        if (carry == 1)
            current_node->next = new ListNode(carry);

        return result;
    }
}