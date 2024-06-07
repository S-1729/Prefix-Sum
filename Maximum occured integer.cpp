class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int>prefix(maxx+2,0);
        for(int i=0;i<n;i++){
            prefix[l[i]]++;
            prefix[r[i]+1]--;
        }
        int cnt=0,ans=0;
        for(int i=1;i<(maxx+2);i++){
            prefix[i]+=prefix[i-1];
            if(prefix[i]>cnt){
                cnt=prefix[i];
                ans=i;
            }
        }
        return ans;
        
    }
};

/*
    Given n integer ranges, the task is to return the maximum occurring integer in the given ranges. If more than one such integer exists, return the smallest one.
    The ranges are in two arrays l[] and r[].  l[i] consists of the starting point of the range and r[i] consists of the corresponding endpoint of the range & a maxx which is the maximum value of r[].
      For example, consider the following ranges.
      l[] = {2, 1, 3}, r[] = {5, 3, 9)
      Ranges represented by the above arrays are.
      [2, 5] = {2, 3, 4, 5}
      [1, 3] = {1, 2, 3}
      [3, 9] = {3, 4, 5, 6, 7, 8, 9}
    The maximum occurred integer in these ranges is 3.
    
    Examples :
    Input: n = 4, l[] = {1,4,3,1}, r[] = {15,8,5,4}, maxx = 15
    Output: 4
    Explanation: The given ranges are [1,15] [4, 8] [3, 5] [1, 4]. The smallest number that is most common or appears most times in the ranges is 4.
    
    Input: n = 5, l[] = {1,5,9,13,21}, r[] = {15,8,12,20,30}, maxx = 30
    Output: 5
    Explanation: The given ranges are [1, 15] [5, 8] [9, 12] [13, 20] [21, 30]. The smallest number that is most common or appears most times in the ranges is 5.

    T.C : O(n+maxm)
    S.C : O(maxm)
*/
