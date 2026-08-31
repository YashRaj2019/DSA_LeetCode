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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        int pos = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr->next != nullptr){
            if((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)){
                    ans.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // less than
        if(ans.size() < 2){
            return {-1, -1};
        }

        int mini = INT_MAX;
        int maxi = ans.back() - ans.front();

        // minimum distance between consecutive critical points
        for(int i=1; i<ans.size(); i++){
            mini = min(mini, ans[i] - ans[i - 1]);
        }

        return {mini, maxi};
    }
};