class Solution{
    private:
      int  binarySearch(vector<int>& mat, int target){
                int n = mat.size(); 
        int low = 0, high = n - 1;
        while(low<=high){
           int mid = low +(high -low)/2;
            if(mat[mid]== target) return true;
            else if(mat[mid]>target )high = mid -1;
            else low = mid +1;
        } return false;
        }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++){
               bool flag = binarySearch(matrix[i],target);
               if(flag) return true;
        }
      
        return false; 
        
       

    }
};