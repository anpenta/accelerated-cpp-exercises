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
 * Chapter 3 - exercise 5
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#define NUM_HOMEWORK_GRADES 2

/* main: Keeps track of grades for several students at once. */
int main() {
  vector<string> student_names;
  vector<double> student_grades;
  int num_students;

  cout << "Enter the number of students: ";
  cin >> num_students;
  if (num_students <= 0) {
    cout << "Number of students should be positive." << endl;
    return 1;
  }

  while (num_students > 0) {
    cout << endl;

    /* Get the student's name. */
    string x;
    cout << "Enter the student's name: ";
    cin >> x;
    student_names.push_back(x);

    /* Get the midterm and final grades. */
    double midterm, final;
    cout << "Enter the midterm grade and the final grade: ";
    cin >> midterm >> final;

    /* Get the homework grades. */
    double sum = 0;
    int count = 0;
    double y;
    cout << "Enter your " << NUM_HOMEWORK_GRADES << " homework grades: ";
    while (count < NUM_HOMEWORK_GRADES) {
      cin >> y;
      sum += y;
      ++count;
    }

    /* We also handle count as requested in exercise 6 of the same chapter. */
    double homework_grade = count > 0 ? sum / count : 0;

    double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * homework_grade;
    student_grades.push_back(final_grade);

    --num_students;
  }

  /* Report the name and grade of each student. */
  for (vector<string>::size_type i = 0; i < student_names.size(); ++i) {
    cout << endl;
    streamsize prec = cout.precision();
    cout << "Student name: " << student_names[i] << setprecision(3) << endl;
    cout << "Grade: " << student_grades[i] << setprecision(prec) << endl;
  }

  return 0;
}
