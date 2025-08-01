class Solution {
public:
    int countPrimes(int n) {
        vector<int>v(n+1,1);
        int count = 0;
        for(long long i=2;i<n;i++){
            if(v[i]){
                count++;
                for(long long j = i*i;j<n;j+=i){
                    v[j] = 0;
                }
            }
        }
        return count;
    }
};