class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        vector<int> ng(nums2.size(), 0);

        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(nums2[i]);
                ng[i] = -1;
            } else {
                while (!st.empty() && nums2[i] > st.top()) {
                    st.pop();
                }
                if (st.empty()) {
                    ng[i] = -1;
                    st.push(nums2[i]);
                } else {
                    ng[i] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    res.push_back(ng[j]);
                }
            }
        }

        return res;
    }
};