#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map);

void make_snail(const std::vector<std::vector<int>> &snail_map,
                std::vector<int> &vec, int begin, int end);

int main() {

  std::vector<std::vector<int>> array = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (int num : snail(array)) {
    std::cout << num << ", ";
  }

  std::cout << "\ntests passed\n";
  return 0;
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  if (!snail_map[0].size())
    return {};
  std::vector<int> snail;
  make_snail(snail_map, snail, 0, snail_map.size());


  return snail;
}

void make_snail(const std::vector<std::vector<int>> &snail_map,
                std::vector<int> &vec, int begin, int end) {
  for (int i = begin; i < end; i++)
    vec.push_back(snail_map[begin][i]);
  for (int j = begin + 1; j < end; j++)
    vec.push_back(snail_map[j][end - 1]);
  for (int i = end - 2; i >= begin; i--)
    vec.push_back(snail_map[end - 1][i]);
  for (int j = end - 2; j > begin; j--)
    vec.push_back(snail_map[j][begin]);

  if (++begin < --end)
    make_snail(snail_map, vec, begin, end);
}