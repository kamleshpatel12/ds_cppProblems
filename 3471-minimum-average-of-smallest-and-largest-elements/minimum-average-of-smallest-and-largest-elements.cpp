class Solution {
public:
    double minimumAverage(vector<int>& nums) {
         int n = nums.size();
          sort(nums.begin(), nums.end());
          int i=0;
          int j = n-1;
          double minValue = INT_MAX;
          while(i<j){
             double avg = (nums[i]+nums[j])/2.0;
             minValue = min(minValue, avg);
             i++;
             j--;
          }
          return minValue;
    }
};