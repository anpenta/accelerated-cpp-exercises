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
 * Chapter 7 - exercise 1
 
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<string, int> word_count_pair;

bool compare(const word_count_pair &a, const word_count_pair &b) {
  return a.second < b.second;
}

/* main: Writes the input words and their counts in ascending order by count. */
int main() {
  string s;
  map<string, int> counters;
  vector<word_count_pair> sorter;

  while (cin >> s) {
    ++counters[s];
  }

  /* Copy the pairs in the sorter vector and sort them. */
  copy(counters.begin(), counters.end(), back_inserter(sorter));
  sort(sorter.begin(), sorter.end(),compare);

  /* Display the sorted pairs. */
  for (vector<word_count_pair>::const_iterator i = sorter.begin();
       i != sorter.end(); ++i) {
    cout << i->first << " appeared " << i->second << " time(s)" << endl;
  }
  
  return 0;
}
