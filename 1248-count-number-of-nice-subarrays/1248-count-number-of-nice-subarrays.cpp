class Solution {
public:
    int subarray(vector<int>& nums, int k) {

        if (k < 0)
            return 0;
        vector<int> num;
        for (auto val : nums) {
            if (val % 2 == 1)
                num.push_back(1);
            else
                num.push_back(0);
        }

        int sum = 0, l = 0, r = 0, cnt = 0;

        while (r < num.size()) {
            sum += num[r];
            while (sum > k) {
                sum -= num[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return abs(subarray(nums,k)-subarray(nums,k-1));

    }
};