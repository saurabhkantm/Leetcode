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
class Solution {
public:
    ListNode* vectorToList(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        ListNode* head = new ListNode(nums[0]);
        ListNode* temp = head;

        for (int i = 1; i < nums.size(); i++) {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        vector<int> arr1, arr2, ans;

        while (l1) {
            arr1.push_back(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            arr2.push_back(l2->val);
            l2 = l2->next;
        }

        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0)
                sum += arr1[i--];

            if (j >= 0)
                sum += arr2[j--];

            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());

        return vectorToList(ans);
    }
};