class Solution {
public:

   
int sum(vector<int>&nums,int mid){

    int s=0;

    for(int i=0;i<nums.size();i++){
        s+=ceil((double)nums[i]/mid);
    }

    return s;

}

int smallestDivisor(vector<int>& nums, int threshold) {

    int left=INT_MAX;
    int right=INT_MIN;

    for(int i=0;i<nums.size();i++){
        left=1;
        right=max(right,nums[i]);
    }



    while(left<=right){

        int mid=left+(right-left)/2;

        if(sum(nums,mid)<=threshold){
           right=mid-1;
        }else{
            left=mid+1;
        }

    }

    return left;

}

};