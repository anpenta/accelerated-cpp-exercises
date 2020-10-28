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
 * Chapter 16 - exercise 1
 
 */

#include <iostream>

char data[] = {10,10,105,110,116,32,109,97,105,110,40,41,32,123,10,32,32,115,116,100,58,58,99,111,117,116,32,60,60,32,115,116,100,58,58,101,110,100,108,32,60,60,32,34,35,105,110,99,108,117,100,101,32,60,105,111,115,116,114,101,97,109,62,34,32,60,60,32,115,116,100,58,58,101,110,100,108,32,60,60,32,115,116,100,58,58,101,110,100,108,59,10,32,32,115,116,100,58,58,99,111,117,116,32,60,60,32,34,99,104,97,114,32,100,97,116,97,91,93,32,61,32,123,34,59,10,32,32,102,111,114,32,40,115,105,122,101,95,116,32,105,32,61,32,48,59,32,105,32,60,32,115,105,122,101,111,102,40,100,97,116,97,41,59,32,43,43,105,41,32,123,10,32,32,32,32,115,116,100,58,58,99,111,117,116,32,60,60,32,40,105,110,116,41,100,97,116,97,91,105,93,32,60,60,32,34,44,34,59,10,32,32,125,10,32,32,115,116,100,58,58,99,111,117,116,32,60,60,32,34,125,59,34,59,10,32,32,115,116,100,58,58,99,111,117,116,32,60,60,32,100,97,116,97,59,10,32,32,114,101,116,117,114,110,32,48,59,10,125,10,};

/* main: Reproduces its own source code, excluding the comments. */
int main() {
  std::cout << std::endl << "#include <iostream>" << std::endl << std::endl;
  std::cout << "char data[] = {";
  for (size_t i = 0; i < sizeof(data); ++i) {
    std::cout << (int)data[i] << ",";
  }
  std::cout << "};";
  std::cout << data;
  return 0;
}
