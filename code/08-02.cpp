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
 * Chapter 8 - exercise 2
 
 */

#include <iostream>
#include <vector>

using namespace std;

bool is_negative(int n) {
  return n < 0;
}

int quadruple(int n) {
  return 4 * n;
}

template<class In>
bool custom_equal(In b, In e, In d) {
  while (b != e) {
    if (*b++ != *d++) {
      return false;
    }
  }
  return true;
}

template<class In, class X>
In custom_find(In b, In e, const X &t) {
  while (b != e) {
    if (*b++ == t) {
      return b;
    }
  }
  return b;
}

template<class In, class Out>
Out custom_copy(In b, In e, Out d) {
  while (b != e) {
    *d++ = *b++;
  }
  return d;
}

template<class In, class Out, class P>
Out custom_remove_copy_if(In b, In e, Out d, P p) {
  while (b != e) {
    if (!p(*b)) {
      *d++ = *b;
    }
    ++b;
  }
  return d;
}

template<class In, class Out, class F>
Out custom_transform(In b, In e, Out d, F f) {
  while (b != e) {
    *d++ = f(*b++);
  }
  return d;
}

template<class In, class T>
T custom_accumulate(In b, In e, T t) {
  while (b != e) {
    t += *b++;
  }
  return t;
}

template<class For>
For custom_search(For b, For e, For b2, For e2) {
  while (b != e) {
    if (custom_equal(b2, e2, b)) {
      return b;
    }
    ++b;
  }
  return e;
}

template <class In, class P>
In custom_find_if(In b, In e, P p) {
  while (b != e) {
    if (p(*b)) {
      return b;
    }
    ++b;
  }
  return e;
}

template<class In, class Out, class T>
Out custom_remove_copy(In b, In e, Out d, const T &t) {
  while (b != e) {
    if (*b != t) {
      *d++ = *b;
    }
    ++b;
  }
  return d;
}

template <class For, class T>
For custom_remove(For b, For e, const T &t) {
  For temp = b;
  while (b != e) {
    if (*b != t) {
      *temp++ = *b;
    }
    ++b;
  }
  return temp;
}

template <class Bi, class P>
Bi custom_partition(Bi b, Bi e, P p) {
  Bi temp = b;
  while (b != e) {
    if (p(*b)) {
      swap(*temp++, *b);
    }
    ++b;
  }
  return temp;
}

/* main: Tests the implemented library algorithms. */
int main() {
  vector<int> v1 = {1, 2};
  vector<int> v2 = {1, 2};
  vector<int> v3 = {1, 1};
  vector<int> v4;
  vector<int> v5 = {4, 8};
  vector<int> v6 = {1};
  vector<int> v7;
  vector<int> v8 = {10, 9, -3, -2};

  cout << boolalpha;

  cout << "Testing custom_equal: " << endl;
  cout << custom_equal(v1.begin(), v1.end(), v2.begin()) << endl;
  cout << custom_equal(v1.begin(), v1.end(), v3.begin()) << endl;
  cout << endl;

  cout << "Testing custom_find: " << endl;
  cout << (v1.end() == custom_find(v1.begin(), v1.end(), 1)) << endl;
  cout << (v1.end() == custom_find(v1.begin(), v1.end(), 3)) << endl;
  cout << endl;

  cout << "Testing custom_copy: " << endl;
  custom_copy(v1.begin(), v1.end(), v3.begin());
  cout << custom_equal(v1.begin(), v1.end(), v3.begin()) << endl;
  cout << endl;

  cout << "Testing custom_remove_copy_if: " << endl;
  custom_remove_copy_if(v1.begin(), v1.end(), back_inserter(v4), is_negative);
  cout << custom_equal(v1.begin(), v1.end(), v4.begin()) << endl;
  cout << endl;

  cout << "Testing custom_transform: " << endl;
  custom_transform(v1.begin(), v1.end(), v4.begin(), quadruple);
  cout << custom_equal(v4.begin(), v4.end(), v5.begin()) << endl;
  cout << endl;

  cout << "Testing custom_accumulate: " << endl;
  cout << custom_accumulate(v5.begin(), v5.end(), 0) << endl;
  cout << endl;

  cout << "Testing custom_search: " << endl;
  cout << (v1.end() == custom_search(v1.begin(), v1.end(), v6.begin(), v6.end())) << endl;
  cout << (v5.end() == custom_search(v5.begin(), v5.end(), v6.begin(), v6.end())) << endl;
  cout << endl;

  cout << "Testing custom_find_if: " << endl;
  cout << (v1.end() == custom_find_if(v1.begin(), v1.end(), is_negative)) << endl;
  cout << endl;

  cout << "Testing custom_remove_copy: " << endl;
  custom_remove_copy(v1.begin(), v1.end(), back_inserter(v7), 2);
  cout << (*(v1.begin()) == *(v7.begin())) << endl;
  cout << endl;

  cout << "Testing custom_remove: " << endl;
  custom_remove(v1.begin(), v1.end(), 1);
  cout << (*(v1.begin()) == 2) << endl;
  cout << endl;

  cout << "Testing custom_partition: " << endl;
  custom_partition(v8.begin(), v8.end(), is_negative);
  cout << is_negative(*(v8.begin())) << endl;
  cout << is_negative(*(v8.begin() + 1)) << endl;
  cout << endl;

  return 0;
}
