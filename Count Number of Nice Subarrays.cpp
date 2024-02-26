class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum=0,ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i]&1?1:0;
            ans+= mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};

/*
	Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
	Return the number of nice sub-arrays.
	
	Example 1:
	Input: nums = [1,1,2,1,1], k = 3
	Output: 2
	Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
	
	Example 2:
	Input: nums = [2,4,6], k = 1
	Output: 0
	Explanation: There is no odd numbers in the array.
	
	Example 3:
	Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
	Output: 16
	
	T.C : O(n)
	S.C : O(n)
*/
