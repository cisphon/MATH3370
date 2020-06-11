#pragma once

#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <chrono>

using namespace std;

namespace tools {
  template<typename T>
  void put_nums_in_vector(vector<T> &nums, string filename) {
    ifstream in("texts/" + filename, ios::in);
    
    T number;
    while (in >> number) //Read number using extraction (>>) operator
      nums.push_back(number);
    
    in.close(); //Close the file stream
  }
  
  template <typename T>
  void put_nums_in_map(map<int, T> &m, string filename)
  {
    ifstream in("texts/" + filename, ios::in);
    
    int i = 0;
    T number;
    while (in >> number) //Read number using extraction (>>) operator
      m[i++] = number;
    
    in.close(); //Close the file stream
  }
  
  template<typename T>
  void put_nums_in_deque(deque<T> &nums, string filename) {
    ifstream in("texts/" + filename, ios::in);
    
    T number;
    while (in >> number) //Read number using extraction (>>) operator
      nums.push_back(number);
    
    in.close(); //Close the file stream
  }
  
  void put_number_of_nums_in_vector(vector<int> &nums, const string file) {
    ifstream myfile("texts/" + file);
    
    string line;
    while (getline(myfile, line)) {
      for (int i = 0; i < line.size(); ++i) {
        char c = line[i];
        
        if (isdigit(c)) {
          int i = c - 48; // -48 because ascii shit
          ++nums[i]; // increment the nonconforming freq
        }
      }
    }
    
    myfile.close();
  }
  
  template<typename T>
  double round_x_decimal_places(T val, int x) {
    stringstream tmp;
    tmp << setprecision(x) << fixed << val;
    return stod(tmp.str());
  }
  
  template<typename T>
  int round_nearest_x(T val, int x) {
    int num = round(val);
    int result = result = num + x / 2;
    result -= result % x;
    return result;
  }
  
  template<typename T>
  void print_vector(const vector<T> &vec) {
    for (int i = 0; i < vec.size(); ++i)
      cout << vec[i] << " ";
    cout << endl;
  }
  
  template<typename T>
  void print_2D_vector(const vector<vector<T>> &matrix)
  {
    for (int i = 0; i < matrix.size(); ++i)
    {
      for (int j = 0; j < matrix[i].size(); ++j)
      {
        cout << matrix[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  
  template<typename T>
  void print_deque(const deque<T> &deq) {
    for (int i = 0; i < deq.size(); ++i)
      cout << deq[i] << " ";
    cout << endl;
  }
  
  template<typename T>
  double vector_mean(const vector<T> &vec) {
    double sum = 0.0;
    for (int i = 0; i < vec.size(); ++i)
      sum += vec[i];
    return sum / vec.size();
  }
  
  template<typename T>
  void vector_mode(const vector<T> &vec) {
    
  }
  
  template<typename T>
  double deque_mean(const deque<T> &deq) {
    double sum = 0.0;
    for (int i = 0; i < deq.size(); ++i)
      sum += deq[i];
    return sum / deq.size();
  }
  
  template<typename T>
  double deque_trimmed_mean(deque<T> &deq, double percent){
    sort(deq.begin(), deq.end());
    
    double val = (deq.size() * percent) / 100.0;
    int num = floor(val);
    for (int i = 0; i < num; ++i)
    {
      deq.pop_back();
      deq.pop_front();
    }
    return deque_mean(deq);
  }
  
  template<typename T>
  double vector_median(vector<T> vec) {
    sort(vec.begin(), vec.end());
    if (vec.size() % 2 == 0) // if the vector has an even number of nums
      return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2.0;
    return vec[vec.size() / 2];
  }
  
  template<typename T>
  T deque_median(deque<T> deq) {
    sort(deq.begin(), deq.end());
    if (deq.size() % 2 == 0) // if the vector has an even number of nums
      return (deq[deq.size() / 2 - 1] + deq[deq.size() / 2]) / 2.0;
    return deq[deq.size() / 2];
  }
  
  
  template<typename T>
  double sum_vector(const vector<T> &nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i)
      sum += nums[i];
    return sum;
  }
  
  template<typename T>
  double sum_deque(const deque<T> &nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i)
      sum += nums[i];
    return sum;
  }
  
  double increment_first_number_until_median_changes(deque<double> deq) {
    double median = deque_median(deq);
    while (deque_median(deq) == median)
      deq[0] += 0.001; // add 0.001 to the largest value
    return deq[0];
  }
  
  template <typename T>
  double decrement_last_number_until_median_changes(vector<T> vec) {
    double median = vector_median(vec);
    while (vector_median(vec) == median)
      vec[vec.size() - 1] -= 0.001; // add 0.001 to the largest value
    return vec[vec.size() - 1] += 0.001;
  }
  
  template <typename T>
  double increment_last_number_until_median_changes(vector<T> vec) {
    double median = vector_median(vec);
    while (vector_median(vec) == median)
      vec[vec.size() - 1] += 0.001; // add 0.001 to the largest value
    return vec[vec.size() - 1] -= 0.001;
  }
  
  template<typename T>
  T sample_range(vector<T> nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - 1] - nums[0];
  }
  
  template<typename T>
  double sample_variance(const vector<T> nums) {
    double mean = vector_mean(nums);
    
    double sum = 0.0;
    for (int i = 0; i < nums.size(); ++i)
      sum += ((nums[i] - mean) * (nums[i] - mean));
    
    return sum /= (nums.size() - 1);
  }
  
  template<typename T>
  double sample_standard_deviation(const vector<T> nums) {
    double mean = vector_mean(nums);
    
    double sum = 0.0;
    for (int i = 0; i < nums.size(); ++i)
      sum += ((nums[i] - mean) * (nums[i] - mean));
    
    return sqrt(sum /= (nums.size() - 1));
  }
  
  template<typename T>
  vector<double> deviations_from_mean(const vector<T> nums) {
    double mean = vector_mean(nums);
    
    vector<double> dev(nums.size());
    for (int i = 0; i < nums.size(); ++i)
      dev[i] = nums[i] - mean;
    
    return dev;
  }
}