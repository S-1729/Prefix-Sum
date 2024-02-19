class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1,ans=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0)
                prefix=1;
            if(suffix==0)
                suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;
    }
};

/*
	Given an integer array nums, find a subarray that has the largest product, and return the product.
	The test cases are generated so that the answer will fit in a 32-bit integer.

	Example 1:
	Input: nums = [2,3,-2,4]
	Output: 6
	Explanation: [2,3] has the largest product 6.
	
	Example 2:
	Input: nums = [-2,0,-1]
	Output: 0
	Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
	
	T.C : O(n)
*/
