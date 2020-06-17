#pragma once

#include "tools.hpp"

namespace hw {
  // webassign
  namespace web {
    // 1.1 - Populations, Samples, and ...
    namespace one {
      namespace sec2 {
        void a() {
          vector<int> nums(9); // make a vector with indices [0,9) = [0,8]
          
          ts::put_number_of_nums_in_vector(nums, "transducers.txt");
          
          for (int i = 0; i < nums.size(); ++i) {
            double freq = ts::round_x_decimal_places(nums[i] / 60.0f, 3);
            printf("%d: %d, %0.3f\n", i, nums[i], freq);
          }
        }
      
        void b() {
          vector<int> nums(9); // make a vector with indices [0,9) = [0,8]
          
          ts::put_number_of_nums_in_vector(nums, "transducers.txt");
          
          double sum = 0;
          for (int i = 0; i <= 5; ++i)
            sum += (nums[i] / 60.0);
          printf("sum: %0.3f\n", ts::round_x_decimal_places(sum, 3));
          
          sum = 0;
          for (int i = 0; i < 5; ++i)
            sum += (nums[i] / 60.0);
          printf("sum: %0.3f\n", ts::round_x_decimal_places(sum, 3));
          
          sum = 0;
          for (int i = 5; i < nums.size(); ++i)
            sum += (nums[i] / 60.0);
          printf("sum: %0.3f\n", ts::round_x_decimal_places(sum, 3));
        }
        
        /*
         Use this in R to make it work:
         vec = c()
         hist(vec, xlab = "number", col = "blue", xlim = c(0,8), ylim = c(0,25))
         */
        vector<double> c() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "transducers.txt");
          return nums;
        }
      }
    
      namespace sec3 {
        /*
         Use this in R to make it work:
         barplot(func())
         */
        vector<double> a() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "papers.txt");
          
          int sum = ts::sum_vector(nums);
          for (int i = 0; i < nums.size(); ++i)
            nums[i] = ((nums[i] / sum) * 100);
          
