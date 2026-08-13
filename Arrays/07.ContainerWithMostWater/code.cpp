class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = -1;
        int length;
        int breadth;
        int area;
        int n = height.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            breadth = j - i;
            length = min(height[i], height[j]);
            area = length * breadth;
            if(area>maxArea) maxArea=area;
            if (height[i] > height[j]) --j;
            else ++i;
        }

        return maxArea;
    }
};