class Solution {
public:
    bool isAvailable(vector<int>&v,int target){

    int left=0;
    int right=v.size()-1;

    while(left<=right){

        int mid=left+(right-left)/2;

        if(v[mid]==target){
            return true;
        }else if(v[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    return false;

}

 bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int left=0;
    int right=matrix.size()-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(isAvailable(matrix[mid],target)){
            return true;
        }else if(matrix[mid][0]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }

    }

    return false;

 }
};