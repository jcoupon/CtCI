#include <iostream>
#include <vector>


using namespace std;


int finPivot(const vector<int> & nums){
    int lo = 0;
    int hi = nums.size()-1;

    while(nums[lo] > nums[hi]){
        int mid = lo + (hi-lo)/2;

        if(nums[mid] > nums[hi]){
            lo = mid+1;
        }
        else{
            hi = mid;
        }

    }

    return lo;
}

int binarySearch(const vector<int> & nums, int lo, int hi, int target){
    
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        if(nums[mid] == target){
            return mid;
        }
        
        if(nums[mid] > target){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    return -1;

}

int findRotated(const vector<int> & nums, int target){

    int pivot = finPivot(nums);
    
    if(target >= nums[pivot]){
        return binarySearch(nums, pivot, nums.size()-1, target);
    }
    else{
        return binarySearch(nums, 0, pivot-1, target);
    }
    return -1;

}

int main(){


    // expected: 11
    vector<int> nums1 = {15, 16, 20, 25, 30, 1, 3, 4, 5, 7, 10, 14};
    cout << findRotated(nums1, 14) << endl;

    // expected: 7
    vector<int> nums2 = {15, 16, 20, 25,  1, 3, 4, 5, 7, 10, 14};
    cout << findRotated(nums2, 5) << endl;

    // expected: 3
    vector<int> nums3 = {1, 3, 4, 5, 7, 10, 14};
    cout << findRotated(nums3, 5) << endl;

    // expected: any
    vector<int> nums4 = {1, 1, 1, 1, 1, 1, 1};
    cout << findRotated(nums4, 1) << endl;

    // expected: -1
    vector<int> nums5 = {1, 3, 4, 5, 7, 10, 14};
    cout << findRotated(nums5, 6) << endl;

    // expected: -1
    vector<int> nums6 = {2, 2, 4, 5, 7, 2};
    cout << findRotated(nums6, 5) << endl;


    return 0;
}
