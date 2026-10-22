class Solution {
public:
    int count = 0;
    int sum = 0;

    void solve(vector<int>& nums, int target, int i) {
        if (i == nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }

        // Choose +
        sum += nums[i];
        solve(nums, target, i + 1);
        sum -= nums[i];  // Backtrack

        // Choose -
        sum -= nums[i];
        solve(nums, target, i + 1);
        sum += nums[i];  // Backtrack
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        sum = 0;
        solve(nums, target, 0);
        return count;
    }
};