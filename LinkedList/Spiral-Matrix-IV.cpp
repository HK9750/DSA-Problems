// Leetcode : 2326 Spiral Matrix IV
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;
        int row = 0, col = 0;
        while (head)
        {
            matrix[row][col] = head->val;
            head = head->next;

            int newRow = row + direction[directionIndex].first;
            int newCol = col + direction[directionIndex].second;

            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || matrix[newRow][newCol] != -1)
            {
                directionIndex = (directionIndex + 1) % 4;
                newRow = row + direction[directionIndex].first;
                newCol = col + direction[directionIndex].second;
            }

            row = newRow;
            col = newCol;
        }
        return matrix;
    }
};

// Explaination

// The idea is to create a matrix of size m x n and fill it with -1.

//  We create a vector of pairs (x,y) to represent direction that starts from right that is (0,1), down (1,0), left (0,-1) and up (-1,0).

// First we set the directionIndex to 0 because first we go to right side, row and col to 0.

// We iterate through the linked list and fill the matrix with the values of the linked list.

// In the while loop first we put in the value and then calculate the new row and new col based on the conditions.

// If the new row and new col are out of bounds or the matrix[newRow][newCol] is not equal to -1 then we change the directionIndex to the next direction that is (directionIndex + 1) % 4.

// We update the row and col to the new row and new col.

// While loop continues until the linked list is empty i.e head is null.

// We return the matrix.