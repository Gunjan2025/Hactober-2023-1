class Solution {
public:
    typedef vector<int>::iterator iterator;
    int sort_count(iterator l, iterator r)
    {
        if (r - l <= 1)
            return 0;
        iterator m = l + (r - l) / 2;
        long two = 2;   //for overflows during multiplication
        int cnt_left = sort_count(l, m);
        int cnt_right = sort_count(m, r);
        int cnt = 0;
        for (iterator it=l, jt=m; it<m; it++)
        {
            //DON'T need to loop from m to r every time
            //O(n) instead of O(n^2)
            while ( jt<r && (*it) > two * (*jt) ) jt++;
            cnt += (jt - m);
        }
        inplace_merge(l, m, r);
        return cnt + cnt_left + cnt_right;
    }
        
    int reversePairs(vector<int>& nums) {
        return sort_count(nums.begin(), nums.end());
    }
};
