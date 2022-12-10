
// LINKED LIST = CAN'T RUN

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

//  A bit less efficient, more readable
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(999);
        ListNode* current = result;
        int bonus = 0;
        int sum = 0;
        int v1 = 0, v2 = 0;
        while (l1 || l2 || bonus) {
            v1 = l1 ? l1->val : 0;
            v2 = l2 ? l2->val : 0;
            sum = v1 + v2 + bonus;

            bonus = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return result->next;
    }
};

//  More efficient, but way less readable
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode* current1 = l1;
        while (current1 != nullptr) {
            len1++;
            current1 = current1->next;
        }
        ListNode* current2 = l2;
        while (current2 != nullptr) {
            len2++;
            current2 = current2->next;
        }

        if (len2 > len1) {
            swap(l1, l2);
            swap(len1, len2);
        }

        current1 = l1;
        current2 = l2;
        int reflectCount = len2;
        int i = 0;
        int bonus = 0;
        int sum = 0;
        while (current1->next != nullptr) {
            if (i >= reflectCount) {
                sum = current1->val + bonus;
            } else {
                sum = current1->val + current2->val + bonus;
                current2 = current2->next;
            }
            if (sum > 9) {
                current1->val = sum - 10;
                bonus = 1;
            } else {
                current1->val = sum;
                bonus = 0;
            }
            current1 = current1->next;
            i++;
        }

        if (len1 > len2) {
            sum = current1->val + bonus;
        } else {
            sum = current1->val + current2->val + bonus;
        }
        if (sum > 9) {
            ListNode* newNode = new ListNode(1);
            current1->next = newNode;
            current1->val = sum - 10;
        } else {
            current1->val = sum;
        }
        return l1;
    }
};