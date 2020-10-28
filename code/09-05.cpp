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
 * Chapter 9 - exercise 5
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Student {
  public:
    Student(std::string input_name, double input_midterm, double input_final);
    char read_grade() const {return grade;};
    std::string read_name() const {return name;};

  private:
    std::string name;
    double midterm, final;
    char grade;
    char compute_grade() {return ((midterm + final) / 2.0) > 60.0 ? 'P' : 'F';};
};

Student::Student(std::string input_name, double input_midterm, double input_final) {
  name = input_name;
  midterm = input_midterm;
  final = input_final;
  grade = compute_grade();
}

bool compare(const Student &a, const Student &b) {
  return a.read_name() < b.read_name();
}

void display(const std::vector<Student> &record) {
  for (std::vector<Student>::const_iterator i = record.begin();
       i != record.end(); ++i) {
    std::cout << i->read_name() << ' ' << i->read_grade() << std::endl; 
  }
}

/* main: Tests the Student class. Note that we also handle the next exercise. */
int main() {
  std::vector<Student> record;
  Student a("George", 10, 40);
  Student b("Drake", 70, 20);
  Student c("John", 80, 70);

  record.push_back(a);
  record.push_back(b);
  record.push_back(c);

  sort(record.begin(), record.end(), compare);
  std::stable_partition(record.begin(), record.end(), [](Student st){return st.read_grade() == 'P';});
  display(record);

  return 0;
}
