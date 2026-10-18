class Solution {
public:
   void solve(int i, vector<int>&nums, vector<int>&temp, vector<vector<int>>& answer){
   int n = nums.size();
    if(i==nums.size()){
     answer.push_back(temp);
     return;
    }

    temp.push_back(nums[i]);
    solve(i+1, nums, temp, answer);

    temp.pop_back();

    solve(i+1, nums, temp, answer);

   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>temp;
        solve(0, nums, temp, answer);
        return answer;
    }
};