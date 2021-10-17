#include <stdbool.h>
#include <stdio.h>
bool isSafe(char board[][100], int row, int col,int N)
{
    int i,j;
    for (i=0;i<col;i++)
        if (board[row][i]=='Q')
            return false;

    for (i=row,j=col;i>=0&&j>= 0;i--,j--)
        if (board[i][j]=='Q')
            return false;

    for (i=row,j=col;j>=0&&i<N;i++,j--)
        if (board[i][j]=='Q')
            return false;
  
    return true;
}
bool placing(char board[][100], int col,int N)
{ int i;
    if (col >= N)
        return true;
    for ( i=0;i<N;i++) 
    {
        if (isSafe(board,i,col,N))
        {
            board[i][col] = 'Q';
            if (placing(board, col + 1,N))
                return true;
            board[i][col] = '-';
        }
    }
    return false;
}

int main()
{
    int q,i,j;
    printf("Enter number of queens -  ");
    scanf("%d",&q);
    
    char board[100][100];
    for( i=0;i<q;i++)
    for( j=0;j<q;j++)
    board[i][j]='-';


    if (placing(board, 0,q) == false) {
        printf("Solution does not exist");
        return false;
    }
  
    printf("\n");
    for ( i = 0; i < q; i++) {
        int p;
        for ( j = 0; j < q; j++)
        {
            printf(" %c ", board[i][j]);
            if(board[i][j]=='Q')
            p=j+1;
        }
        printf("    %d\n",p);
    }
    return 0;
}
