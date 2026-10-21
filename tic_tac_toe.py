
def display(board):
    for i in range(0, 9, 3):
        print(" | ".join(board[i:i + 3]))
        if i < 6:
            print("--+---+--")


def check_winner(board, player):
    winning_lines = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6)
    ]

    for line in winning_lines:
        if all(board[i] == player for i in line):
            return True
    return False


def main():
    board = list("123456789")
    player = "X"

    while True:
        display(board)
        move = input(f"Player {player}, choose position (1-9): ")

        if not move.isdigit() or not 1 <= int(move) <= 9:
            print("Enter a number from 1 to 9.")
            continue

        index = int(move) - 1

        if board[index] in ("X", "O"):
            print("Position already occupied!")
            continue

        board[index] = player

        if check_winner(board, player):
            display(board)
            print(f"Player {player} wins!")
            break

        if all(cell in ("X", "O") for cell in board):
            display(board)
            print("It's a draw!")
            break

        player = "O" if player == "X" else "X"


if __name__ == "__main__":
    main()
