class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int product=1;
        for(int i=0;i<n;i++){
            product*=nums[i];
            ans.push_back(product);
        }
        
        product=1;
        for(int i=n-1;i>0;i--){
            ans[i]=ans[i-1]*product;
            product*=nums[i];
        }
        ans[0]=product;
        return ans;
    }
};

/*
	Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
	The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
	You must write an algorithm that runs in O(n) time and without using the division operation.

	Example 1:
	Input: nums = [1,2,3,4]
	Output: [24,12,8,6]
	
	Example 2:
	Input: nums = [-1,1,0,-3,3]
	Output: [0,0,9,0,0]
	
	T.C : O(2n)
*/
