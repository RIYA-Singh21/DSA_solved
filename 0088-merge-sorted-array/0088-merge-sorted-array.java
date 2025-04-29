class Solution {
    void swap(int[] nums1, int ind1, int[] nums2, int ind2){
        if(nums1[ind1] > nums2[ind2]){
            int temp = nums1[ind1];
            nums1[ind1] = nums2[ind2];
            nums2[ind2] = temp;
        }
    }

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = gap;

            while (right < len) {
                // both in nums1
                if (left < m && right < m) {
                    if (nums1[left] > nums1[right]) {
                        int temp = nums1[left];
                        nums1[left] = nums1[right];
                        nums1[right] = temp;
                    }
                }
                // left in nums1, right in nums2
                else if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        int temp = nums1[left];
                        nums1[left] = nums2[right - m];
                        nums2[right - m] = temp;
                    }
                }
                // both in nums2
                else {
                    if (nums2[left - m] > nums2[right - m]) {
                        int temp = nums2[left - m];
                        nums2[left - m] = nums2[right - m];
                        nums2[right - m] = temp;
                    }
                }

                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
}
