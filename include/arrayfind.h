//
// Created by Yu Jun on 29/08/2018.
//

#ifndef UTILI_ARRAYFIND_H
#define UTILI_ARRAYFIND_H

#include <vector>
#include <iostream>
#include <unordered_map>

class ArrayFind
{

 public:

  static bool find(const std::vector<std::vector<int>>& matrix, int number)
  {
    if (matrix.empty())
    {
      return false;
    }

    size_t row = matrix.size();
    size_t column = matrix[0].size();

    size_t beginRow = 0;
    size_t beginColumn = column - 1;

    while (beginRow >= 0 && beginRow < row && beginColumn >= 0 && beginColumn < column)
    {
      if (matrix[beginRow][beginColumn] == number)
      {
        return true;
      } else if (matrix[beginRow][beginColumn] > number)
      {
        beginColumn--;
      } else
      {
        beginRow++;
      }
    }
    return false;
  }

  //数组不重复
  static std::vector<int> twoSum(std::vector<int>& nums, int target)
  {
    std::unordered_map<int, int> indexMap;
    std::vector<int> res;
    for(int i =0; i < nums.size(); ++i)
    {
      indexMap.insert({nums[i], i});
    }
    for(int i =0; i< nums.size(); ++i)
    {
      int t = target - nums[i]; //new value
      if (indexMap.count(t) && indexMap[t] != i)
      {
        res.emplace_back(i);
        res.emplace_back(indexMap[t]);
        break;
      }
    }
    return res;
  }

  //数组重复
  //返回vector<int>是有问题的 TODO
  static std::vector<int> twoSum1(std::vector<int>& nums, int target)
  {
    std::unordered_map<int, int> indexMap;
    std::vector<int> res;
    for(int i =0; i < nums.size(); ++i)
    {
      indexMap.insert({nums[i], i});
    }
    for(int i =0; i< nums.size(); ++i)
    {
      int t = target - nums[i]; //new value
      if (indexMap.count(t) && indexMap[t] != i)
      {
        res.emplace_back(i);
        res.emplace_back(indexMap[t]);
        break;
      }
    }
    return res;
  }
};

#endif //UTILI_ARRAYFIND_H
