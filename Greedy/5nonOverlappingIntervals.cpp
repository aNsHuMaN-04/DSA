// Approach 1 : Sort by Start Time and then check for overlaps and remove the one with longer end time

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int removals = 0;

        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] < prevEnd) {

                removals++;

                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else {
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};

// Approach 2 : Sort by End Time and then check for overlaps and check which intervals we can keep and then return total intervals - count of intervals we can keep
// Extension of n meetings in a room problem
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 1;
        int lastEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] >= lastEnd) {

                count++;
                lastEnd = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};