class Solution {
public:
//merge the aar
//optimize 1st swapping the elements 

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //store smaller elements in arr1 and larger in arr 2
        int left=m-1,right=0;
        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;right++;
            }else break;
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.begin()+n);
        for(int i=0;i<n;i++){
        nums1[m+i]=nums2[i];
        }
    }
};