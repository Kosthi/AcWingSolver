class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, ans = 0, res = 1;
        for (int r = 0; r < nums.size(); r++) {
            res *= nums[r];
            while (l <= r && res >= k) res /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};
