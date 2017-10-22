  if (tilerow == blankrow && tilecolumn - blankcolumn == 1)
    {
        // tile is righ or left of blank
        int temp = board[blankrow][blankcolumn];
        tilerow = board[blankrow][blankcolumn];
        board[blankrow][blankcolumn] = temp;  
        return true;
    }
    if ((abs(tilerow - blankrow) == 1) && tilecolumn == blankcolumn)
    {
        // tile below or above blank
        int temp = board[blankrow][blankcolumn];
        tilerow = board[blankrow][blankcolumn];
        board[blankrow][blankcolumn] = temp;        
        return true;
    }
    return false;




int swap(int* [], int* [])
{
    int temp = *a;
    *a = *b;
    *b = *temp;
}