/*******************************************************************************************************
Lab 6: This program provides the implementation for the LoShuSquare and Player classes, which are used
       to allow the user to play the Lo Shu Magic Square game through standard input.
Author: Vincent Nguyen
Date: 3/15/2019
*******************************************************************************************************/
#ifndef Player_h
#define Player_h

#include <iostream>
#include "LoChuSquare.h"

/*******************************************************************************************************
the Player class first explains the rules of the game and how to modify values. After the first change,
checkAll()l is called to check for equality and duplicity. Each time the user enters values to change the
grid, printBoard(); is called to display the updated grid. The program runs until the user completes
a Lo Shu Square.
*******************************************************************************************************/
class Player {
    public:
        Player(LoShuSquare object)
        {
            std::cout << "To change a square, enter the row, column, and number separated by spaces (Example: 1 1 5). Rows and columns are numbered 1 to 3 and a Lo Shu Square contains the numbers 1-9 exactly. You win when each row, column, and diagonal have an equal sum, and there are no duplicate numbers!\n";
            object.printBoard();

            int row, col, val;
            std::cout << "Modify a square:";
                std::cin >> row >> col >> val;
                while (row < 1 || row > 3 || col < 1 || col > 3)
                {
                    std::cout << "Row and column values must be 1-3.\n";
                    std::cout << "Modify a square:";
                    std::cin >> row >> col >> val;
                }
                object.fillSquare(row - 1, col - 1, val);
                object.printBoard();

            while (object.checkAll() == false)
            {
                std::cout << "Modify a square:";
                std::cin >> row >> col >> val;
                while (row < 1 || row > 3 || col < 1 || col > 3)
                {
                    std::cout << "Row and column values must be 1-3.\n";
                    std::cout << "Modify a square:";
                    std::cin >> row >> col >> val;
                    object.fillSquare(row - 1, col - 1, val);
                    object.printBoard();
                }
                object.fillSquare(row - 1, col - 1, val);
                object.printBoard();
            }
            std::cout << "You completed a Lo Shu Square! Congrats!\n";
        }
};

#endif
