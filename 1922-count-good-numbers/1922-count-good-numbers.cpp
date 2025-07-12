#define mod (long long)(1e9+7)

class Solution {
public:
    long long pow(long long a, long long b){
        if(b == 0) return 1;
        long long root = pow(a, b / 2);
        if(b % 2 == 0) return (root * root) % mod;
        return (a * ((root * root) % mod)) % mod;
    }

    int countGoodNumbers(long long n) {
        long long odd = n / 2;           
        long long even = n - odd;      
        return (pow(5, even) * pow(4, odd)) % mod;
    }
};