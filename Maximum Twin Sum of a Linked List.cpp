class Solution {
public:
    int pairSum(ListNode* head){
        vector<int> x;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast -> next){
            x.push_back(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        int res = 0, i(x.size() - 1);
        while(slow){
            res = max(res, x[i--] + slow -> val);
            slow = slow -> next;
        }

        return res;
    }
};
