class Solution {
public:
    //���رȽ�
    static bool cmp(Interval &a, Interval &b) { 
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        //ȥ���������
        if(intervals.size() == 0) 
            return res;
        //��������������
        sort(intervals.begin(), intervals.end(), cmp); 
        //�����һ������
        res.push_back(intervals[0]); 
        //�����������䣬�鿴�Ƿ���ĩβ���ص�
        for(int i = 1; i < intervals.size(); i++){ 
            //�������ص������½�β
            if(intervals[i].start <= res.back().end) 
                res.back().end = max(res.back().end, intervals[i].end);
            //����û���ص���ֱ�Ӽ���
            else 
                res.push_back(intervals[i]);
        }
        return res;
    }
};
