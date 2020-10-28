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
 * Chapter 2 - exercise 9
 
 */

#include <iostream>

using namespace std;

/* main: Determines the largest number out of two input numbers. */
int main() {
  int a, b;
  int max;

  cout << "Enter number a: ";
  cin >> a;

  cout << "Enter number b: ";
  cin >> b;

  max = a > b ? a : b;
  cout << "The largest number is: " << max << endl;

  return 0;
}
