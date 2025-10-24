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
    bool isPalindrome(ListNode* head) {

        if(head->next==nullptr){
            return 1;
        }
        
        // Step 1: Count the number of nodes
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Step 2: Move to middle
        count /= 2;
        ListNode* current = head;
        ListNode* prev = nullptr;

        while (count--) {
            prev = current;
            current = current->next;
        }

        // Step 3: Split the list
        prev->next = nullptr;

        // Step 4: Reverse the second half (current points to its head)
        ListNode* front;
        prev = nullptr;
        while (current != nullptr) {
            front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }

        // Step 5: Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = prev;  // head of reversed second half

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true; 
    }
};
