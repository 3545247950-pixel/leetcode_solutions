//单调栈解法
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        stk = stack<int>{};
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;

    }
};