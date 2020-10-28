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
 * Chapter 5 - exercise 9
 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void no_words_error() {
  throw domain_error("no words detected");
}

void display(const vector<string> &words) {
  if (words.size() == 0) {
    no_words_error();
  }

  for (vector<string>::const_iterator it = words.begin();
       it != words.end(); ++it) {
    cout << *it << endl;
  }
}

bool is_uppercase(string word) {
  for (string::const_iterator it = word.begin();
       it != word.end(); ++it) {
    if (!isupper(*it)) {
      return false;
    }
  }

  return true;
}

bool is_lowercase(string word) {
  for (string::const_iterator it = word.begin();
       it != word.end(); ++it) {
    if (!islower(*it)) {
      return false;
    }
  }

  return true;
}

/* main: Writes the lowercase input words followed by the uppercase input words. */
int main() {
  vector<string> uppercase_words;
  vector<string> lowercase_words;

  cout << "Enter words, followed by end-of-file: ";
  string x;
  while (cin >> x) {
    if (is_uppercase(x)) {
      uppercase_words.push_back(x);
    } else if (is_lowercase(x)) {
      lowercase_words.push_back(x);
    } else {
        cout << "You should only enter lowercase or uppercase words" << endl;
        return 1;
    }
    
  }

  cout << endl << "Lowercase words: " << endl << endl;
  try {
    display(lowercase_words);
  } catch (domain_error) {
      cout << "No lowercase words entered" << endl;
  }
  
  cout << endl << "Uppercase words: " << endl << endl;
  try {
    display(uppercase_words);
  } catch (domain_error) {
    cout << "No uppercase words entered" << endl;
  }
  
  return 0;
}
