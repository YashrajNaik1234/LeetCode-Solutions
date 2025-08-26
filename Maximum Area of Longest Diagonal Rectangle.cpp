class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDia = 0, maxArea = 0;

        for (auto dim : dimensions) {
            int l = dim[0], w = dim[1];
            int dia = l * l + w * w, area = l * w;
            if (dia > maxDia) {
                maxDia = dia; maxArea = area;
            }
            else if (dia == maxDia) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
