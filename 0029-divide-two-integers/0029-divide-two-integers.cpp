class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int sin = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sin = 0;

        if (divisor < 0)
            divisor *= -1;
        if (dividend < 0)
            dividend *= -1;

        int temp = 0;
        long long cnt = 0;
        while (temp <= dividend) {
            temp += divisor;
            cnt++;
        }

        if (!sin)
            return -(cnt - 1);
        return cnt - 1;
    }
};