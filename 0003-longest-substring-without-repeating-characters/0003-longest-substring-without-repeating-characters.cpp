class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int mxSize = 0;
        int i = 0, j = 0;
        map<char, int> mp;

        while (j != s.size() && i <= j) {
            // cout<<j<<":"<<endl;
            if (mp.find(s[j]) == mp.end()) {
                mp.insert({s[j], j});
                mxSize = max(mxSize, j - i + 1);
                // cout<<"inserted"<<mxSize<<endl;
            } else if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
                mp[s[j]] = j;
                // cout<<"2nd condition"<<mxSize<<endl;
            } else if (mp[s[j]] < i) {
                mxSize = max(mxSize, j - i + 1);
                mp[s[j]] = j;
            }

            j++;
        }

        return mxSize;
    }
};