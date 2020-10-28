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
 * Chapter 4 - exercise 3
 
 */

#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_VAL 1000

int get_number_length(int x) {
  int length = 1;
  while (x / 10 != 0) {
    x /= 10;
    ++length;
  }
}

/* main: Calculates the squares of integer values up to MAX_VAL. */
int main() {
  int integer_length = get_number_length(MAX_VAL);
  int square_length = get_number_length(MAX_VAL * MAX_VAL);

  for (int i = 1; i <= MAX_VAL; ++i) {
    cout << setw(integer_length) << i << setw(square_length) << i * i << endl;
  }

  return 0;
}
