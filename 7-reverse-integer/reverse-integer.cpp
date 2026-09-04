class Solution {
public:
    int reverse(int x) {
        int temp =x;
        long long result  = 0;
        while(temp!=0){
            int rem = temp%10;
            result = result*10+rem;
            temp /= 10;
        }
        
        if(result  > INT_MAX || result < INT_MIN){
            return 0;
        }
        return result;
    }
};

// reversing 1234
// 4 = (rem 4) 
// 43 = (rem 3) = 40+3
// 432 = (rem 2) = 430+2(43*10+2)
// 4321 = (rem 1)