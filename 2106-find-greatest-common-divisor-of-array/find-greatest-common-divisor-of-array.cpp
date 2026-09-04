class Solution {
public:
    int gcdfind(int a, int b){
     while(b != 0){
        int temp = b;    //  save b first
        b = a % b;       //  use original a
        a = temp;        //  update a
     }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[n-1]);

    }
};

// euclid gcd algo : gcd(a, b) = gcd(b, a%b)