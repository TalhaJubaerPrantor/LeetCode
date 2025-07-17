class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int result=0;
        for(int val:nums) result ^=val;
        return result;
    }
};