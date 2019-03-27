/*****************************************************************************************************************
Lab 6: This program provides the implementation for the LoShuSquare and Player classes, which are used
       to allow the user to play the Lo Shu Magic Square game through standard input.
Author: Vincent Nguyen
Date: 3/15/2019
*****************************************************************************************************************/


#ifndef LoShuSquare_h
#define LoShuSquare_h

#include <iostream>


class LoShuSquare {
    private:
        int grid[3][3];
        int LoShuSum;
    public:
/*****************************************************************************************************************
Constructor of LoShuSquare
******************************************************************************************************************/
        LoShuSquare()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j] = 0;
                }
            }
        }

/*******************************************************************************************************
the function fillSquare takes in the row and column indexes and values to modify each square in the grid
*******************************************************************************************************/
        void fillSquare(int row, int col, int value){grid[row][col] = value;}

/*******************************************************************************************************
the function printBoard prints each value in the 2D array
*******************************************************************************************************/
        void printBoard()
        {
            std::cout << std::endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    std::cout << grid[i][j];
                }
                std::cout << std::endl;
            }
        }
/*******************************************************************************************************
the function checkRow adds the sum of each row and checks if they are equal
*******************************************************************************************************/
        bool checkRow()
        {
            LoShuSum = grid[0][0] + grid[0][1] + grid[0][2];
            int sum;

            for (int i = 1; i < 3; i++)
            {
                sum = 0;
                for (int j = 0; j < 3; j++)
                {
                    sum += grid[i][j];
                }
                if (sum == LoShuSum)
                    continue;
                else
                    return false;
            }
            LoShuSum = sum;
            return true;
        }
/*******************************************************************************************************
the function checkCol adds the sum of each column and checks if they are equal
*******************************************************************************************************/
        bool checkCol()
        {
            for (int i = 0; i < 3; i++)
            {
                int sum = 0;
                for (int j = 0; j < 3; j++)
                {
                    sum += grid[j][i];
                }
                if (sum == LoShuSum)
                    continue;
                else
                    return false;
            }
            return true;
        }
/*******************************************************************************************************
the function checkDia adds the sum of each diagonal and checks if they are equal
*******************************************************************************************************/
        bool checkDia()
        {
            if ((grid[0][0] + grid[1][1] + grid[2][2] == LoShuSum) && (grid[0][2] + grid [1][1] + grid[2][0] == LoShuSum))
                return true;
            else
                return false;
        }

        bool checkDuplicates()
        {
            int values[] = {grid[0][0], grid[0][1], grid[0][2],
                            grid[1][0], grid[1][1], grid[1][2],
                            grid[2][0], grid[2][1], grid[2][2]};
            for (int number = 1; number < 10; number++)
            {
                int dup = 0;
                for (int index = 0; index < 9; index++)
                {
                    if (number == values[index])
                        dup++;
                }
                if (dup > 1)
                    return true;
            }
            return false;
        }
/*******************************************************************************************************
the function checkAll checks if each of the check functions are true. If true, it checks for duplicates
and displays a message and returns false for checkAll() if true.
*******************************************************************************************************/
        bool checkAll()
        {
            if ((checkRow() == true) && (checkDia() == true) && (checkCol() == true))
            {
                if(checkDuplicates() == true)
                {
                    std::cout << "The sums are equal, but there are duplicates in the grid. A Lo Shu Square contains the numbers 1-9 exactly.\n";
                    return false;
                }
                else
                    return true;
            }
            else
                return false;
        }
};

#endif
