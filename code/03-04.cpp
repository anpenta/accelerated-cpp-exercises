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
 * Chapter 3 - exercise 4
 
 */

#include <iostream>
#include <vector>

using namespace std;

/* main: Reports the length of the shortest and longest string in its input. */
int main() {
  vector<string> words;
  string x;

  /* Get the input words. */
  cout << "Enter a list of words, "
          "followed by end-of-file to indicate the end: ";
  while (cin >> x) {
    words.push_back(x);
  }

  cout << endl;
  
  /* If no words were entered, terminate the program. */
  if (words.size() == 0) {
    cout << "You did not enter any words." << endl;
    return 1;
  }

  int max, min;
  for (vector<string>::size_type i = 0; i < words.size(); ++i) {
    if (i == 0) {
      max = words[i].length();
      min = words[i].length();
    } else {
        max = words[i].length() > max ? words[i].length() : max;
        min = words[i].length() < min ? words[i].length() : min;
    }
  }
  
  cout << "Maximum string length: " << max << endl;
  cout << "Minimum string length: " << min << endl;

  return 0;
}
