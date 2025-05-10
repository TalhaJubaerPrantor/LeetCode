bool cmp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
class Solution {
public:
    

    string frequencySort(string s) {

        map<char, int> m;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m.insert({s[i], 1});
            } else {
                m[s[i]]++;
            }
        }

        vector<pair<char, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), cmp);

        string ans = "";

        for (auto val : v) {
            for (int i = 0; i < val.second; i++) {
                ans += val.first;
            }
        }

        return ans;
    }
};