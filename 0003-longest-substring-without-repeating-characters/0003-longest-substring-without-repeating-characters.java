class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer>mpp=new HashMap<>();
        int left=0;int right=0;
        int len=0;
        while(right<s.length()){
            if(mpp.containsKey(s.charAt(right)))
                left=Math.max(mpp.get(s.charAt(right))+1,left);
            //update the latest right index of the character
            mpp.put(s.charAt(right),right);
            len=Math.max(len,right-left+1);
            right++;
        }
        return len;
    }
}