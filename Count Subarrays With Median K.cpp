class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        bool found=false;
        for(int i=0;i<n;i++){
            if(nums[i]<k)
                sum--;
            else if(nums[i]>k)
                sum++;
            else if(nums[i]==k)
                found=true;
            
            if(found)
                ans+= mp[sum]+mp[sum-1];
            else
                mp[sum]++;
        }
        return ans;
    }
};


//Code-2
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),ind=0;
        while(nums[ind]!=k)
            ind++;
        
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=ind+1;i<n;i++){
            sum+=(nums[i]>k?1:-1);
            mp[sum]++;
        }
        
        int ans=mp[0]+mp[1];
        sum=0;
        for(int i=ind-1;i>=0;i--){
            sum+=(nums[i]>k?1:-1);
            ans+=mp[-sum]+mp[-sum+1];
        }
        return ans;
    }
};


/*
	You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
	Return the number of non-empty subarrays in nums that have a median equal to k.
	Note:
		1.The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
		For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
		2.A subarray is a contiguous part of an array.

	Example 1:
	Input: nums = [3,2,1,4,5], k = 4
	Output: 3
	Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].
	
	Example 2:
	Input: nums = [2,3,1], k = 3
	Output: 1
	Explanation: [3] is the only subarray that has a median equal to 3.

	T.C : O(n)
	S.C : O(n)
*/
