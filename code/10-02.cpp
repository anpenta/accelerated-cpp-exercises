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
 * Chapter 10 - exercise 2
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

template <class T, class I>
T median(I begin, I end) {
  if (begin == end) {
    throw std::domain_error("no input grades to compute median");
  }

  std::vector<T> sorter;
  while (begin != end) {
    sorter.push_back(*begin++);
  }
  sort(sorter.begin(), sorter.end());
  size_t mid = sorter.size() / 2;

  return sorter.size() % 2 == 1 ? sorter[mid] : (sorter[mid] + sorter[mid - 1]) / 2;
}

/* main: Tests the median function. Note that we also handle the next exercise. */
int main() {
  int a[] = {1, 2, 7, 5, 3};
  double b[] = {1, 2, 7, 5};
  std::vector<int> c = {10, 5, 9};

  std::cout << "Median of a: " << median<int>(a, a + sizeof(a) / sizeof(*a)) << std::endl;
  std::cout << "Median of b: " << median<double>(b, b + sizeof(b) / sizeof(*b)) << std::endl;
  std::cout << "Median of c: " << median<int>(c.begin(), c.end()) << std::endl;

  return 0;
}
