class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();int n2=nums2.size();
        int i=0,j=0;
        vector<int>merge;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j])
                merge.push_back(nums1[i++]);
            else 
                merge.push_back(nums2[j++]);
        }
        //add the remaining elements
        while(i<n1)merge.push_back(nums1[i++]);
        while(j<n2)merge.push_back(nums2[j++]);
        int n=n1+n2;
        if(n%2==1)return double(merge[n/2]);
        else return double(((double)merge[n/2] + (double)merge[n/2-1])/2);
    }
};