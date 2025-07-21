class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }

        int reverse = 0;
        int temp  = x;
        int count = 0;

        while (temp) {
            int d = temp % 10;
            temp /= 10;
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && d > 7))
                return false;           
            reverse = reverse * 10 + d;
            ++count;
        }

        temp = x;
        int half = count / 2;

        for (int i = 0; i < half; ++i) {
            if ((temp % 10) != (reverse % 10))
                return false;
            temp /= 10;
            reverse  /= 10;
        }

        return true;
    }
};