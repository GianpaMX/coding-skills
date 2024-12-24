import assertk.assertThat
import assertk.assertions.isEqualTo
import assertk.assertions.isFalse
import assertk.assertions.isTrue
import org.junit.jupiter.api.Test

class Sudoku {
    private class Board(vararg rowsArray: Array<Int?>) {
        private val board: Array<Array<Int?>> = Array(9) { Array(9) { null } }

        init {
            rowsArray.forEachIndexed { i, rows ->
                rows.forEachIndexed { j, square ->
                    board[i][j] = square?.takeIf { it > 0 }
                }
            }
        }

        override fun equals(other: Any?): Boolean {
            if (this === other) return true
            if (javaClass != other?.javaClass) return false

            other as Board

            other.board.forEachIndexed { i, row ->
                row.forEachIndexed { j, otherBoardSquare ->
                    if (this.board[i][j] != otherBoardSquare) return false
                }
            }

            return true
        }

        override fun hashCode(): Int = board
            .joinToString("") { row ->
                row.joinToString("") { square ->
                    square?.toString() ?: "0"
                }
            }
            .hashCode()

        override fun toString(): String {
            return board
                .joinToString(" | ") { row ->
                    row.joinToString(" ") { square ->
                        square?.toString() ?: "0"
                    }
                }
        }

        operator fun get(row: Int) = board[row]

        fun isValid(row: Int, column: Int, number: Int) =
            isRowValid(row, number) &&
                    isColumnValid(column, number) &&
                    isSubGridValid(row, column, number)

        private fun isColumnValid(column: Int, number: Int): Boolean {
            for (i in 0..<9) {
                if (board[i][column] == number) return false
            }
            return true
        }

        private fun isRowValid(row: Int, number: Int): Boolean {
            for (j in 0..<9) {
                if (board[row][j] == number) return false
            }
            return true
        }

        private fun isSubGridValid(row: Int, column: Int, number: Int): Boolean {
            val gridRow = row / 3 * 3
            val gridCol = column / 3 * 3

            for (i in gridRow..<gridRow + 3) {
                for (j in gridCol..<gridCol + 3) {
                    if (board[i][j] == number) return false
                }
            }
            return true
        }

        fun put(row: Int, column: Int, number: Int?): Board {
            val newBoard = Array(board.size) { i -> board[i].copyOf() }
            newBoard[row][column] = number?.takeIf { it > 0 }
            return Board(*newBoard)
        }

    }

    private fun solve(board: Board): Board? {
        fun solve(board: Board, i: Int, j: Int): Board? {
            if (i == 9) return board
            if (j == 9) return solve(board, i + 1, 0)
            if (board[i][j] != null) return solve(board, i, j + 1)

            for (number in 1..9) {
                if (board.isValid(i, j, number)) {
                    solve(board.put(i, j, number), i, j + 1)?.let {
                        return it
                    }
                }
            }

            return null
        }

        return solve(board, 0, 0)
    }

    @Test
    fun `Example 1`() {
        val board = Board(
            arrayOf(5, 3, 0, 0, 7, 0, 0, 0, 0),
            arrayOf(6, 0, 0, 1, 9, 5, 0, 0, 0),
            arrayOf(0, 9, 8, 0, 0, 0, 0, 6, 0),
            arrayOf(8, 0, 0, 0, 6, 0, 0, 0, 3),
            arrayOf(4, 0, 0, 8, 0, 3, 0, 0, 1),
            arrayOf(7, 0, 0, 0, 2, 0, 0, 0, 6),
            arrayOf(0, 6, 0, 0, 0, 0, 2, 8, 0),
            arrayOf(0, 0, 0, 4, 1, 9, 0, 0, 5),
            arrayOf(0, 0, 0, 0, 8, 0, 0, 7, 0),
        )

        val solution = solve(board)

        assertThat(solution).isEqualTo(
            Board(
                arrayOf(5, 3, 4, 6, 7, 8, 9, 1, 2),
                arrayOf(6, 7, 2, 1, 9, 5, 3, 4, 8),
                arrayOf(1, 9, 8, 3, 4, 2, 5, 6, 7),
                arrayOf(8, 5, 9, 7, 6, 1, 4, 2, 3),
                arrayOf(4, 2, 6, 8, 5, 3, 7, 9, 1),
                arrayOf(7, 1, 3, 9, 2, 4, 8, 5, 6),
                arrayOf(9, 6, 1, 5, 3, 7, 2, 8, 4),
                arrayOf(2, 8, 7, 4, 1, 9, 6, 3, 5),
                arrayOf(3, 4, 5, 2, 8, 6, 1, 7, 9),
            )
        )
    }

    @Test
    fun `Example 2`() {
        val board = Board(
            arrayOf(8, 1, 9, 2, 7, 3, 6, 5, 4),
            arrayOf(4, 2, 3, 6, 8, 5, 1, 9, 7),
            arrayOf(0, 7, 0, 0, 9, 0, 2, 0, 0),
            arrayOf(0, 5, 0, 0, 0, 7, 0, 0, 0),
            arrayOf(3, 8, 4, 9, 5, 6, 7, 2, 1),
            arrayOf(0, 0, 0, 1, 0, 0, 0, 3, 0),
            arrayOf(0, 0, 1, 0, 0, 0, 0, 6, 8),
            arrayOf(0, 0, 8, 5, 0, 0, 0, 1, 0),
            arrayOf(0, 9, 0, 0, 0, 0, 4, 0, 0),
        )

        val solution = solve(board)

        assertThat(solution).isEqualTo(
            Board(
                arrayOf(8, 1, 9, 2, 7, 3, 6, 5, 4),
                arrayOf(4, 2, 3, 6, 8, 5, 1, 9, 7),
                arrayOf(5, 7, 6, 4, 9, 1, 2, 8, 3),
                arrayOf(1, 5, 2, 8, 3, 7, 9, 4, 6),
                arrayOf(3, 8, 4, 9, 5, 6, 7, 2, 1),
                arrayOf(9, 6, 7, 1, 2, 4, 8, 3, 5),
                arrayOf(2, 3, 1, 7, 4, 9, 5, 6, 8),
                arrayOf(7, 4, 8, 5, 6, 2, 3, 1, 9),
                arrayOf(6, 9, 5, 3, 1, 8, 4, 7, 2),
            )
        )
    }

    @Test
    fun `valid number`() {
        val board = Board()

        val result = board.isValid(4, 3, 2)

        assertThat(result).isTrue()
    }

    @Test
    fun `invalid row`() {
        val board = Board().put(4, 0, 2)

        val result = board.isValid(4, 3, 2)

        assertThat(result).isFalse()
    }

    @Test
    fun `invalid column`() {
        val board = Board().put(8, 3, 2)

        val result = board.isValid(4, 3, 2)

        assertThat(result).isFalse()
    }

    @Test
    fun `invalid subgrid`() {
        val board = Board().put(3, 4, 2)

        val result = board.isValid(4, 3, 2)

        assertThat(result).isFalse()
    }
}
