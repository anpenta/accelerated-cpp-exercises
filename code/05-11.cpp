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
 * Chapter 5 - exercise 11
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void no_words_error() {
  throw domain_error("no words detected");
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

bool has_ascenders(string word) {
  vector<char> ascenders = {'b', 'd', 'f', 'h', 'k', 'l', 't'};
  
  for (string::const_iterator it = word.begin();
       it != word.end(); ++it) {
    if (find(ascenders.begin(), ascenders.end(), *it) != ascenders.end()) {
      return true;
    }
  }

  return false;
}

bool has_descenders(string word) {
  vector<char> descenders = {'g', 'j', 'p', 'q', 'y'};
  
  for (string::const_iterator it = word.begin();
       it != word.end(); ++it) {
    if (find(descenders.begin(), descenders.end(), *it) != descenders.end()) {
      return true;
    }
  }

  return false;
}

/*
 * detect_normal_words: Detects the words in the dictionary vector that do not
 * have ascenders or descenders and stores them in the normal_words vector. Returns
 * the length of the longest normal word, if it exists, otherwise returns 0.
 */
string::size_type detect_normal_words(const vector<string> &dictionary, vector<string> &normal_words) {
  string::size_type max_normal_word_length = 0;

  for (vector<string>::const_iterator it = dictionary.begin();
       it < dictionary.end(); ++it) {
    if (!has_ascenders(*it) && !has_descenders(*it)) {
      normal_words.push_back(*it);
      
      if ((*it).size() > max_normal_word_length) {
        max_normal_word_length = (*it).size();
      }
    }
  }

  return max_normal_word_length;
}

/*
 * main: Finds the longest word in the dictionary that does not have ascenders or
 * descenders. This word is defined as normal.
 */
int main() {
  vector<string> dictionary = {"apples", "bananas", "madam", "racecar"};
  vector<string> normal_words;
  string::size_type max_normal_word_length;

  max_normal_word_length = detect_normal_words(dictionary, normal_words);
  if (max_normal_word_length == 0) {
    cout << "No normal words in the dictionary" << endl;
  } else {
    cout << endl <<  "Longest normal word(s): " << endl << endl;
    display_with_length(normal_words, max_normal_word_length);
  }
  
  return 0;
}
