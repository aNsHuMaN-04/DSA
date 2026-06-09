#include <bits/stdc++.h>
using namespace std;

// Class to hold solution logic
class Solution {
public:
    // Function to get all meetings that can be scheduled
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        // Store meetings as (end_time, start_time, original_index)
        vector<tuple<int, int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            // i+1 for 1-based indexing
            meetings.push_back({end[i], start[i], i + 1}); 
           
        }

        // Sort by end time
        sort(meetings.begin(), meetings.end());

        vector<int> result; // To store meeting indices
        int lastEnd = -1;

        // Traverse sorted meetings
        for (auto& m : meetings) {
            int e = get<0>(m);
            int s = get<1>(m);
            int idx = get<2>(m);

            // If meeting starts after last one ends
            if (s > lastEnd) {
                // Store index
                result.push_back(idx); 
                // Update last end time
                lastEnd = e; 
            }
        }
        return result;
    }
};

// if just want count of meetings and not the order

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {

        int n = start.size();

        vector<pair<int, int>> meetings;

        for(int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        sort(meetings.begin(), meetings.end());

        int count = 0;
        int lastEnd = -1;

        for(auto it : meetings) {

            int e = it.first;
            int s = it.second;

            if(s > lastEnd) {
                count++;
                lastEnd = e;
            }
        }

        return count;
    }
};