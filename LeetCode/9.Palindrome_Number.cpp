class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long num = 0;
        int original = x;
        while(x > 0){
            num *= 10; 
            num += x % 10;
            x /= 10;
        }
        return original == num;
    }
};
