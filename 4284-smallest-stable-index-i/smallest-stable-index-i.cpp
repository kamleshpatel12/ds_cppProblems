class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maximum;
        int n = nums.size();
        vector<int>minimum;
        int maxValue  = -1;
        for(int i=0; i<n; i++){
            maxValue = max(nums[i], maxValue);
            maximum.push_back(maxValue);
        }

        int minValue = INT_MAX;

        for(int i=n-1; i>=0; i--){
            minValue = min(nums[i], minValue);
            minimum.push_back(minValue);
        }
        reverse(minimum.begin(), minimum.end());
      
      for(int i=0; i<n; i++){
        if((maximum[i] - minimum[i]) <=k){
            return i;
        }
      }

      return -1;

    }
};

