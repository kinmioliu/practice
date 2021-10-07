class NumMatrix {
    vector<vector<int>> matrixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) : matrixSum(matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            int curLineSum = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                curLineSum += matrix[i][j];
                if (i == 0) {
                    matrixSum[0][j] = curLineSum;
                } else {
                    matrixSum[i][j] = matrixSum[i - 1][j] + curLineSum;
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return matrixSum[row2][col2];
        } else if (row1 == 0 && col1 != 0) {
            return matrixSum[row2][col2] - matrixSum[row2][col1 - 1];
        } else if (row1 != 0 && col1 == 0){
            return matrixSum[row2][col2] - matrixSum[row1 - 1][col2];
        } else {
            return matrixSum[row2][col2] - matrixSum[row1 - 1][col2] - matrixSum[row2][col1 - 1] + matrixSum[row1 - 1][col1 - 1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
