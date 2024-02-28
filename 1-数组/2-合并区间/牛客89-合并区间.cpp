class Solution {
public:
    //重载比较
    static bool cmp(Interval &a, Interval &b) { 
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        //去除特殊情况
        if(intervals.size() == 0) 
            return res;
        //按照区间首排序
        sort(intervals.begin(), intervals.end(), cmp); 
        //放入第一个区间
        res.push_back(intervals[0]); 
        //遍历后续区间，查看是否与末尾有重叠
        for(int i = 1; i < intervals.size(); i++){ 
            //区间有重叠，更新结尾
            if(intervals[i].start <= res.back().end) 
                res.back().end = max(res.back().end, intervals[i].end);
            //区间没有重叠，直接加入
            else 
                res.push_back(intervals[i]);
        }
        return res;
    }
};
