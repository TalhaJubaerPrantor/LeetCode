class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lim = k;
        int i = 0, j = 0;
        int mxSize = 0;

        while (j != nums.size()) {

            if (nums[j] == 1 || (nums[j] == 0 && lim != 0)) {
                mxSize = max(mxSize, j - i + 1);
                if (nums[j] == 0)
                    lim--;
                j++;
            } else if (lim == 0 && lim <= k) {
                if (nums[i] == 1) {
                    i++;
                } else {
                    lim++;
                    i++;
                }
            }
        }
        return mxSize;
    }
};