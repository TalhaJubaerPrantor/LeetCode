class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
    vector<int>temp(nums.begin(),nums.end());
    temp.insert(temp.end(),nums.begin(),nums.end());

    vector<int>res(nums.size(),-1);
    stack<int>st;
    for(int i=nums.size()-1;i>=0;i--){
        for(int j=i;j<i+nums.size();j++){
            if( temp[i]<temp[j] ){
                res[i]=temp[j];
                break;
            }
        }
    }
    return res;
}
};