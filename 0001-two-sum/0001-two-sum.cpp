class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;
      
        int f, l;
        for (int i = 0; i < nums.size(); i++) {

            mp.insert({nums[i], i});

            if (mp.find(target - nums[i]) != mp.end()  && mp[target-nums[i]]!=i) {
                f = mp[target - nums[i]];
                l = i;
            }
        }

       vector<int>ans={f,l};
        return ans;

    }
};