class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Correct way to handle INT_MIN
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        bool sign = (dividend < 0) == (divisor < 0);  // true if same sign

        long ans = 0;
        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += 1L << count;
            n -= d << count;
        }

        if (ans >= (1LL << 31))  // clamp to 32-bit signed int range
            return sign ? INT_MAX : INT_MIN;

        return sign ? ans : -ans;
    }
};
