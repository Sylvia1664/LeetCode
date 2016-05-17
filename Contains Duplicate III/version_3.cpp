class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 | k <1)
            return false;

        int i,key;
        unordered_map<int, int> dict;

        for(i =0; i < nums.size(); i++)
        {
            key = nums[i]/max(1,t);
            //map::iterator it;
            if( (dict.find(key) != dict.end() && abs(nums[i] - dict[key]) <= t) ||
                (dict.find(key-1) != dict.end() && abs((long)nums[i] - (long)dict[key-1]) <= t) ||
                (dict.find(key+1) !=dict.end() && abs(nums[i] - dict[key+1]) <= t))
            {                           
                return true;
            }

            //dict[key] = nums[i];
            dict.insert(pair<int, int>(key,nums[i]));

            if(i >= k)
            {   
                dict.erase(nums[i-k]/max(1,t)); //ɾ�����ڴ�С֮��ļ�ֵ
            }

        }
        return false;       
    }
};