#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int s=0;
    int e = nums.size() - 1;
    while(s <= e){
        int mid = s + (e-s)/2;
        
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] - nums[s] > 0){
            if(nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        else if(nums[mid] - nums[s] < 0){
            if(nums[mid] < target && nums[e] >= target)
                s = mid +1;
            else
                e = mid - 1;
        }
        
    }
     return -1;
 }

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    cout << search(arr,0)<<endl;
    return 0;
}