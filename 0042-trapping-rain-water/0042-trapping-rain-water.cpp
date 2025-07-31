class Solution {
public:
    vector<int>leftMax(vector<int>&height){
    vector<int>prefMax(height.size(),0);
    prefMax[0]=height[0];
    for(int i=1;i<height.size();i++){
        prefMax[i]=max(prefMax[i-1],height[i]);
    }
    return prefMax;
}

vector<int>rightMax(vector<int>&height){
    vector<int>suffMax(height.size(),0);
    suffMax[height.size()-1]=height[height.size()-1];
    for(int i=height.size()-2;i>=0;i--){
        suffMax[i]=max(suffMax[i+1],height[i]);
    }
    return suffMax;
}

int trap(vector<int>& height){
    vector<int>prefMax=leftMax(height);
    vector<int>suffMax=rightMax(height);
    int water=0;

    for(int i =1;i<height.size()-1;i++){
        if(height[i]<prefMax[i] && height[i]<suffMax[i] ){
            water+=min(prefMax[i],suffMax[i])-height[i];
        }
    }
    return water;
}
};