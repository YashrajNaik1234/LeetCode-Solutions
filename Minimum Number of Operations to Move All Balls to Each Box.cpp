class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);

        int leftball = 0, moveleft = 0;
        int rightball = 0, moveright = 0;

        for(int i(0);i < boxes.size();i++){
            ans[i] += moveleft;
            leftball += boxes[i] - '0'; moveleft += leftball;

            int j = boxes.size() - i - 1;
            ans[j] += moveright;
            rightball += boxes[j] - '0'; moveright += rightball;
        }

        return ans;
    }
};
