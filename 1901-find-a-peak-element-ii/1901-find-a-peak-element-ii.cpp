class Solution {
public:
    int maxElement(vector<vector<int>>& arr, int col) {
        int n = arr.size();
        int idx = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i][col] > arr[idx][col])
                idx = i;
        }

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            int row = maxElement(mat, mid);

            int left = (mid > 0) ? mat[row][mid - 1] : INT_MIN;
            int right = (mid < m - 1) ? mat[row][mid + 1] : INT_MIN;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};

            else if (left > mat[row][mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};