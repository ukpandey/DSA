#include<iostream>
#include<vector>
using namespace std;

double medianBetter(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;

    int cnt = 0, i = 0, j = 0;
    int ind1el = -1, ind2el = -1;

    // Traverse both arrays like merge step of merge sort
    while (i < n1 && j < n2) {

        // Check which element is smaller and pick it
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            i++;
        } else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            j++;
        }
        cnt++;
    }

    // Copy remaining elements from first array if any
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }

    // Copy remaining elements from second array if any
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    // Return median depending on even or odd size
    if (n % 2 == 1) return (double)ind2el;
    return (ind1el + ind2el) / 2.0;
}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int low=0, high=n;
        int left = (n+m+1)/2;
        while(low<=high){
            int l1=INT32_MIN, l2=INT32_MIN;
            int r1=INT32_MAX, r2=INT32_MAX;
            int mid1 = low+(high-low)/2;
            int mid2 = left-mid1;
            if(mid1<n) r1 = nums1[mid1];
            if(mid2<m) r2 = nums2[mid2];
            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];
            
            if(l1<=r2 && l2<=r1){
                if((n+m)%2 == 1){
                    return max(l1,l2);
                }
            return (double) (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else if(l2>r1){
                low = mid1+1;
            }
        }
        return 0;
    }

int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout<<findMedianSortedArrays(a,b);
    return 0;
}