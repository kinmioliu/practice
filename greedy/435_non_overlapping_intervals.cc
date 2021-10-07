class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removeCnt = 0;
        sort(intervals.begin(), intervals.begin(),[](const vector<int>& l, const vector<int>& r){
                if (l[0] < r[0]) {
                    return true;
                } else if (l[0] == r[0]) {
                    return (l[1] - l[0]) <= (r[1] - r[0]);
                } else {
                    return false;
                }
                });
        vector<int> top = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlap(top, intervals[i])) {
                removeCnt++;
                continue;
            }
            top = intervals[i];
        }
        return removeCnt;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        typedef vector<int> INTERVAL;
        struct IntervalLink {
            int overlapCnt;
            list<INTERVAL> overlapedIntervals;
        };
        map<INTERVAL, IntervalLink> mapIntervals;
        sort(intervals.begin(), intervals.begin(),[](const vector<int>& l, const vector<int>& r){
                if (l[0] < r[0]) {
                    return true;
                } else if (l[0] == r[0]) {
                    return (l[1] - l[0]) <= (r[1] - r[0]);
                } else {
                    return false;
                }
                });
        auto last = unique(interval.begin(), interval.end());
        int eraseCnt = intervals.end() - last;
        intervals.erase(last, intervals.end());
        
        // create link map
        for(int i = 0; i < intervals.size() - 1; i++) {
            auto newInterval = mapIntervals.insert(make_pair(intervals[i], {0, list<INTERVAL>()}));
            for (int j = i + 1; j < intervals.size(); j++) {
                if (isOverlap(intervals[i], intervals[j])) {
                    newInterval->second.overlapCnt++;
                    newInterval->second.overlapedIntervals.push_back(intervals[j]);
                    auto linkInterval = mapIntervals.find(intervals[j]);
                    if (linkInterval == mapIntervals.end()) {
                        linkInterval = mapIntervals.insert(make_pair(intervals[j], {0, list<INTERVAL>()}));
                    }
                    linkInterval->second.overlapCnt++;
                    linkInterval->second.overlapedIntervals.push_back(intervals[i]);
                    continue;
                }
                break; // if current interval don't overlap, then the left will not overlap
            }
        }
        for (auto& link : mapIntervals) {
            cout << link->first << ":" << link->second.overlapCnt;
        }
        cout << endl;
    }
private:
    inline bool isOverlap(const vector<int>& l, const vector<int>& r)const {
        return ((l[1] - l[0]) + (r[1] - r[0])) > (r[1] - l[0])
    }
    ostream &operator<<(ostream &os, const vector<int> &interval){
        os << "(" <<  interval[0] << "," << interval[1] << ")";
        return os;
    }
};
