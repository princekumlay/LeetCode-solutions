class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Convert all four dates to day-of-the-year integers
        int aStart = convertToDays(arriveAlice);
        int aEnd = convertToDays(leaveAlice);
        int bStart = convertToDays(arriveBob);
        int bEnd = convertToDays(leaveBob);
        
        // Find the latest arrival and earliest departure among both
        int latestArrival = max(aStart, bStart);
        int earliestDeparture = min(aEnd, bEnd);
        
        // Calculate overlapping days (if valid)
        if (latestArrival <= earliestDeparture) {
            return earliestDeparture - latestArrival + 1;
        }
        
        return 0;
    }

private:
    int convertToDays(string date) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonths[i];
        }
        totalDays += day;
        
        return totalDays;
    }
};