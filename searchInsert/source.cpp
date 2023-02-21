#include "Utils.hpp"
#include <iostream>
#include <vector>

int solve(std::vector<int> nums, int target) {
  std::cout << "Solving problem" << std::endl;
  std::cout << "Target is " << target << std::endl;
  int low = 0;
  int high = nums.size();
  int mid;
  if (target > nums[high - 1]) {
    return high;
  }
  while (low <= high) {
    mid = (low + high) / 2;
    if (nums[mid] == target) { // if found return its position
      return mid;
    }

    if (target < nums[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low; // if not found return the location where it should be
}
int main(int argc, char **argv) {
  std::cout << "Reading input" << std::endl;
  std::vector<int> m_Nums = parseIntVec();
  int target;
  std::cin >> target;
  int ans = solve(m_Nums, target);
  std::cout << "answer is " << ans << std::endl;
  return 0;
}
