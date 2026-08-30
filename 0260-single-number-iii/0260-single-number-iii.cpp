class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
		 int n = nums.size();
         long XOR =0;
         for(int i=0;i<n;i++){
            XOR ^=nums[i];
         }
         int rm = (XOR &(XOR -1))^ XOR;
         int XOR1=0,XOR2 =0;
            for(int i=0; i < n; i++) {
                  if(nums[i] & rm) {
                XOR1 = XOR1 ^ nums[i];
            }
            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }
          if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
		}
};