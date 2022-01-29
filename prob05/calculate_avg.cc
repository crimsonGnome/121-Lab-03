// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "calculate_avg.h"

#include <vector>

double CalculateAvg(std::vector<double>& input) {
  // Complete this function.
  // Initialize the variable
  double average = 0;
  int amountOfStudents = input.size();

  for (short int i = 0; i < amountOfStudents; i++) {
    average += input[i];
  }
  // If no class
  if (amountOfStudents <= 0) {
    return 0;
  }
  average = average / amountOfStudents;
  return average;
}
