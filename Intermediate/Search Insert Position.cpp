class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        if(target>arr[arr.size()-1])
            return arr.size();
        else if(target<arr[0])
            return 0;
        int low=0,high=arr.size()-1;
        while(low<=high)
        {
            if(low==high)
            {
                if(arr[low]>=target)
                    return low;
                else if(arr[low]<target)
                    return low+1;
            }
            int mid=(low+high)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        if(arr[low]>target)
            return low;
        else
            return low+1;
    }
};
