class Solution {
public:
   
    int check(vector<int>&nums,int mid){

    int sum=0;
    int flag=1;

    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }else{
            flag++;
            sum=nums[i];
        }
    }
    return flag;
}

int splitArray(vector<int>& nums, int k) {

    int left=0;
    int right=0;

    for(int i=0;i<nums.size();i++){

            right+=nums[i];
    }

    while(left<=right){

        int mid=left+(right-left)/2;

        if(check(nums,mid)>k){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    return left;

}

};