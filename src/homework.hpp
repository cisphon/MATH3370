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
        map<int, int> c() {
          map<int, int> m;
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
          for (int i = 0; i < y_values.size() - 1; ++i) {
            m[sum] = (y_values[i + 1] - y_values[i]);
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

          cout << ts::decrement_last_number_before_median_changes(cracks) << endl;
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
        int zin = 7, mer = 9, cab = 13, tot = 29, bot = 6;

        void a() {
          cpp_int perms = ts::fact(zin) / ts::fact(zin - 3);
          cout << perms << endl;
        }

        void b() {

          cpp_int top = ts::fact(tot);
          cpp_int bottom = ts::fact(bot) * ts::fact(tot - bot);

          cout << top / bottom << endl;
        }

        void c() {
          cout << ts::ch(zin, 2) * ts::ch(mer, 2) * ts::ch(cab, 2) << endl;
        }

        void d() {
          cpp_int top = ts::ch(zin, 2) * ts::ch(mer, 2) * ts::ch(cab, 2);
          cpp_int bottom = ts::ch(tot, bot);
          cout <<
               ts::round_x_decimal_places(cpp_float(top) / cpp_float(bottom), 3)
               << endl;
        }


        void e() {
          cpp_int top = ts::ch(zin, bot) + ts::ch(mer, bot) + ts::ch(cab, bot);
          cpp_int bottom = ts::ch(tot, bot);
          cout <<
               ts::round_x_decimal_places(cpp_float(top) / cpp_float(bottom), 3)
               << endl;
        }
      }

      namespace sec2 {
        /*
        vector<string> rec = {"Kenwood", "Onkyo", "Sony", "Sherwood"};
        vector<string> cdp = {"Onkyo", "Pioneer", "Sony", "Technics"};
        vector<string> spk = {"Boston", "Infinity"};
        vector<string> cas = {"Onkyo", "Sony", "Teac", "Technics"};
        */
        vector<string> rec = {"Kenwood", "Onkyo", "Pioneer", "Sony", "Sherwood"};
        vector<string> cdp = {"Onkyo", "Pioneer", "Sony", "Technics"};
        vector<string> spk = {"Boston", "Infinity", "Polk"};
        vector<string> cas = {"Onkyo", "Sony", "Teac", "Technics"};

        int w = rec.size(), x = cdp.size(), y = spk.size(), z = cas.size();
        cpp_int total = 0, without_sony = 0, one_sony = 0;

        void a() {
          total = ts::ch(w, 1) * ts::ch(x, 1) * ts::ch(y, 1) * ts::ch(z, 1);
          cout << total << endl;
        }

        void b() {
          int rec_c = count(rec.begin(), rec.end(), "Sony");
          int cdp_c = count(cdp.begin(), cdp.end(), "Sony");

          cout << ts::ch(rec_c, 1) * ts::ch(cdp_c, 1)
                  * ts::ch(y, 1) * ts::ch(z, 1) << endl;
        }

        void c() {
          int rec_wo_sony = w - count(rec.begin(), rec.end(), "Sony");
          int cdp_wo_sony = x - count(cdp.begin(), cdp.end(), "Sony");
          int spk_wo_sony = y - count(spk.begin(), spk.end(), "Sony");
          int cas_wo_sony = z - count(cas.begin(), cas.end(), "Sony");

          without_sony = ts::ch(rec_wo_sony, 1) * ts::ch(cdp_wo_sony, 1)
                         * ts::ch(spk_wo_sony, 1) * ts::ch(cas_wo_sony, 1);

          cout << without_sony << endl;
        }

        void d() {
          one_sony = total - without_sony;
          cout << one_sony << endl;
        }

        void e() {
          cout << cpp_float(one_sony) / cpp_float(total) << endl;


          cout << "UHHH" << endl;
        }
      }

      namespace sec3 {
        int day = 10, swing = 8, grave = 6;

        int w = 3;

        cpp_float same_shift = 0;

        void a() {
          cout << ts::ch(day, w) << endl;

          cpp_float p = cpp_float(ts::ch(day, w)) /
                        cpp_float(ts::ch(day + swing + grave, w));

          cout << ts::round_x_decimal_places(p, 4) << endl;
        }

        void b() {
          cpp_float denominator = cpp_float(ts::ch(day + swing + grave, w));
          cpp_float p =
                  cpp_float(ts::ch(day, w)) / denominator
                  + cpp_float(ts::ch(swing, w)) / denominator
                  + cpp_float(ts::ch(grave, w)) / denominator;

          same_shift = p;
          cout << ts::round_x_decimal_places(same_shift, 4) << endl;
        }

        void c() {
          cout << ts::round_x_decimal_places(1 - same_shift, 4) << endl;
        }

        void d() {
          cpp_float denominator = cpp_float(ts::ch(day + swing + grave, w));
          cpp_float numerator = cpp_float(ts::ch(grave + swing, w) + ts::ch(day + grave, w)
                                          + ts::ch(day + swing, w) - ts::ch(grave, w) - ts::ch(swing, w) -
                                          ts::ch(day, w));

          cpp_float p = numerator / denominator;

          cout << ts::round_x_decimal_places(p, 4) << endl;
        }
      }

      namespace sec4 {
        int cellular = 5, cordless = 5, corded = 5;
        int total = cellular + cordless + corded;

        void a() {
          cpp_float p = cpp_float(ts::ch(cordless, cordless) * ts::ch(cellular + corded, cordless))
                        / cpp_float(ts::ch(total, cellular + cordless));

          cout << p << endl;
        }

        void b() {
          int n = 10;
          cpp_float denominator = cpp_float(ts::ch(cellular + cordless + corded, n));
          cpp_float numerator = 3 * cpp_float(ts::ch(cordless, 1) * ts::ch(corded, 4)
                                              + ts::ch(cordless, 2) * ts::ch(corded, 3) +
                                              ts::ch(cordless, 3) * ts::ch(corded, 2)
                                              + ts::ch(cordless, 4) * ts::ch(corded, 1));

          cpp_float p = numerator / denominator;
          cout << p << endl;
        }

        void c() {
          cpp_float p = cpp_float(ts::ch(cellular, 2) * ts::ch(cordless, 2) * ts::ch(corded, 2))
                        / cpp_float(ts::ch(total, 6));

          cout << p << endl;
        }
      }

      void run() {

      }
    }

    // 2.4 - Conditional Probability
    namespace four {
      namespace sec1 {
        double p_a = 0.55, p_b = 0.40, p_a_int_b = 0.20;

        void a() {

        }
      }

      namespace sec2 {

      }

      namespace sec3 {

      }

      namespace sec4 {

      }
    }

    // 3.1 - Random Values
    namespace five {

    }

    // 3.2 
    namespace six {
      class sec1 {
      private:
        map<int, double> m;

      public:
        sec1(bool my_data) {
          if (my_data)
            m = {{45, 0.06},
                 {46, 0.10},
                 {47, 0.11},
                 {48, 0.14},
                 {49, 0.26},
                 {50, 0.16},
                 {51, 0.06},
                 {52, 0.05},
                 {53, 0.03},
                 {54, 0.02},
                 {55, 0.01}};
          else
            m = {{45, 0.05},
                 {46, 0.10},
                 {47, 0.13},
                 {48, 0.14},
                 {49, 0.26},
                 {50, 0.15},
                 {51, 0.06},
                 {52, 0.05},
                 {53, 0.03},
                 {54, 0.02},
                 {55, 0.01}};
        }

        void a() {
          double sum = 0;
          for (int i = 45; i <= 50; ++i)
            sum += m[i];
          cout << sum << endl;
        }

        void b() {
          double sum = 0;
          for (int i = 51; i <= 55; ++i)
            sum += m[i];
          cout << sum << endl;
        }

        void c() {
          double sum = 0;
          for (int i = 45; i < 50; ++i)
            sum += m[i];
          cout << sum << endl;

          sum = 0;
          for (int i = 45; i <= 47; ++i)
            sum += m[i];
          cout << sum << endl;
        }
      };

      class sec2 {
      private:
        vector<double> p;

      public:
        sec2(bool my_data) {
          if (my_data)
            p = {0.12, 0.15, 0.20, 0.25, 0.18, 0.07, 0.03};
          else
            p = {0.12, 0.15, 0.20, 0.25, 0.18, 0.08, 0.02};
        }

        void a() {
          double sum = 0;
          for (int i = 0; i <= 3; ++i)
            sum += p[i];
          cout << sum << endl;
        }

        void b() {
          double sum = 0;
          for (int i = 0; i < 3; ++i)
            sum += p[i];
          cout << sum << endl;
        }

        void c() {
          double sum = 0;
          for (int i = 3; i < p.size(); ++i)
            sum += p[i];
          cout << sum << endl;
        }

        void d() {
          double sum = 0;
          for (int i = 2; i <= 5; ++i)
            sum += p[i];
          cout << sum << endl;
        }

        void e() {
          double sum = 0;
          for (int i = 0; i < p.size(); ++i)
            if (2 <= i && i <= 4)
              sum += p[i];
          cout << sum << endl;
        }

        void f() {
          double sum = 0;
          for (int i = 0; i <= 2; ++i)
            sum += p[i];
          cout << sum << endl;
        }
      };

      void run() {
        sec2 s(true);
        s.a();
        s.b();
        s.c();
        s.d();
        s.e();
        s.f();
      }
    }

    // 3.3
    namespace seven {
      namespace sec1 {
        vector<int> x{1, 2, 4, 8, 16};
        vector<double> px{0.05, 0.15, 0.30, 0.35, 0.15};
        vector<int> xs(x);

        double ex = 0, vx = 0;

        void a() {
          ex = ts::E(x, px);
          cout << ts::round_x_decimal_places(ex, 2) << endl;
        }

        void b() {
          transform(xs.begin(), xs.end(), xs.begin(), [](int x) { return x * x; });

          vx = ts::E(xs, px) - (ex * ex);

          cout << ts::round_x_decimal_places(vx, 4) << endl;
        }

        void c() {
          cout << ts::round_x_decimal_places(sqrt(vx), 3) << endl;
        }

        void d() {
          double sum = 0, hold;
          for (int i = 0; i < x.size(); ++i)
            sum += ((x[i] - ex) * (x[i] - ex) * px[i]);
          cout << sum << endl;
        }
      }

      namespace sec2 {
        vector<int> y{0, 1, 2, 3};
        vector<double> py{0.45, 0.25, 0.25, 0.05};

        void a() {
          cout << ts::E(y, py) << endl;
        }

        void b() {
          vector<int> ys(y);
          transform(ys.begin(), ys.end(), ys.begin(), [](int x) { return x * x; });

          cout << 80 * ts::E(ys, py) << endl;
        }
      }

      namespace sec3 {
#define mydata true
#if mydata
        vector<double> x{16, 18, 20};
        vector<double> px{0.4, 0.3, 0.3};

        double F1(double X) { return 62 * X - 650; }

        double F2(double X) { return X - 0.009 * X * X; }

#else
        vector<int> x {16, 18, 20};
        vector<double> px {0.5, 0.4, 0.1};
        double F1(int X) { return 69 * X - 650; }
        double F2(int X) { return X - 0.008*X*X; }
#endif

        void a() {
          cout << ts::E(x, px) << endl;
          cout << ts::E(x, px, [](double X) -> double { return X * X; }) << endl;
          cout << ts::V(x, px) << endl;
        }

        void b() {
          cout << ts::E(x, px, F1) << endl;
        }

        void c() {
          cout << ts::V(x, px, F1) << endl;
        }

        void d() {
          cout << ts::E(x, px, F2) << endl;
        }

        void run() {
          a();
          b();
          c();
          d();
        }
      }
    }

