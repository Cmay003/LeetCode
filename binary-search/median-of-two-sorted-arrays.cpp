#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int count=0;
        int n1=nums1.size();
        int n2=nums2.size();
        int elem1=-1, elem2=-1;
        int n=(n1+n2);
        int idx2=n/2, idx1=idx2-1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count==idx1) elem1=nums1[i];
                if(count==idx2) elem2=nums1[i];
                i++;
                count++;
            }
            else{
                if(count==idx1) elem1=nums2[j];
                if(count==idx2) elem2=nums2[j];
                j++;
                count++;
            }
        }
        while(i<n1){
            if(count==idx1) elem1=nums1[i];
            if(count==idx2) elem2=nums1[i];
            i++;
            count++;
        }
        while(j<n2){
            if(count==idx1) elem1=nums2[j];
            if(count==idx2) elem2=nums2[j];
            j++;
            count++;
        }
        if(n%2==0){
            return (elem1+elem2)/2.0;
        }
        else{
            return elem2;
        }
    }
};