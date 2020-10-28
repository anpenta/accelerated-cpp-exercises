/*  
 * Copyright (C) 2019 Andreas Pentaliotis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
	
/* 
 * Accelerated C++: Practical Programming by Example (2000) by Andrew Koenig and Barbara E. Moo
 * Chapter 3 - exercise 2
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double>::size_type vec_sz;

double median(vector<double> integers, int start, int end) {
  vec_sz size = start + end;
  vec_sz mid = size / 2;
  double median;

  median = size % 2 == 0 ? (integers[mid] + integers[mid - 1]) / 2
                         : integers[mid];

  return median;
}

/* main: Computes and prints the quartiles of a set of integers. */
int main() {
  vector<double> integers;
  int x;

  /* Get the input integers. */
  cout << "Enter a list of integers, "
          "followed by end-of-file to indicate the end: ";
  while (cin >> x) {
    integers.push_back(x);
  }

  vec_sz size = integers.size();

  /* If no integers were entered, terminate the program. */
  if (size == 0) {
    cout << "You did not enter any integers." << endl;
    return 1;
  }

  sort(integers.begin(), integers.end());
  
  vec_sz mid = size / 2;
  vec_sz quartile_1_end;
  vec_sz quartile_2_start;

  /* If there is an odd number of integers, exclude the median from both halves. */
  if (size % 2 == 1) {
    quartile_1_end = mid;
    quartile_2_start = mid + 1;
  } else {
      quartile_1_end = mid;
      quartile_2_start = mid;
  }
  
  cout << "Quartile 1" << endl;
  cout << median(integers, 0, quartile_1_end) << endl;

  cout << "Quartile 2" << endl;
  cout << median(integers, 0, size) << endl;

  cout << "Quartile 3" << endl;
  cout << median(integers, quartile_2_start, size) << endl;
  
  return 0;
}
