/*

Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int LeftSum;
        int RightSum;
        
        //if the nums.size is == 1, means that you are on one edge of the array
        int len=nums.size();
        if(len==1)
            return 0;
        
        //Size of this is the size of the nums
        int sum[len];
        sum[0]=nums[0];
        
        //Calculate total sum of numbers
        for(int i=1;i<len;i++)
        {
            sum[i]=nums[i]+sum[i-1];
        }
        
        //Calculate Left and Right sums
        for(int i=0;i<len;i++)
        {
            LeftSum=sum[i]-nums[i];
            RightSum=sum[len-1]-sum[i];

        if(LeftSum==RightSum)
            return i;
        }
        return -1;
        }
    
};
