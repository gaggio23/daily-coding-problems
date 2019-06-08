/* Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
*/

// Solution with hash table (unordered set)

#include <iostream>
#include <vector>
#include <unordered_set>

bool is_k_summable(const std::vector<int>& list, const int k)
{
    // Trivial case:
    if(list.empty() || (list.size() == 1)) return false;

    std::unordered_set<int> hash_table;
    for(const int i : list)
    {
        // If the element is already in the hash table
        if((hash_table.find(i) != hash_table.end()) && ((i * 2) == k)) return true;
        else
        {
            hash_table.insert(i);
            if(hash_table.find(k - i) != hash_table.end()) return true;
        }        
    }
    return false;
}

int main()
{
    std::vector<int> list = { 2, 4, 3, 5, 6, -2, 4, 7, 8, 8 };
    std::cout << "Result is : " << is_k_summable(list, 16) << std::endl;
    return 0;
}