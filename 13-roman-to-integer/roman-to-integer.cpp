class Solution {
public:
    int romanToInt(string s) {
        static const std::unordered_map<char, int> numerals{
            {'I', 1}, 
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}
        };

        int num = 0;
        const size_t len = s.size();

        for (size_t n = 0; n < len; ++n) {
            int curr     = numerals.at(s[n]);                      
            int currNext = (n + 1 < len) ? numerals.at(s[n + 1]) : 0;                      

            if (curr < currNext) {
                num -= curr;
            } else {
                num += curr;
            }
        }

        return num;
    }
};