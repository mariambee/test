/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}


/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // set counter
    int numbers = (d * d) - 1; 
    // loop over rows
    for (int row = 0; row < d; row++)
    {
        // loop over columns
        for (int column = 0; column < d; column++)
        {
            // store numbers in array
            board[row][column] = numbers;
            // decrease counter
            numbers--;
        }
    }
    // check condition of even dimensions
    if (d % 2 == 0)
    {
        // swap numbers 1 and 2 so game can be won
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp;
    }
}


/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // loop over rows
    for (int row = 0; row < d; row++)
    {
        // loop over columns
        for (int column = 0; column < d; column++)
        {
            // find 0
            if (board[row][column] == 0)
            {
                // replace 0
                printf(" - ");
            }
            else if (board[row][column] < 10)
            {
                // print numbers < 10 with an additional space for visual appeal
                printf( " %i ", board[row][column]);
            }
            else
            {
                printf("%i ", board[row][column]);
            }
        }
        // indent two lines for visual appeal
        printf("\n");
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // loop over rows
    for (int row = 0; row < d; row++)
    {
        // loop over columns
        for (int column = 0; column < d; column++)
        {
            // check if position = tile
            if (board[row][column] == tile)
            {
                // check if blank is below tile and check borders
                if (board[row + 1][column] == 0 && (row + 1) < d)
                {
                    // swap
                    int temp = board[row][column];
                    board[row][column] = board[row + 1][column];
                    board[row + 1][column] = temp;
                    return true;
                }
                // check if blank is above tile and check borders
                if (board[row - 1][column] == 0 && (row - 1) >= 0)
                {
                    // swap
                    int temp = board[row][column];
                    board[row][column] = board[row - 1][column];
                    board[row - 1][column] = temp;
                    return true;
                }
                // check if blank is to the left of tile and check borders
                if (board[row][column - 1] == 0 && (column - 1) >= 0)
                {
                    // swap
                    int temp = board[row][column];
                    board[row][column] = board[row][column - 1];
                    board[row][column - 1] = temp;
                    return true;
                }
                // check if blank is to the right of tile and check borders
                if (board[row][column + 1] == 0 && (column + 1) < d)
                {
                    // swap
                    int temp = board[row][column];
                    board[row][column] = board[row][column + 1];
                    board[row][column + 1] = temp;
                    return true;
                }
            }
        }
    }
    return false;
}
                

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // set counter
    int numbers = 1;
    // loop over rows
    for (int row = 0; row < d; row++)
    {
        // loop over columns
        for (int column = 0; column < d; column++)
        {
            {
                // check if numbers in array match winning order
                if (board[row][column] == numbers || (board[d - 1][d - 1] == 0 
                && numbers == d * d))
                {
                    // change counter
                    numbers++;
                }
                else
                {
                    // if a number doesn't match return false
                    return false;
                }
            }
        }
    }
    // if everything matches return true
    return true;
}