class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);
        for (int i = n-1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] > arr[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long minSum(vector<int>& arr) {
        auto prev = prevSmallerElement(arr);
        auto next = nextSmallerElement(arr);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int previ = prev[i];
            int nexti = (next[i] == -1 ? arr.size() : next[i]);
            long long left = i - previ;
            long long right = nexti - i;
            sum += left * right * 1LL * arr[i];
        }
        return sum;
    }

    vector<int> nextGreaterElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);
        for (int i = n-1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] < arr[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && arr[st.top()] <= arr[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long maxSum(vector<int>& arr) {
        auto prev = prevGreaterElement(arr);
        auto next = nextGreaterElement(arr);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int previ = prev[i];
            int nexti = (next[i] == -1 ? arr.size() : next[i]);
            long long left = i - previ;
            long long right = nexti - i;
            sum += left * right * 1LL * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return maxSum(nums) - minSum(nums);
    }
};