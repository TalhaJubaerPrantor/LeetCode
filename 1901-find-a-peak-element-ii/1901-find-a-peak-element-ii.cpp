class Solution {
public:
    int findMax(vector<vector<int>>& mat, int col){
        int maxRow=0;
        for(int i=0;i<mat.size();i++){
            maxRow= mat[i][col]>=mat[maxRow][col] ? i: maxRow;
        }
        return maxRow;
    }
    bool predicate(int midCol,vector<vector<int>>& mat, int leftCol, int rightCol ){
        int maxRow=findMax(mat,midCol);
        bool rejectRight= midCol+1 <= rightCol &&mat[maxRow][midCol+1] < mat[maxRow][midCol];   
        return rejectRight;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int leftCol=0;
        int rightCol=mat[0].size()-1;
        while(leftCol<rightCol){
            int midCol= leftCol + (rightCol-leftCol)/2;
            if(predicate(midCol,mat,leftCol,rightCol)){
                rightCol=midCol;
            }
            else{
                leftCol=midCol+1;
            }
        }                        
        int maxRow=findMax(mat,leftCol);
        return vector<int>{maxRow, leftCol};

    }

};