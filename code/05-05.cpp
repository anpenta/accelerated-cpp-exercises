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
 * Chapter 5 - exercise 5
 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void picture_empty_error() {
  throw domain_error("picture empty");
}

/* center: Pads and evenly distributes all lines of a given picture. */
vector<string> center(const vector<string> &picture) {
  if (picture.size() == 0) {
    picture_empty_error();
  }

  vector<string> centered_picture;
  vector<string>::size_type width = 0;

  for (vector<string>::const_iterator it = picture.begin();
       it != picture.end(); ++it) {
    if (it->size() > width) {
      width = it->size();
    }
  }

  for (vector<string>::const_iterator it = picture.begin();
       it != picture.end(); ++it) {
    centered_picture.push_back(string((width - (*it).size()) / 2, ' ') +
                               *it + string(width - (*it).size(), ' '));
  }

  return centered_picture;
}

void display(const vector<string> &picture) {
  if (picture.size() == 0) {
    picture_empty_error();
  }

  for (vector<string>::const_iterator it = picture.begin();
       it != picture.end(); ++it) {
    cout << *it << endl;
  }
}

/* main: Tests the center function. */
int main() {
  vector<string> picture = {"|", "||||", "||||||||"};
  vector<string> centered_picture = center(picture);

  display(picture);
  cout << endl;
  display(centered_picture);
  
  return 0;
}
