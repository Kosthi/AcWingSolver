class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        int q[1010];
        int hh = 0, tt = -1;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (hh <= tt && i - k + 1 > q[hh]) hh++;
            while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;
            q[++tt] = i;
            if (i >= k - 1) ans.push_back(nums[q[hh]]);
        }
        return ans;
    }
};
