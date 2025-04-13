class Solution {
    //better soln: hash array
    public int missingNumber(int[] nums) {
        //use a hash array 
        int n=nums.length;
        int[] hash=new int[n+1];
        for(int num :nums){
            hash[num]++;
        }
        for(int i=0;i<=n;i++){
            if(hash[i]==0)return i;
        }
        return -1;
    }
}
