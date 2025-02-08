// Leetcode 2349. Design A Number Container System

class NumberContainers
{
public:
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (idxToNum.count(index))
        {
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index);
            if (numToIdx[prevNum].empty())
            {
                numToIdx.erase(prevNum);
            }
        }

        idxToNum[index] = number;
        numToIdx[number].insert(index);
    }

    int find(int number)
    {
        if (numToIdx.count(number))
        {
            return *numToIdx[number].begin();
        }

        return -1;
    }
};

// Explaination:

// We are given a class NumberContainers with two functions change and find. The change function takes two integers index and number as input and changes the number at the given index to the given number. The find function takes an integer number as input and returns the index of the first occurrence of the given number in the container. If the number is not present in the container, the function returns -1.
// We can solve this problem using a hashmap and a set. We will maintain two hashmaps idxToNum and numToIdx. The idxToNum hashmap will store the index as the key and the number as the value. The numToIdx hashmap will store the number as the key and a set of indices as the value.
// In the change function, we will first check if the given index is present in the idxToNum hashmap. If it is present, we will remove the index from the set corresponding to the previous number in the numToIdx hashmap. If the set becomes empty after removing the index, we will remove the number from the numToIdx hashmap. We will then update the idxToNum hashmap with the new number at the given index and add the index to the set corresponding to the new number in the numToIdx hashmap.
// In the find function, we will check if the given number is present in the numToIdx hashmap. If it is present, we will return the index of the first occurrence of the number by taking the first element from the set corresponding to the number. If the number is not present in the numToIdx hashmap, we will return -1.
