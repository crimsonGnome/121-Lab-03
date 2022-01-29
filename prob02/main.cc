#include <iostream>
#include <map>
#include <string>

using std::cin, std::cout, std::map, std::string, std::pair;

int main() {
  // Declare variables
  string input;
  string charAmount;
  bool textAnalyze = true;
  cout << "Enter text to analyze: ";
  getline(cin, input);

  // Your code here to analyze the input and let
  // the user see what lettersare in it.

  // Map Initialized.
  map<char, int> mappedInput;
  // Loop over data to insert map
  for (short int i = 0; i < input.length(); i++) {
    // if the character is = to the input, increase count
    char tempChar = input[i];
    if (mappedInput.count(tempChar) == 0) {
      // increase the map size
      mappedInput.insert(pair<char, int>(tempChar, 1));
    } else {
      // Take exsisting mapped data and increase it by 1;
      int count = mappedInput[tempChar] + 1;
      mappedInput[tempChar] = count;
    }
  }
  // first thing do. If we are running text anaylize do not quit
  while (textAnalyze == true) {
    // After ever new loop reset the short int count back to zero
    int count = 0;
    cout << "\nWhat character do you want stats on? ";
    cin >> charAmount;
    // If the input is quit then exit program
    if (charAmount == "quit") {
      break;
    }
    // Find the mapped item
    count = mappedInput[charAmount[0]];

    // After the for loop but befor the wile loop closes return amount
    cout << "\nThe character " << charAmount << " appears " << count
         << " times.";
  }

  std::cout << "Goodbye!" << std::endl;
  return 0;
}
