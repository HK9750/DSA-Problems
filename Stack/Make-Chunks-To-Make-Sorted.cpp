// Leetcode 769. Max Chunks To Make Sorted

// Stack Method

class Solution
{

public:
    int maxChunksToSorted(vector<int> &arr)
    {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!st.empty() && st.top() > arr[i])
            {
                int top = st.top();
                while (!st.empty() && st.top() > arr[i])
                {
                    st.pop();
                }
                st.push(top);
            }
            else
            {
                st.push(arr[i]);
            }
        }
        return st.size();
    }
};