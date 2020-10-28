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
 * Chapter 4 - exercise 5
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

istream &read_words(istream& in, vector<string> &words) {
  if (in) {
    words.clear();

    string x;
    while (in >> x) {
      words.push_back(x);
    }

    in.clear();
  }

  return in;
}

void no_words_error() {
  throw domain_error("no words entered");
}

void count_each_word(vector<string> &words) {
  vector<string> unique_words;
  int count;

  for (vector<string>::size_type i = 0; i < words.size(); ++i) {
    /* Skip to the next word, if the current word was counted before. */
    if (unique_words.size() != 0
        && find(unique_words.begin(), unique_words.end(), words[i]) != unique_words.end()) {
      continue;
    }

    unique_words.push_back(words[i]);

    /* Count the occurences of the word. */
    count = 0;
    for (vector<string>::size_type j = 0; j < words.size(); ++j) {
      if (words[i].compare(words[j]) == 0) {
        ++count;
      }
    }
    cout << words[i] + " appears " << count << " time(s)." << endl;
  }
}

/*
 * main: Counts the number of words in the input and how many times
 * each word occured.
 */
int main() {
  vector<string> words;

  cout << "Enter words, followed by end-of-file: ";
  read_words(cin, words);

  /* If no words were entered, terminate the program. */
  if (words.size() == 0) {
    no_words_error();
  }

  cout << endl << "Total number of words entered: " << words.size() << endl << endl;
  count_each_word(words);
  
  return 0;
}
