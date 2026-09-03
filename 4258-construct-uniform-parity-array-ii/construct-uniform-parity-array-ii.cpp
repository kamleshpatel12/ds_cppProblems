class Solution {
public:

    bool isOdd(vector<int>& nums) {
        bool isodd = true;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                isodd = false;
                break;
            }
        }

        return isodd;
    }
    bool isEven(vector<int>& nums) {
        bool iseven = true;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 != 0) {
                iseven = false;
                break;
            }
        }

        return iseven;
    }


    bool oddCheckup(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        // smallest number is already odd
        int smallestodd = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums1[i] < smallestodd && nums1[i] % 2 != 0) {
                smallestodd = nums1[i];
            }
        }

        for(int i = 0; i < n; i++) {

            if(nums1[i] % 2 != 0) {
                nums2[i] = nums1[i];
            }
            else {
                // even - odd = odd
                nums2[i] = nums1[i] - smallestodd;
            }
        }

        if(isOdd(nums2) == 1) {
            return true;
        }

        return false;
    }


    bool uniformArray(vector<int>& nums1) {

        // Already all even
        if(isEven(nums1) == 1)
            return true;

        // Already all odd
        if(isOdd(nums1) == 1)
            return true;

        int n = nums1.size();

        vector<int> nums2;
        nums2 = nums1;

        int smallest = INT_MAX;

        for(int x : nums1) {
            if(x < smallest) {
                smallest = x;
            }
        }

        // If smallest is odd,
        // convert every even number to odd.
        if(smallest % 2 != 0) {

            if(oddCheckup(nums1, nums2) == 1) {
                return true;
            }
        }

        // If smallest is even, mixed array is impossible.
        else {
            return false;
        }

        return false;
    }
};