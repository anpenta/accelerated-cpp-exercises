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
 * Chapter 5 - exercise 10
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

/* display_with_length: Displays the words of given length only. */
void display_with_length(const vector<string> &words, string::size_type length) {
  if (words.size() == 0) {
    no_words_error();
  }

  for (vector<string>::const_iterator it = words.begin();
       it != words.end(); ++it) {
    if ((*it).size() == length) {
      cout << *it << endl;
    }
  }
}

bool is_palindrome(string word) {
  string temp = word;
  reverse(word.begin(), word.end());
  if (word.compare(temp) == 0) {
    return true;
  }

  return false;
}

/*
 * detect_palindromes: Detects the palindromes in the dictionary vector and stores
 * them in the palindromes vector. Returns the length of the longest palindrome(s),
 * if it exists, otherwise returns 0.
 */
string::size_type detect_palindromes(const vector<string> &dictionary, vector<string> &palindromes) {
  string::size_type max_palindrome_length = 0;

  for (vector<string>::const_iterator it = dictionary.begin();
       it < dictionary.end(); ++it) {
    if (is_palindrome(*it)) {
      palindromes.push_back(*it);
      
      if ((*it).size() > max_palindrome_length) {
        max_palindrome_length = (*it).size();
      }
    }
  }

  return max_palindrome_length;
}

/* main: Displays all palindromes in a dictionary and specifies the longest palindrome(s). */
int main() {
  vector<string> dictionary = {"apples", "bananas", "madam", "racecar"};
  vector<string> palindromes;
  string::size_type max_palindrome_length;

  max_palindrome_length = detect_palindromes(dictionary, palindromes);
  if (max_palindrome_length == 0) {
    cout << "No palindromes in the dictionary" << endl;
  } else {
    cout << "Detected palindromes: " << endl << endl;
    display(palindromes);
    cout << endl <<  "Longest palindrome(s): " << endl << endl;
    display_with_length(palindromes, max_palindrome_length);
  }

  return 0;
}
