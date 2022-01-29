#include <iostream>
#include <vector>

int horizontalCheck(std::vector<std::vector<int>>& game, int i, int k) {
  // Check if its if everything horizontally is the same
  if (game[i][k] == 1 && game[i][k + 1] == 1 && game[i][k + 2] == 1) {
    return 1;
  }
  if (game[i][k] == 2 && game[i][k + 1] == 2 && game[i][k + 2] == 2) {
    return 2;
  }
  return -1;
}

int verticalCheck(std::vector<std::vector<int>>& game, int i, int k) {
  // Check if its if everything vertically is the same
  if (game[i][k] == 1 && game[i + 1][k] == 1 && game[i + 2][k] == 1) {
    return 1;
  }
  if (game[i][k] == 2 && game[i + 1][k] == 2 && game[i + 2][k] == 2) {
    return 2;
  }
  return -1;
}

int diagonalCheck(std::vector<std::vector<int>>& game, int i, int k) {
  // Check if its if everything diagonally is the same
  if (game[i][k] == 1 && game[i + 1][k + 1] == 1 && game[i + 2][k + 2] == 1) {
    return 1;
  }
  if (game[i][k] == 2 && game[i + 1][k + 1] == 2 && game[i + 2][k + 2] == 2) {
    return 2;
  }
  return -1;
}

int backwardsDiagonalCheck(std::vector<std::vector<int>>& game, int i, int k) {
  // Check if its if everything backwards diagonally (up from the bottom is the
  // same
  if (game[i][k] == 1 && game[i - 1][k + 1] == 1 && game[i - 2][k + 2] == 1) {
    return 1;
  }
  if (game[i][k] == 2 && game[i - 1][k + 1] == 2 && game[i - 2][k + 2] == 2) {
    return 2;
  }
  return -1;
}

int CheckGame(std::vector<std::vector<int>>& game) {
  // Your code here to determine if there was a winner, a draw, or if the
  // game can continue.
  bool isEmpty = false;
  int statusOfGame;

  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++) {
      // The purpose is to check the outer columns. Once we are in the inner
      // boxes there is no pont ot loop
      // It has to have an 1 or 2 on the left or top to get 3 in a row.
      if (game[i][k] == 0) {
        isEmpty = true;
      }
      // After checking if the square is empty it then can skip it if its in the
      // bottom
      // 4 starting from the middle
      if (i > 0 && k > 0) {
        continue;
      }
      if (i == 0 && k == 0) {
        // if k and i are both 0 => horizontal, vertical and diagonal check
        statusOfGame = diagonalCheck(game, i, k);
        // if The status check returns 1 or 2 return that person as the winner
        if (statusOfGame != -1) {
          return statusOfGame;
        }
      }
      if (i == 2 && k == 0) {
        // if k and i are both 0 => horizontal, vertical and diagonal check
        statusOfGame = backwardsDiagonalCheck(game, i, k);
        // if The status check returns 1 or 2 return that person as the winner
        if (statusOfGame != -1) {
          return statusOfGame;
        }
      }
      if (i == 0) {
        // if i is 0 => vertical check
        statusOfGame = verticalCheck(game, i, k);
        // if The status check returns 1 or 2 return that person as the winner
        if (statusOfGame != -1) {
          return statusOfGame;
        }
      }
      if (k == 0) {
        // if k is 0 =< horizontal check
        statusOfGame = horizontalCheck(game, i, k);
        // if The status check returns 1 or 2 return that person as the winner
        if (statusOfGame != -1) {
          return statusOfGame;
        }
      }
    }
  }
  // lastly check if there are any zeros to return still in progress vs.
  // catsgaeme
  if (isEmpty == true) {
    statusOfGame = 0;
    return statusOfGame;
  } else {
    statusOfGame = -1;
    return statusOfGame;
  }
}
