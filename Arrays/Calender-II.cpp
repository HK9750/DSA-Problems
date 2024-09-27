// Leetcode 731. My Calendar II
// Line Sweep Algorithm

class MyCalendarTwo
{
public:
    map<int, int> eventCount;

    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        eventCount[start]++;
        eventCount[end]--;

        int ongoingEvents = 0;
        for (auto &[time, change] : eventCount)
        {
            ongoingEvents += change;
            if (ongoingEvents > 2)
            {
                eventCount[start]--;
                eventCount[end]++;
                return false;
            }
        }
        return true;
    }
};

// Explanation:

// We will keep a map of time and change in the number of events at that time.
// We will increase the number of events at the start time and decrease the number of events at the end time.
// We will keep track of the number of ongoing events at any time.
// If the number of ongoing events is greater than 2, we will revert the changes and return false.
// Otherwise, we will return true.
