class Solution {
public:
    bool isPalindrome(int x) {

    if(x<0){
        return false;
    }

    int temp =x;
   long long result = 0; // while reversing number can overflow, so it is necessary to check for it
    while(temp!=0){
        int rem = temp %10;
        result  = result*10+rem;
        temp /=10;
    }

    if(result > INT_MAX || result < INT_MIN) 
    return false;

    while(x!=0){
      int rem1 = x%10;
      int rem2 = result%10;
      if(rem1!=rem2){
        return false;
      }
      x /=10;
      result /=10;
    }
    return true;

    }
};