<<<<<<< HEAD
    // 5.3-5.4
    namespace eight {
      namespace sec1 {
        map<double, double> nums = {{25, 0.2},
                                    {45, 0.5},
                                    {60, 0.3}};

        map<double, double> nums2 = {{25, 0.0},
                                     {35, 0.0},
                                     {45, 0.0},
                                     {42.5, 0},
                                     {52.5, 0.0},
                                     {60, 0.0}};

        map<double, double> dists = {{0.0,   0.0},
                                  {200.0,  0.0},
                                  {112.5, 0.0},
                                  {612.5, 0.0}};

        void a() {
          for (auto num1 = nums.begin(); num1 != nums.end(); ++num1) {
            for (auto num2 = nums.begin(); num2 != nums.end(); ++num2) {
              //cout << num1->first << ' ' << num2->first << ' ';

              double p = num1->second * num2->second;
              //cout << p << ' ';

              double mean = (num1->first + num2->first) / 2.0;
              //cout << mean << ' ';

              nums2[mean] += p;

              /*
              cout << ((num1->first - mean) * (num1->first - mean)
                       + (num2->first - mean) * (num2->first - mean)) << endl;
              */
            }
          }
          cout << "CAREFUL!!!! WATCH THE ORDERING!!!" << endl;
          for (auto num = nums2.begin(); num != nums2.end(); ++num)
            cout << num->first << ' ';
          cout << endl;
          for (auto num = nums2.begin(); num != nums2.end(); ++num)
            cout << num->second << ' ';
          cout << endl << endl;

          double sum = 0.0;
          for (auto num = nums2.begin(); num != nums2.end(); ++num)
            sum += (num->first * num->second);
          cout << sum << endl << endl;
        }

        void b() {
          for (auto num1 = nums.begin(); num1 != nums.end(); ++num1) {
            for (auto num2 = nums.begin(); num2 != nums.end(); ++num2) {
              double p = num1->second * num2->second;
              double mean = (num1->first + num2->first) / 2.0;
              double s2 = ((num1->first - mean) * (num1->first - mean)
                           + (num2->first - mean) * (num2->first - mean));
              dists[s2] += p;
            }
          }

          cout << "CAREFUL!!!! WATCH THE ORDERING!!!" << endl;
          for (auto num = dists.begin(); num != dists.end(); ++num)
            cout << num->first << ' ';
          cout << endl;
          for (auto num = dists.begin(); num != dists.end(); ++num)
            cout << num->second << ' ';
          cout << endl << endl;

          double sum = 0.0;
          for (auto num = dists.begin(); num != dists.end(); ++num)
            sum += (num->first * num->second);
          cout << sum << endl;
        }
      }

      namespace sec2 {
        map<double, double> salaries = {{1, 29.7},
                                        {2, 33.6},
                                        {3, 30.2},
                                        {4, 33.6},
                                        {5, 25.8},
                                        {6, 29.7}};
        void a () {

=======
    // 3.4 - The Binomial Distribution
    namespace eight {
      namespace sec1 {
        // b(4; 8, 0.3)
        void a() {
          cpp_float result = ts::bin(4, 8, 0.3);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        // b(6; 8, 0.55)
        void b() {
          cpp_float result = ts::bin(6, 8, 0.55);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        //P(3 ≤ X ≤ 5) when n = 7 and p = 0.55
        void c() {
          int n = 7;
          double p = 0.55;
          cpp_float result = ts::P(3, 5, n, p);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        // P(1 ≤ X) when n = 9 and p = 0.15
        void d() {
          int n = 9;
          double p = 0.15;
          cpp_float result = 1 - ts::bin(0, n, p);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }
      }

      namespace sec2 {
        int n = 25;
        double p = 0.05;

        // Determine P(X ≤ 2)
        void a() {
          cpp_float result = ts::P(0, 2, n, p);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        // Determine P(X ≥ 5)
        void b() {
          // P(X >= 5) = 1 - P(X < 5)
          cpp_float result = 1 - ts::P(0, 4, n, p);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        // Determine P(1 ≤ X ≤ 4) = P(X<=4) - P(X <= 0)
        void c() {
          cpp_float result = ts::P(1, 4, n, p);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        // What is the probability that none of the 25 boards is defective?
        void d() {
          cpp_float result = ts::bin(0, n, p);
          cout << ts::round_x_decimal_places(result, 3) << endl;
        }

        void e() {
          cpp_float result = n * p;
          cout << ts::round_x_decimal_places(result, 3)<< endl;

          double q = 1 - p;
          result = sqrt(n * p * q);
          cout << ts::round_x_decimal_places(result, 3) << endl;
>>>>>>> f739e83844d77987b731adc58013a23e86612bc0
        }
      }

      namespace sec3 {
<<<<<<< HEAD

      }

      namespace sec4 {

=======
        
>>>>>>> f739e83844d77987b731adc58013a23e86612bc0
      }
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

          urban.pop_front();
          urban.pop_back();
          farm.pop_front();
          farm.pop_back();
          cout << "Trimmed Urban mean: " << ts::deque_mean(urban) << endl;
          cout << "Trimmed Farm mean: " << ts::deque_mean(farm) << endl;

          cout << "Trimming percentage for urban: " << (1.0 / n1) * 100 << endl;
          cout << "Trimming percentage for farm: " << (1.0 / n2) * 100 << endl;
        }

        void q35() {
          deque<double> nums;
          ts::put_nums_in_deque(nums, "mercury.txt");
          sort(nums.begin(), nums.end());

          cout << "Sample mean: " << ts::deque_mean(nums) << endl;
          cout << "Sample median: " << ts::deque_median(nums) << endl;

          cout << "Trimmed mean: " << ts::deque_trimmed_mean(nums, 10) << endl;

          nums.clear();
          ts::put_nums_in_deque(nums, "mercury.txt");
          sort(nums.begin(), nums.end());

          cout << ts::increment_first_number_until_median_changes(nums) << endl;
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

          cout << "Cooler std. dev < Control std. dev < Warmer std. dev" << endl;
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

    // 1.3 - 1.4 Measures of Location and Variability
    namespace two {

    }

    // 2.3 - Counting Techniques
    namespace three {
      namespace sec1 {
        int zin = 8, mer = 10, cab = 12, tot = 30, bot = 6;
        cpp_int c_ans = 0;

        void a() {
          cpp_int perms = ts::perm(zin, 3);
          cout << perms << endl;
        }

        void b() {
          cout << ts::ch(tot, bot) << endl;
        }

        void c() {
          c_ans = ts::ch(zin, 2) * ts::ch(mer, 2) * ts::ch(cab, 2);
          cout << c_ans << endl;
        }

        void d() {
          cpp_float top = cpp_float(c_ans);
          cpp_float bottom = cpp_float(ts::ch(tot, bot));
          cout << ts::round_x_decimal_places(top / bottom, 3) << endl;
        }

        void e() {
          cpp_int top = ts::ch(zin, bot) + ts::ch(mer, bot) + ts::ch(cab, bot);
          cpp_int bottom = ts::ch(tot, bot);
          cout <<
               ts::round_x_decimal_places(cpp_float(top) / cpp_float(bottom), 3)
               << endl;
        }
      }
    }

    void run() {

    }
  }
}

namespace exam {
  /*
   * The propagation of fatigue cracks in various aircraft parts has been the subject of extensive study in recent years. The accompanying data consists of propagation lives (flight hours/104) to reach a given crack size in fastener holes intended for use in military aircraft.
   */
  namespace sec1 {
    vector<double> nums;

    void a() {
      ts::put_nums_in_vector(nums, "sec1.txt");
      cout << ts::round_x_decimal_places(ts::vector_mean(nums), 4) << endl;
      cout << ts::round_x_decimal_places(ts::vector_median(nums), 4) << endl;
    }

    void b() {
      cout << ts::decrement_last_number_before_median_changes(nums) << endl;
    }
  }

  /*
   *  An article reported the following data on oxidation-induction time (min) for various commercial oils:
   */
  namespace sec2 {
    vector<double> nums;

    void a() {
      ts::put_nums_in_vector(nums, "sec2.txt");
      cout << ts::sample_variance(nums) << endl;
      cout << ts::round_x_decimal_places(ts::sample_standard_deviation(nums), 3) << endl;
    }

    void b() {
      // express the numbers in hours
      transform(nums.begin(), nums.end(), nums.begin(), [](double X) { return X / 60.0; });
      cout << ts::sample_variance(nums) << endl;
      cout << ts::sample_standard_deviation(nums) << endl;
    }
  }

  /*
   *  An individual is presented with three different glasses of cola, labeled C, D, and P. He is asked to taste all three and then list them in order of preference. Suppose the same cola has actually been put into all three glasses.
   */
  namespace sec4 {
    void a() {
      char cola[3] = {'c', 'd', 'p'};

      do {
        cout << cola[0] << ' ' << cola[1] << ' ' << cola[2] << endl;
      } while (next_permutation(cola, cola + 3));
    }
  }

  /*
   * A stereo store is offering a special price on a complete set of components (receiver, compact disc player, speakers, turntable). A purchaser is offered a choice of manufacturer for each component.
   */
  namespace sec5 {
    vector<string> rec = {"Kenwood", "Sony", "Sherwood"};
    vector<string> cdp = {"Onkyo", "Pioneer", "Sony", "Technics"};
    vector<string> spk = {"Boston", "Infinity", "Polk"};
    vector<string> cas = {"Onkyo", "Sony", "Teac", "Technics"};

    int w = rec.size(), x = cdp.size(), y = spk.size(), z = cas.size();
    cpp_int total = 0, without_sony = 0, one_sony = 0;

    void a() {
      total = ts::ch(w, 1) * ts::ch(x, 1) * ts::ch(y, 1) * ts::ch(z, 1);
      cout << total << endl;
    }

    void b() {
      int rec_c = count(rec.begin(), rec.end(), "Sony");
      int cdp_c = count(cdp.begin(), cdp.end(), "Sony");

      cout << ts::ch(rec_c, 1) * ts::ch(cdp_c, 1)
              * ts::ch(y, 1) * ts::ch(z, 1) << endl;
    }

    void c() {
      int rec_wo_sony = w - count(rec.begin(), rec.end(), "Sony");
      int cdp_wo_sony = x - count(cdp.begin(), cdp.end(), "Sony");
      int spk_wo_sony = y - count(spk.begin(), spk.end(), "Sony");
      int cas_wo_sony = z - count(cas.begin(), cas.end(), "Sony");

      without_sony = ts::ch(rec_wo_sony, 1) * ts::ch(cdp_wo_sony, 1)
                     * ts::ch(spk_wo_sony, 1) * ts::ch(cas_wo_sony, 1);

      cout << without_sony << endl;
    }

    void d() {
      one_sony = total - without_sony;
      cout << one_sony << endl;
    }

    void e() {
      cout << cpp_float(one_sony) / cpp_float(total) << endl;


      cout << "UHHH" << endl;
    }
  }

  /*
   * Eighty percent of all vehicles examined at a certain emissions inspection station pass the inspection. Assuming that successive vehicles pass or fail independently of one another, calculate the following probabilities. (Enter your answers to three decimal places.)
   * */
  namespace sec7 {
    double per = 0.8;

    int x = 3, y = 1;

    cpp_float a_ans = 0, c_ans = 0, d_ans = 0;

    // P(all of the next three vehicles inspected pass)
    void a() {
      a_ans = cpp_float(ts::ch(x, x)) * cpp_float(pow(per, x) * pow((1 - 0.80), x - x));
      cout << a_ans << endl;
    }

    // P(at least one of the next three inspected fails)
    void b() {
      cout << 1 - a_ans << endl;
    }

    // P(exactly one of the next three inspected passes)
    void c() {
      c_ans = cpp_float(ts::ch(x, y)) * cpp_float(pow(per, y) * pow((1 - 0.80), x - y));
      cout << c_ans << endl;
    }

    void d() {
      d_ans = cpp_float(ts::ch(x, 0)) * cpp_float(pow(per, 0) * pow((1 - 0.80), x))
              + cpp_float(ts::ch(x, y)) * cpp_float(pow(per, y) * pow((1 - 0.80), x - y));
      cout << d_ans << endl;
    }

    void e() {
      cpp_float denom = 1 - cpp_float(ts::ch(x, 0)) * cpp_float(pow(per, 0) * pow((1 - 0.80), x));
      cout << a_ans / denom << endl;
    }
  }

  /*
   * Airlines sometimes overbook flights. Suppose that for a plane with 50 seats, 55 passengers have tickets. Define the random variable Y as the number of ticketed passengers who actually show up for the flight. The probability mass function of Y appears in the accompanying table.
   */
  namespace sec9 {
    map<int, double> m{{45, 0.06},
                       {46, 0.10},
                       {47, 0.11},
                       {48, 0.14},
                       {49, 0.26},
                       {50, 0.16},
                       {51, 0.06},
                       {52, 0.05},
                       {53, 0.03},
                       {54, 0.02},
                       {55, 0.01}};

    // What is the probability that the flight will accommodate all ticketed passengers who show up?
    void a() {
      double sum = 0;
      for (int i = 45; i <= 50; ++i)
        sum += m[i];
      cout << sum << endl;
    }

    // What is the probability that not all ticketed passengers who show up can be accommodated?
    void b() {
      double sum = 0;
      for (int i = 51; i <= 55; ++i)
        sum += m[i];
      cout << sum << endl;
    }

    void c() {
      /*
       * If you are the first person on the standby list (which means you will be the first one to get on the plane if there are any seats available after all ticketed passengers have been accommodated), what is the probability that you will be able to take the flight?
       */
      double sum = 0;
      for (int i = 45; i < 50; ++i)
        sum += m[i];
      cout << sum << endl;

      // What is this probability if you are the third person on the standby list?
      sum = 0;
      for (int i = 45; i <= 47; ++i)
        sum += m[i];
      cout << sum << endl;
    }
  }

  /*
   *  A mail-order computer business has six telephone lines. Let X denote the number of lines in use at a specified time. Suppose the pmf of X is as given in the accompanying table.
   */
  namespace sec10 {
    vector<double> x{0, 1, 2, 3, 4, 5, 6};
    vector<double> px{0.12, 0.15, 0.20, 0.23, 0.20, 0.07, 0.03};

    double b_ans = 0;

    void F() {
      double sum = 0;
      for (int i = 0; i < px.size(); ++i) {
        sum += px[i];
        cout << sum << " ";
      }
      cout << endl;
    }

    //{at most three lines are in use}
    void a() {
      double sum = 0;
      for (int i = 0; i <= 3; ++i)
        sum += px[i];
      cout << sum << endl;
    }

    // {fewer than three lines are in use}
    void b() {
      double sum = 0;
      for (int i = 0; i <= 2; ++i)
        sum += px[i];
      b_ans = sum;
      cout << b_ans << endl;
    }

    // {at least three lines are in use}
    void c() {
      cout << 1 - b_ans << endl;
    }

    // {between two and five lines, inclusive, are in use}
    void d() {
      double sum = 0;
      for (int i = 2; i <= 5; ++i)
        sum += px[i];
      cout << sum << endl;
    }
  }

  /*
   *  An individual who has automobile insurance from a certain company is randomly selected. Let Y be the number of moving violations for which the individual was cited during the last 3 years. The pmf of Y is the following.
   */
  namespace sec11 {
    vector<double> y{0, 1, 2, 3};
    vector<double> py{0.55, 0.25, 0.15, 0.05};

    // Compute E(Y).
    void a() {
      cout << ts::E(y, py) << endl;
    }

    // Suppose an individual with Y violations incurs a surcharge of $100Y2
    void b() {
      cout << ts::E(y, py, [](double Y) { return 100 * Y * Y; }) << endl;
    }
  }
}