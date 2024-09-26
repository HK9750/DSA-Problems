// Leetcode 729. My Calendar I

class MyCalendar
{
public:
    vector<pair<int, int>> books;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto p : books)
        {
            if (max(p.first, start) < min(p.second, end))
                return false;
        }
        books.push_back({start, end});
        return true;
    }
};

// Explanation: We can use a vector of pairs to store the start and end of the booked slots. We can then iterate over the vector and check if the new slot overlaps with any of the existing slots. If it does, we return false. Otherwise, we add the new slot to the vector and return true.