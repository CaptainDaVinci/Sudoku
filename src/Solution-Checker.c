#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkSolution(int [][9], int, int, int);

int main(void)
{
    int i, j;
    int grid[9][9];

    printf("\nWant to check your sudoku solution ?\n\n");

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(!(checkSolution(grid, grid[i][j], i, j)))
            {
                printf("\nOops! something is wrong.\n");
                exit(0);
            }
        }
    }
    printf("\nYour solution is correct!\n");
}

bool checkSolution(int grid[][9],int valueAtCell, int i, int j)
{
    int row = i;
    int cols = j;

    for(row = 0; row < 9; row++)
    {
        if(grid[row][j] == valueAtCell && row != i)
            return false;
    }

    for(cols = 0; cols < 9; cols++)
    {
        if(grid[i][cols] == valueAtCell && cols != j)
            return false;
    }

    for(int tempi = 0, row = i - i % 3; tempi < 3; tempi++, row++)
    for(int tempj = 0, cols = j - j % 3; tempj < 3; tempj++, cols++)
    {
        if(grid[row][cols] == valueAtCell && row != i && cols != j)
        {
            return false;
        }
    }

    return true;
}