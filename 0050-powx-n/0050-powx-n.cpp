class Solution {
public:
    double helper(double x, long n){
        if(n == 0) return 1;
        if(x == 0) return 0;

        double res = helper(x, n / 2);
        res = res * res;

        return (n & 1) ? res * x : res;
    }

    double myPow(double x, int n) {
        long N = n;
        double ans = helper(x, abs(N));
        return (n >= 0) ? ans : 1 / ans;
    }
};