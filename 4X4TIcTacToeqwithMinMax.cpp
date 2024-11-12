#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Constants for players and game settings
const char EMPTY = '-';   // Represents an empty cell
const char HUMAN = 'X';   // Represents the human player
const char AI = 'O';      // Represents the AI player
const int BOARD_SIZE = 4; // Size of the board (4x4)
const int MAX_DEPTH = 6;  // Maximum depth for recursion in minimax (limits recursion for performance)

// Function to create an empty 4x4 board
vector<vector<char>> createBoard()
{
    return vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));
}

// Function to print the current board state
void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)  // Loop through each row
    {
        for (char cell : row)  // Loop through each cell in the row
        {
            cout << cell << " ";  // Print cell content followed by a space
        }
        cout << endl;  // Newline at end of each row
    }
    cout << endl;  // Extra newline for spacing
}

// Function to check for a winner or tie
char checkWinner(const vector<vector<char>> &board)
{
    // Check rows and columns for a win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // Check row for human or AI win
        if (all_of(board[i].begin(), board[i].end(), [](char c){ return c == HUMAN; }))
            return HUMAN;
        if (all_of(board[i].begin(), board[i].end(), [](char c){ return c == AI; }))
            return AI;

        // Check column for human or AI win
        bool colHumanWin = true, colAIWin = true;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[j][i] != HUMAN)
                colHumanWin = false;
            if (board[j][i] != AI)
                colAIWin = false;
        }
        if (colHumanWin)
            return HUMAN;
        if (colAIWin)
            return AI;
    }

    // Check both diagonals for a win
    bool diag1HumanWin = true, diag1AIWin = true;
    bool diag2HumanWin = true, diag2AIWin = true;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // Primary diagonal (top-left to bottom-right)
        if (board[i][i] != HUMAN)
            diag1HumanWin = false;
        if (board[i][i] != AI)
            diag1AIWin = false;
        
        // Secondary diagonal (top-right to bottom-left)
        if (board[i][BOARD_SIZE - i - 1] != HUMAN)
            diag2HumanWin = false;
        if (board[i][BOARD_SIZE - i - 1] != AI)
            diag2AIWin = false;
    }
    if (diag1HumanWin || diag2HumanWin)
        return HUMAN;
    if (diag1AIWin || diag2AIWin)
        return AI;

    // Check for a tie (no empty cells)
    bool isTie = true;
    for (const auto &row : board)
    {
        if (any_of(row.begin(), row.end(), [](char c){ return c == EMPTY; }))
        {
            isTie = false;  // If there's an empty cell, it's not a tie
            break;
        }
    }

    return isTie ? 'T' : '\0'; // Return 'T' for Tie, '\0' for ongoing game
}

// Minimax algorithm with alpha-beta pruning
int minimax(vector<vector<char>> &board, int depth, bool isMaximizing, int alpha, int beta)
{
    char result = checkWinner(board);  // Check the current game status
    if (result == HUMAN) return -10 + depth;  // Human win score
    if (result == AI) return 10 - depth;      // AI win score
    if (result == 'T' || depth >= MAX_DEPTH) return 0;  // Tie or depth limit

    // Maximize score if AI's turn
    if (isMaximizing)
    {
        int maxEval = numeric_limits<int>::min();
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = AI;  // AI makes a move
                    int eval = minimax(board, depth + 1, false, alpha, beta);  // Recursively minimize opponent’s score
                    board[i][j] = EMPTY;  // Undo move (backtrack)
                    maxEval = max(maxEval, eval);  // Get the best score for AI
                    alpha = max(alpha, eval);  // Update alpha (best max score so far)
                    if (beta <= alpha) break;  // Beta cutoff
                }
            }
        }
        return maxEval;
    }
    // Minimize score if Human's turn
    else
    {
        int minEval = numeric_limits<int>::max();
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = HUMAN;  // Human makes a move
                    int eval = minimax(board, depth + 1, true, alpha, beta);  // Recursively maximize opponent’s score
                    board[i][j] = EMPTY;  // Undo move (backtrack)
                    minEval = min(minEval, eval);  // Get the best score for Human
                    beta = min(beta, eval);  // Update beta (best min score so far)
                    if (beta <= alpha) break;  // Alpha cutoff
                }
            }
        }
        return minEval;
    }
}

// Function to find the best move for AI by using minimax
pair<int, int> findBestMove(vector<vector<char>> &board)
{
    int bestVal = numeric_limits<int>::min();  // Initialize best score for AI
    pair<int, int> bestMove = {-1, -1};  // Initialize best move

    // Try each cell and evaluate using minimax
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = AI;  // AI makes a tentative move
                int moveVal = minimax(board, 0, false, numeric_limits<int>::min(), numeric_limits<int>::max());  // Evaluate move
                board[i][j] = EMPTY;  // Undo move

                // Update best move if the current move has a higher score
                if (moveVal > bestVal)
                {
                    bestVal = moveVal;
                    bestMove = {i, j};  // Store best move position
                }
            }
        }
    }
    return bestMove;
}

// Main game loop function
void playGame()
{
    vector<vector<char>> board = createBoard();  // Initialize the board
    cout << "4x4 Tic Tac Toe" << endl;
    printBoard(board);  // Display the initial board

    while (true)
    {
        // Human move input
        int row, col;
        cout << "Enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY)
        {
            cout << "Invalid move, try again." << endl;
            continue;
        }
        board[row][col] = HUMAN;  // Place human move
        printBoard(board);  // Display updated board

        // Check if human's move resulted in a win or tie
        char winner = checkWinner(board);
        if (winner != '\0')
        {
            if (winner == HUMAN) cout << "You win!" << endl;
            else if (winner == AI) cout << "AI wins!" << endl;
            else cout << "It's a tie!" << endl;
            break;
        }

        // AI makes a move
        cout << "AI's turn:" << endl;
        pair<int, int> aiMove = findBestMove(board);  // Find best move for AI

        // If no moves left, it’s a tie
        if (aiMove.first == -1 && aiMove.second == -1)
        {
            cout << "It's a tie!" << endl;
            break;
        }

        board[aiMove.first][aiMove.second] = AI;  // Place AI's move
        printBoard(board);  // Display updated board

        // Check if AI's move resulted in a win or tie
        winner = checkWinner(board);
        if (winner != '\0')
        {
            if (winner == HUMAN) cout << "You win!" << endl;
            else if (winner == AI) cout << "AI wins!" << endl;
            else cout << "It's a tie!" << endl;
            break;
        }
    }
}

// Entry point
int main()
{
    playGame();  // Start the game
    return 0;
}
