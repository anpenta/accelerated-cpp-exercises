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
 * Chapter 7 - exercise 9
 
 */

#include <iostream>

using namespace std;

/* nrand: Returns a random integer in the range [0, n). */
int nrand(int n) {
  if (n <= 0) {
    throw domain_error("argument to nrand should be positive");
  }

  int r;
  int times;

  /* Determine the times that n is divisible by RAND_MAX. */
  if (n <= RAND_MAX) {
    times = 1;
  } else {
      times = 0;
      while (n > RAND_MAX) {
          ++times;
          n /= RAND_MAX;
      }
  }

  /* Compute r in the appropriate range. */
  const int bucket_size = times * RAND_MAX / n;
  do {
    r = rand() / bucket_size;
  } while (r >= n);

  return r;
}

/* main: Tests the nrand function. */
int main() {
  int n;

  cout << "Enter a positive integer: ";
  cin >> n;
  cout << "Generated integer: " << nrand(n) << endl;

  return 0;
}
