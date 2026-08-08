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
    ListNode* removeElements(ListNode* head, int val) {

        // // Method 1

        // ListNode* temp = head;
        // vector<int>ans;

        // // store only the value which is NOT equal to val
        // while(temp != nullptr){
        //     if(temp->val != val){
        //         ans.push_back(temp->val);
        //     }
        //     temp = temp->next;
        // }

        // // if all the nodes had value = val
        // if(ans.empty()){
        //     return nullptr;
        // }

        // // put the remaining values back into the linked list
        // temp = head;
        // int i = 0;

        // while(temp != nullptr && i <ans.size()){
        //     temp->val = ans[i];
        //     i++;
        //     temp = temp->next;
        // }

        // // move to the LAST valid node
        // temp = head;

    
        // for(int j=1; j<ans.size(); j++){
        //     temp=temp->next;
        // }

        // // cut off after the last valid node
        // temp->next = nullptr;

        // return head;

        // Method 2

        while(head != nullptr && head->val == val){
            head= head->next;
        }

        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};