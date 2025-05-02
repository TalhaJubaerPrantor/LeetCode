class Solution {
public:
    int indxI(vector<vector<int>>& mat, int j) {

        int mx = INT_MIN;
        int idx = -1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][j] > mx) {
                mx = mat[i][j];
                idx = i;
            }
        }

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int left = 0;
        int right = mat[0].size() - 1;
        vector<int> ans(2, 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = indxI(mat, mid);
            if (mat[i][mid] < mat[i][mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right < 0)
            right = 0;
        if (left < 0)
            left = 0;
        ans[0] = left;
        ans[1] = right + 1;
        return ans;
    }
};