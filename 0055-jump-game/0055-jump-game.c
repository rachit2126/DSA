bool canJump(int* nums, int numsSize) {
     int  maxind = 0;
             for(int i=0;i<numsSize;i++){
                if(i>maxind){
                    return false;
                }
                maxind= fmax(maxind,i+nums[i]);
             }     
             return true;
}