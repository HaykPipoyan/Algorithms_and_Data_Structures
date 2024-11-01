class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = m - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]){
                int rowStart = 0;
                int rowEnd = n - 1;
                while(rowStart <= rowEnd){
                    int rowMid = rowStart + (rowEnd - rowStart) / 2;
                    if(target == matrix[mid][rowMid]){
                        return true;
                    } else if(target < matrix[mid][rowMid]){
                        rowEnd = rowMid - 1;
                    } else {
                        rowStart = rowMid + 1;
                    }
                }
                return false;
            } else if(target < matrix[mid][0]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};