          return nums;
        }
      
        void b() {
          vector<int> nums;
          ts::put_nums_in_vector(nums, "papers.txt");
          
          double sum = 0.0;
          int total = 0;
          for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            if (i + 1 >= 5)
              sum += nums[i];
          }
          printf("%0.4f\n", ts::round_x_decimal_places(sum / total, 4));
          
          
          sum = 0.0;
          total = 0;
          for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            if (i + 1 >= 10)
              sum += nums[i];
          }
          printf("%0.4f\n", ts::round_x_decimal_places(sum / total, 4));
          
          sum = 0.0;
          total = 0;
          for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            if (i + 1 > 10)
              sum += nums[i];
          }
          printf("%0.4f\n", ts::round_x_decimal_places(sum / total, 4));
        }
      }
    
      namespace sec4 {
        void a() {
          vector<int> nums;
          ts::put_nums_in_vector(nums, "particles.txt");
          
          double freq = 0.0;
          int total = nums[0];
          for (int i = 1; i < nums.size(); ++i) {
            total += nums[i];
            freq += nums[i];
          }
          printf("%0.2f\n", ts::round_x_decimal_places(freq / total, 2));
          
          
          freq = 0.0;
          total = 0;
          for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            if (i >= 5)
              freq += nums[i];
          }
          
          printf("%0.2f\n", ts::round_x_decimal_places(freq / total, 2));
        }
      
        void b() {
          vector<int> nums;
          ts::put_nums_in_vector(nums, "particles.txt");
          
          double freq = 0.0;
          int total = 0;
          for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            if (5 <= i && i <= 10) // if i is in [5, 10]
              freq += nums[i];
          }
          
          printf("%0.2f\n", ts::round_x_decimal_places(freq / total, 2));
          
          freq = 0.0;
          total = 0;
          for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            if (5 < i && i < 10) // if i is in (5, 10)
              freq += nums[i];
          }
          
          printf("%0.2f\n", ts::round_x_decimal_places(freq / total, 2));
        }
        
        // barplot(c())
        map<int,int> c() {
          map<int,int> m;
          ts::put_nums_in_map(m, "particles.txt");
          return m;
        }
      }
    
      namespace sec5 {
        // barplot(a())
        map<int, double> a() {
          vector<double> y_values;
          ts::put_nums_in_vector(y_values, "fire_load.txt");
          
          map<int, double> m;
          int sum = 0;
          for (int i = 0; i < y_values.size() - 1; ++i)
          {
            m[sum] = (y_values[i+1] - y_values[i]);
            sum += 150;
          }
          m[sum] = 0; // there is no difference for the last one.
          
          return m;
        }
      
        void b() {
          map<int, double> cumulative;
          
          ifstream in("texts/fire_load.txt", ios::in);
          
          int value = 0;
          double number;
          while (in >> number) //Read number using extraction (>>) operator
          {
            cumulative[value] = number;
            value += 150;
          }
          in.close(); //Close the file stream
          
          double ans = cumulative.find(600)->second / 100.0;
          cout << ts::round_x_decimal_places(ans, 3) << endl;
          
          ans = (100.0 - cumulative.find(1200)->second) / 100.0;
          cout << ts::round_x_decimal_places(ans, 3) << endl;
        }
      
        void c() {
          map<int, double> cumulative;
          
          ifstream in("texts/fire_load.txt", ios::in);
          
          int value = 0;
          double number;
          while (in >> number) //Read number using extraction (>>) operator
          {
            cumulative[value] = number;
            value += 150;
          }
          in.close(); //Close the file stream
          
          
          map<int, double>::iterator it = cumulative.find(600);
          map<int, double>::iterator end = cumulative.find(1200);
          
          double ans = (end->second - it->second) / 100.0;
          cout << ts::round_x_decimal_places(ans, 3) << endl;
        }
      }
    }
    
    // 1.3-1.4-Measures of Location and Variability
    namespace two {
      namespace sec1 {
        void a() {
          vector<double> urban;
          ts::put_nums_in_vector(urban, "urban.txt");
          cout << ts::round_x_decimal_places(ts::vector_mean(urban), 2) << endl;
          
          vector<double> farms;
          ts::put_nums_in_vector(farms, "farm.txt");
          cout << ts::round_x_decimal_places(ts::vector_mean(farms), 2) << endl;
        }
        
        void b() {
          vector<double> urban;
          ts::put_nums_in_vector(urban, "urban.txt");
          sort(urban.begin(), urban.end());
          cout << ts::vector_median(urban) << endl;
          
          vector<double> farm;
          ts::put_nums_in_vector(farm, "farm.txt");
          sort(farm.begin(), farm.end());
          cout << ts::vector_median(farm) << endl;
        }
        
        void c() {
          deque<double> urban;
          ts::put_nums_in_deque(urban, "urban.txt");
          sort(urban.begin(), urban.end());
          urban.pop_front();
          urban.pop_back();
          cout << ts::round_x_decimal_places(ts::deque_mean(urban), 2) << endl;
          
          deque<double> farm;
          ts::put_nums_in_deque(farm, "farm.txt");
          sort(farm.begin(), farm.end());
          farm.pop_front();
          farm.pop_back();
          cout << ts::round_x_decimal_places(ts::deque_mean(farm), 2) << endl;
          
          urban.clear();
          ts::put_nums_in_deque(urban, "urban.txt");
          double trimmed_percentage = (1.0 * 100) / urban.size();
          cout << ts::round_x_decimal_places(trimmed_percentage, 2) << endl;
          
          farm.clear();
          ts::put_nums_in_deque(farm, "farm.txt");
          trimmed_percentage = (1.0 * 100) / farm.size();
          cout << ts::round_x_decimal_places(trimmed_percentage, 2) << endl;
        }
      }
      
      namespace sec3 {
        void a() {
          vector<double> blood;
          ts::put_nums_in_vector(blood, "blood.txt");
          cout << ts::round_nearest_x(ts::vector_median(blood), 5) << endl;
          
          replace(blood.begin(), blood.end(), 137.4, 137.9); // replace 137.4 with 137.9
          cout << ts::round_nearest_x(ts::vector_median(blood), 5) << endl;
        }
      }
      
      namespace sec4 {
        void a() {
          vector<double> cracks;
          ts::put_nums_in_vector(cracks, "cracks.txt");
          
          cout << ts::round_x_decimal_places(ts::vector_mean(cracks), 4) << endl;
          cout << ts::round_x_decimal_places(ts::vector_median(cracks), 4) << endl;
        }
        
        void b() {
          vector<double> cracks;
          ts::put_nums_in_vector(cracks, "cracks.txt");
          
          cout << cracks[cracks.size() - 1] 
          - ts::decrement_last_number_until_median_changes(cracks) << endl;
        }
      }
      
      namespace sec5 {
        void a() {
          bitset<10> bset("0011101100");
          cout << bset.count() / (bset.size() + 0.0) << endl;
        }
      
        void b() {
          bitset<10> bset("0011101100");
          bset.flip();
          
          cout << bset.count() / (bset.size() + 0.0) << endl;
        }
      
        void c() {
          bitset<10> bset("0011101100");
          
          cout << 0.6 * 25 - bset.count() << endl;
        }
      }
      
      namespace sec6 {
        void a() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "chem.txt");
          sort(nums.begin(), nums.end());
          
          double range = ts::round_x_decimal_places(nums[nums.size() - 1] - nums[0], 2);
          printf("%0.2f\n", range);
        }
        
        void b() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "chem.txt");
          
          // subtract 180 from each observation
          for (int i = 0; i < nums.size(); ++i)
            nums[i] = nums[i] - 180.0;
          
          double mean = ts::vector_mean(nums); // the assumed mean
          
          double sum = 0;
          for (int i = 0; i < nums.size(); ++i)
            sum += ((nums[i] - mean) * (nums[i] - mean));
          
          cout << ts::round_x_decimal_places(sum / (nums.size() - 1.0), 2) << endl;
        }
        
        void c() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "chem.txt");
          
          double mean = ts::vector_mean(nums); // the assumed mean
          
          double sum = 0.0;
          for (int i = 0; i < nums.size(); ++i)
            sum += ((nums[i] - mean) * (nums[i] - mean));
          
          cout << ts::round_x_decimal_places(sqrt(sum / (nums.size() - 1.0)), 2) << endl;
        }
        
        void d() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "chem.txt");
          
          double mean = ts::vector_mean(nums); // the assumed mean
          
          double sum = 0;
          for (int i = 0; i < nums.size(); ++i)
            sum += ((nums[i] - mean) * (nums[i] - mean));
          
          cout << ts::round_x_decimal_places(sum / (nums.size() - 1.0), 2) << endl;
        }
      }
    
      namespace sec7 {
        void a() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "area.txt");
          
          double sum = 0.0, sum_squared = 0.0l;
          for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum_squared += (nums[i] * nums[i]);
          }
          
          cout << ts::round_x_decimal_places(sum, 2) << endl;
          cout << ts::round_x_decimal_places(sum_squared, 2) << endl;
        }
        
        void b() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "area.txt");
          
          cout << ts::round_x_decimal_places(ts::sample_variance(nums), 3) << endl;
          cout << ts::round_x_decimal_places(ts::sample_standard_deviation(nums), 3) << endl;
        }
      }
    }
  
    // 2.3 - Counting Techniques
    namespace three {
      namespace sec1 {
        void a() {
          int z = 7;
          cpp_int perms = ts::factorial(z) / ts::factorial(z - 3);
          cout << perms << endl;
        }
      
        void b() {
          int t = 29;
          int b = 6;
          cpp_int top = ts::factorial(t);
          cpp_int bottom = ts::factorial(b) * ts::factorial(t - b);
    
          cout << top / bottom << endl;
        }
      
        void c() {
          cout << ts::choose(7, 2)*ts::choose(9, 2)*ts::choose(13, 2)<< endl;
        }
        
        void d() {
          cpp_int top = ts::choose(7, 2)*ts::choose(9, 2)*ts::choose(13, 2);
          cpp_int bottom = ts::choose(29, 6);
          cout << cpp_dec_float_100(top) / cpp_dec_float_100(bottom) << endl;
        }
      
        void e() {
          cpp_int top = ts::choose(7, 6)+ts::choose(9, 6)+ts::choose(13, 6);
          cpp_int bottom = ts::choose(29, 6);
          cout << cpp_dec_float_100(top) / cpp_dec_float_100(bottom) << endl;
        }
      }
    }
  
    void run() {
      one::sec2::a();
      one::sec2::b();
      //one::sec2::c();
      
      //one::sec3::a();
      one::sec3::b();
      
      one::sec4::a();
      one::sec4::b();
      //one::sec4::c();
      
      //one::sec5::a();
      one::sec5::b();
      one::sec5::c();
      
      two::sec1::a();
      two::sec1::b();
      two::sec1::c();
      
      two::sec3::a();
      
      two::sec4::a();
      two::sec4::b();
      
      two::sec5::a();
      two::sec5::b();
      two::sec5::c();
      
      two::sec6::a();
      two::sec6::b();
      two::sec6::c();
      two::sec6::d();
      
      two::sec7::a();
      two::sec7::b();
    }
  }
  
  // discussions
  namespace disc {
    namespace one { 
      namespace sec3 {
        void q34() {
          deque<double> urban;
          ts::put_nums_in_deque(urban, "urban.txt");
          
          sort(urban.begin(), urban.end());
          
          deque<double> farm;
          ts::put_nums_in_deque(farm, "farm2.txt");
          
          sort(farm.begin(), farm.end());
          
          int n1 = urban.size(), n2 = farm.size();
          
          cout << "Urban mean: " << ts::deque_mean(urban) << endl;
          cout << "Farm mean: " << ts::deque_mean(farm) << endl;
          
          cout << "Urban median: " << ts::deque_median(urban) << endl;
          cout << "Farm median: " << ts::deque_median(farm) << endl;
          
          urban.pop_front(); urban.pop_back();
          farm.pop_front(); farm.pop_back();
          cout << "Trimmed Urban mean: " << ts::deque_mean(urban) << endl;
          cout << "Trimmed Farm mean: " << ts::deque_mean(farm) << endl;
          
          cout << "Trimming percentage for urban: "<< (1.0 / n1) * 100 << endl;
          cout << "Trimming percentage for farm: " << (1.0 / n2) * 100 << endl;
        }
      
        void q35() {
          deque<double> nums;
          ts::put_nums_in_deque(nums, "mercury.txt");
          sort(nums.begin(), nums.end());
          
          cout << "Sample mean: " << ts::deque_mean(nums) << endl;
          cout << "Sample median: " << ts::deque_median(nums) << endl;
          
          cout << "Trimmed mean: " << ts::deque_trimmed_mean(nums, 10)<<endl;
          
          nums.clear();
          ts::put_nums_in_deque(nums, "mercury.txt");
          sort(nums.begin(), nums.end());
          
          cout << ts::increment_first_number_until_median_changes(nums)<< endl;
        }
      
        void q36() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "oxygen.txt");
          
          // stem(nums);
          
          cout << ts::vector_mean(nums) << endl;
          cout << ts::vector_median(nums) << endl;
          
          for (int i = 0; i < nums.size(); ++i)
            nums[i] /= 60.0;
          
          cout << ts::vector_mean(nums) << endl;
          cout << ts::vector_median(nums) << endl;
        }
      
        void q37() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "snow.txt");
          
          cout << ts::vector_mean(nums) << endl;
        }
      
        void q38() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "blood2.txt");
          
          vector<double> reported(nums.size());
          for (int i = 0; i < reported.size(); ++i)
            reported[i] = ts::round_nearest_x(nums[i], 5);
          
          cout << ts::vector_median(reported) << endl;
          
          replace(nums.begin(), nums.end(), 127.4, 127.6);
          
          for (int i = 0; i < reported.size(); ++i)
            reported[i] = ts::round_nearest_x(nums[i], 5);
          
          cout << ts::vector_median(reported) << endl;
        }
      }
    
      namespace sec4 {
        void q44() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "chem2.txt");
          
          cout << ts::sample_range(nums) << endl;
          
          for (int i = 0; i < nums.size(); ++i)
            nums[i] -= 180;
          
          cout << ts::sample_variance(nums) << endl;
          
          cout << ts::sample_standard_deviation(nums) << endl;
          
          nums.clear();
          ts::put_nums_in_vector(nums, "chem2.txt");
          
          cout << ts::sample_variance(nums) << endl;
        }
      
        void q45() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "modulus.txt");
          
          cout << ts::vector_mean(nums) << endl;
          
          vector<double> dev = ts::deviations_from_mean(nums);
          ts::print_vector(dev);
          
          cout << ts::sample_variance(dev) << endl;
          
          cout << ts::sample_standard_deviation(dev) << endl;
          
          cout << ts::sample_variance(nums) << endl;
          
          vector<double> trans(nums);
          for (int i = 0; i < trans.size(); ++i)
            trans[i] -= 100;
          
          cout << ts::sample_variance(trans) << endl;
          
          cout << "They're the same." << endl;
        }
      
        void q46() {
          vector<double> cooler;
          ts::put_nums_in_vector(cooler, "cooler.txt");
          cout << ts::vector_mean(cooler) << endl;
          cout << ts::vector_median(cooler) << endl;
          cout << "There is no mode." << endl;
          
          vector<double> control;
          ts::put_nums_in_vector(control, "control.txt");
          cout << ts::vector_mean(control) << endl;
          cout << ts::vector_median(control) << endl;
          cout << "There is no mode." << endl;
          
          
          vector<double> warmer;
          ts::put_nums_in_vector(warmer, "warmer.txt");
          cout << ts::vector_mean(warmer) << endl;
          cout << ts::vector_median(warmer) << endl;
          cout << "There is no mode." << endl;
          
          cout << "Cooler mean < Control mean < Warmer mean" << endl;
          cout << "Cooler median < Control median < Warmer Median" << endl;
          
          
          cout << ts::sample_standard_deviation(cooler) << endl;
          cout << ts::sample_standard_deviation(control) << endl;
          cout << ts::sample_standard_deviation(warmer) << endl;
          
          cout << "Cooler std. dev < Control std. dev < Warmer std. dev"<< endl;
        }
      
        void q47() {
          vector<double> nums;
          ts::put_nums_in_vector(nums, "wine.txt");
          cout << ts::vector_mean(nums) << endl;
          cout << ts::vector_median(nums) << endl;
          cout << "There is no mode." << endl;
          
          cout << ts::sample_variance(nums) << endl;
          
          for (int i = 0; i < nums.size(); ++i)
            nums[i] -= 13.0;
          
          cout << ts::sample_variance(nums) << endl;
        }
      
        // This is incomplete.
        auto q48() {
          vector<double> urban;
          ts::put_nums_in_vector(urban, "urban.txt");
          cout << ts::sample_standard_deviation(urban) << endl;
          
          vector<double> farm;
          ts::put_nums_in_vector(farm, "farm2.txt");
          cout << ts::sample_standard_deviation(farm) << endl;
          
          cout << "Urban std. dev > 3x than Farm std. dev" << endl;
          return farm;
        }
      }
    }
  
    void run()
    {
      
    }
  }
}