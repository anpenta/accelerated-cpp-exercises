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
 * Chapter 8 - exercise 4
 
 */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void custom_swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

/* main: Tests the custom_swap function. */
int main() {
  int a = 2;
  int b = 1;

  cout << "a: " << a << "\tb: " << b << endl;
  swap(a, b);
  cout << "a: " << a << "\tb: " << b << endl;
  
  return 0;
}
