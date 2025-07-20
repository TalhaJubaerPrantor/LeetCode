class MinStack {
    vector<pair<int,int>> st;
public:
    MinStack() {

    }

    void push(int val) {
        if(st.size()==0){
            st.push_back({val,val});
        }else{
            st.push_back({val,min(val,st[st.size()-1].second)});
        }
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st[st.size()-1].first;
    }

    int getMin() {
        return st[st.size()-1].second;
    }
};