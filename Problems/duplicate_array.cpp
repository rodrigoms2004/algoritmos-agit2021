
// How to compile
// g++ -O3 duplicate_array.cpp -o duplicate_array.o

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    int maxElement(vector<int>& nums)
    {
      return *max_element(std::begin(nums), std::end(nums)); // C++ 11 
    }
  public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
      int buffer_size = maxElement(nums);
      int array_buffer[buffer_size + 1]; // max value is the size of array_buffer plus 1
      // initialization 
      for (int i = 0; i <= buffer_size; ++i)
        array_buffer[i] = 0;

      // count number of occurrences
      for (int n : nums) 
        array_buffer[n]++;
      
      vector<int> result;
      for (int i = 0; i <= buffer_size; ++i) 
      {
        int value = array_buffer[i];
        if (value == 2) 
          result.push_back(i);
      }
      
      return result;
    }
};

int main(int argc, char *argv[]) {

  vector<int> nums = {4,3,2,7,8,2,3,1};
  // vector<int> nums = {1,1,2};
  // vector<int> nums = {1};

  // auto it = *max_element(std::begin(nums), std::end(nums)); // C++ 11
  // cout << it << endl;

  Solution *sol = new Solution();
  auto result = sol->findDuplicates(nums);

  cout << "[";
  for (int i = 0, l = result.size() - 1; i <= l; ++i) 
    i == l 
      ? cout << result[i]
      : cout << result[i] << ",";
  cout << "]" << endl;
  return 0;
}

// USEFUL LINKS
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
// https://stackoverflow.com/questions/9874802/how-can-i-get-the-max-or-min-value-in-a-vector