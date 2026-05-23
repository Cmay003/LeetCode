class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n;
        int gap = (len/2)+(len%2);
        while(gap>0){
            int l=0;
            int r=l+gap;
            while(r<len){
                if(l<m && r>=m){
                    if(nums1[l]>nums2[r-m]){
                        swap(nums1[l],nums2[r-m]);
                    }
                }
                else if(l>=m && r>=m){
                    if(nums2[l-m]>nums2[r-m]){
                        swap(nums2[l-m],nums2[r-m]);
                    }
                }
                else{
                    if(nums1[l]>nums1[r]){
                        swap(nums1[l],nums1[r]);
                    }
                }
                l++;
                r++;
            }            
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }
        for(int i=0; i<n; i++){
            nums1[m+i]=nums2[i];
        }
    }
};