class Solution {
public:

    void subSet(vector<int>& nums,vector<int>& ans,int i, vector<vector<int>>& sets){
        if(i==nums.size()){
            sets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        subSet(nums,ans,i+1,sets);

        ans.pop_back();
        subSet(nums,ans,i+1,sets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> sets;
        vector<int> ans;
        
        subSet(nums,ans,0,sets);
        return sets;
    }
};