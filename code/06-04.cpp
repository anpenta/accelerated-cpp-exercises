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
 * Chapter 6 - exercise 4
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_vector(vector<int> &v) {
  if (!v.empty()) {
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
      cout << *i << " ";
    }
    cout << endl;
  }
}

/* main: Copies u to v1 and u to v2 in two different ways. */
int main() {
  vector<int> u(10, 100);
  vector<int> v1;
  vector<int> v2;
  
  copy(u.begin(), u.end(), back_inserter(v1));
  copy(u.begin(), u.end(), inserter(v2, v2.begin()));

  cout << "u: ";
  display_vector(u);

  cout << "v1: ";
  display_vector(v1);

  cout << "v2: ";
  display_vector(v2);
  
  return 0;
}
