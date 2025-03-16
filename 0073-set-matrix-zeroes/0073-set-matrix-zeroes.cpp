class Solution {
public:
//optimal O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int colZero=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //mark the col
                    matrix[i][0]=0;
                    //mark the row
                    if(j!=0)
                        matrix[0][j]=0;
                    else 
                        colZero=0;
                }
            }
        }
        //start from the 1st row and 1st col
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                //check whether the element is 0 or not 
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        //check for the first row (based on the first element of the matrix)
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        //checl the first col based ont he colZero element
        if(colZero==0){
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }

    }
};