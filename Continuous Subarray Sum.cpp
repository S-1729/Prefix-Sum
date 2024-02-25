class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2)
                    return true;
            }
            else
                mp[rem]=i;
        }
        return false;
    }
};

/*
	Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

	A good subarray is a subarray where:
		1.its length is at least two, and
		2.the sum of the elements of the subarray is a multiple of k.
	Note that:
		1.A subarray is a contiguous part of the array.
		2.An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

	Example 1:
	Input: nums = [23,2,4,6,7], k = 6
	Output: true
	Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

	Example 2:
	Input: nums = [23,2,6,4,7], k = 13
	Output: false

	T.C : O(n)
	S.C : O(n)
*/
