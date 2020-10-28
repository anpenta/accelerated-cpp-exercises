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
 * Chapter 4 - exercise 2
 
 */

#include <iostream>
#include <iomanip>

using namespace std;

/* main: Calculates the squares of integer values up to 100. */
int main() {
  for (int i = 1; i <= 100; ++i) {
    cout << setw(3) << i << setw(6) << i * i << endl;
  }

  return 0;
}
