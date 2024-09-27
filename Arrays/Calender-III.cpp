// Leetcode 732. My Calendar III
// A leetcode hard problem, but very similar to the previous one and can be solved using the same line sweep algorithm.

class MyCalendarThree
{
public:
    map<int, int> eventCount;

    MyCalendarThree() {}

    int book(int start, int end)
    {
        eventCount[start]++;
        eventCount[end]--;

        int ongoingEvents = 0;
        int maxEvents = 0;
        for (auto &[time, change] : eventCount)
        {
            ongoingEvents += change;
            maxEvents = max(maxEvents, ongoingEvents);
        }
        return maxEvents;
    }
};

// Explanation:

// We will keep a map of time and change in the number of events at that time.
// We will increase the number of events at the start time and decrease the number of events at the end time.
// We will keep track of the number of ongoing events at any time.
// We will also keep track of the maximum number of ongoing events at any time.
// We will return the maximum number of ongoing events at any time.
// This is a very simple problem and can be solved using the same line sweep algorithm as the previous one. The only difference is that we need to keep track of the maximum number of ongoing events at any time.
