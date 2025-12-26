class Solution {
public:
    int bestClosingTime(string customers) {
        int cur = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') cur++;
        }

        int mini = cur,res = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') cur--;
            else cur++;

            if (cur < mini) {
                res = i + 1; mini = cur;
            }
        }

        return res;
    }
};
