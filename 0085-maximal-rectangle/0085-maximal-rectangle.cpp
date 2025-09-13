class Solution {
public:
    vector<vector<int>> prefSome(vector<vector<char>> matrix) {

        vector<vector<int>> pref(matrix.size(),
                                 vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0) {
                    if (matrix[i][j] == '1') {
                        pref[i][j] = 1;
                    } else {
                        pref[i][j] = 0;
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        pref[i][j] = pref[i - 1][j] + 1;
                    } else {
                        pref[i][j] = 0;
                    }
                }
            }
        }
        return pref;
    }

    vector<int> pse(vector<int> nums) {
        stack<int> stk;
        vector<int> res(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty()) {
                stk.push(i);
                res[i] = -1;
            } else {
                while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    res[i] = -1;
                    stk.push(i);
                } else {
                    res[i] = stk.top();
                    stk.push(i);
                }
            }
        }
        return res;
    }

    vector<int> nse(vector<int> nums) {
        stack<int> stk;
        vector<int> res(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (stk.empty()) {
                stk.push(i);
                res[i] = nums.size();
            } else {
                while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    res[i] = nums.size();
                    stk.push(i);
                } else {
                    res[i] = stk.top();
                    stk.push(i);
                }
            }
        }
        return res;
    }

    int hist_size(vector<int> nums, vector<int> nseVal, vector<int> pseVal) {

        int mx = 0;
        for (int i = 0; i < nseVal.size(); i++) {
            int val = (nseVal[i] - pseVal[i] - 1) * nums[i];
            mx = max(mx, val);
        }
        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int mxHist = 0;
        for (int i = 0; i < matrix.size(); i++) {
            int hist = hist_size(prefSome(matrix)[i], nse(prefSome(matrix)[i]),
                                 pse(prefSome(matrix)[i]));
            mxHist = max(mxHist, hist);
        }
        return mxHist;
    }
};