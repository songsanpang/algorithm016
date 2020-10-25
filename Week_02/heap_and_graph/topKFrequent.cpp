class Solution {
    class cmp {
        public: //必须为public ，class默认为private，对优先队列来说排序规则不可见，这种错也太难检查了
        bool operator () (const pair<int,int>& p1 ,const pair<int,int>& p2) {
            return p1.second > p2.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        // for(auto i : nums) cnt[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> qu;

        for(unordered_map<int,int>::iterator i = cnt.begin(); i != cnt.end();++i) {
            qu.push(*i);
            if(qu.size()>k) qu.pop();
        }
        // while(qu.size() > k) qu.pop();
        vector<int> res;
        while(!qu.empty()) {
            res.push_back(qu.top().first);
            qu.pop();
        }
        return res;    
    }
};










