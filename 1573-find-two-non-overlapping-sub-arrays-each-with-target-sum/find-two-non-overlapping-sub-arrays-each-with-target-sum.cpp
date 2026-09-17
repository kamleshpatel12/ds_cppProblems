class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        // best[i] = shortest target-sum subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // We found a target-sum subarray
            if (sum == target) {

                int len = right - left + 1;

                // Need a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Keep shortest target subarray seen so far
                minLen = min(minLen, len);
            }

            // Store the best answer up to this index
            best[right] = minLen;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};