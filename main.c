#include <stdio.h>

char board[3][3];         // Ігрове поле
char currentPlayer;       // Поточний гравець: 'X' або 'O'

// Ініціалізація порожнього поля
void initBoard()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

// Вивід поля на екран
void printBoard()
{
    printf("\n     1   2   3\n");
    for (int row = 0; row < 3; ++row)
    {
        printf("   +---+---+---+\n");
        printf(" %d |", row + 1);
        for (int col = 0; col < 3; ++col)
        {
            printf(" %c |", board[row][col]);
        }
        printf("\n");
    }
    printf("   +---+---+---+\n\n");
}

// Перевірка на переможця
char checkWinner()
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return board[i][0];

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return board[0][i];
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return board[0][0];

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

// Перевірка на нічию
int checkDraw()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

// Хід гравця
void playerMove()
{
    int rowInput, colInput;
    while (1)
    {
        printf("Гравець %c, введiть рядок i стовпець (через пробiл): ", currentPlayer);
        if (scanf("%d %d", &rowInput, &colInput) != 2)
        {
            printf("Невiрний ввiд. Спробуйте ще раз.\n");
            while (getchar() != '\n');
            continue;
        }

        if (rowInput < 1 || rowInput > 3 || colInput < 1 || colInput > 3)
        {
            printf("Координати мають бути в межах вiд 1 до 3.\n");
            continue;
        }

        if (board[rowInput - 1][colInput - 1] != ' ')
        {
            printf("Клiтинка вже зайнята. Спробуйте iншу.\n");
            continue;
        }

        board[rowInput - 1][colInput - 1] = currentPlayer;
        break;
    }
}

// Зміна гравця
void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Головна функція
int main()
{
    setlocale(LC_ALL, "ukr");
    currentPlayer = 'X';
    initBoard();

    printf("Вiтаємо у грi \"Хрестики-нулики\"!\n");

    while (1)
    {
        printBoard();
        playerMove();

        char winner = checkWinner();
        if (winner != ' ')
        {
            printBoard();
            printf("Гравець %c виграв! Вiтаємо!\n", winner);
            break;
        }

        if (checkDraw())
        {
            printBoard();
            printf("Нiчия. Гарна гра!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}

