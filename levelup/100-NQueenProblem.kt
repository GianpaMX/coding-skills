package io.github.gianpamx.sharedtab.tabs

import assertk.assertThat
import assertk.assertions.isEqualTo
import assertk.assertions.isFalse
import assertk.assertions.isTrue
import org.junit.jupiter.api.Test

class NQueenProblemTest {

    class NQueenProblem() {
        fun solve(boardSize: Int): Board? {
            fun solve(board: Board, row: Int): Board? {
                if (row == boardSize) return board

                for (queenColumn in 0..<boardSize) {
                    if (board.isQueenValidOn(row, queenColumn)) {
                        solve(board.put(row, queenColumn, 'Q'), row + 1)?.let { solution ->
                            return solution
                        }
                    }
                }

                return null
            }

            return solve(Board(boardSize), 0)
        }

        private fun Board.isQueenValidOn(row: Int, column: Int) =
            !columnContains(column, 'Q') &&
                    !ascendingDiagonalContains(row, column, 'Q') &&
                    !descendingDiagonalContains(row, column, 'Q')
    }

    @Test
    fun `Print N-Queen Problem`() {
        val nQueenProblem = NQueenProblem()

        val result = nQueenProblem.solve(4)

        assertThat(result).isEqualTo(
            Board(
                charArrayOf(' ', 'Q', ' ', ' '),
                charArrayOf(' ', ' ', ' ', 'Q'),
                charArrayOf('Q', ' ', ' ', ' '),
                charArrayOf(' ', ' ', 'Q', ' '),
            )
        )
    }

    @Test
    fun print() {
        val nQueenProblem = NQueenProblem()

        val result = nQueenProblem.solve(4)

        val s = result?.toPrettyString()

        println(s)
    }
}

class Board(val size: Int) {
    private val board = Array(size) { CharArray(size) { ' ' } }

    constructor(vararg rowsArray: CharArray) : this(rowsArray.size) {
        rowsArray.forEachIndexed { i, rows ->
            rows.forEachIndexed { j, square ->
                board[i][j] = square
            }
        }
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as Board

        if (other.board.size != this.board.size) return false

        other.board.forEachIndexed { i, row ->
            row.forEachIndexed { j, otherBoardSquare ->
                if (this.board[i][j] != otherBoardSquare) return false
            }
        }

        return true
    }

    override fun hashCode(): Int = board
        .map { row ->
            row
                .map { square -> square.code }
                .reduce { acc, j -> acc + 13 * j }
        }
        .reduce { acc, rowHashCode -> acc + rowHashCode }


    fun toPrettyString() = buildString {
        val lineSeparator = System.lineSeparator()

        board.forEachIndexed { i, row ->
            if (i == 0) {
                append("╔")
                repeat(row.size) { j ->
                    if (j > 0) append("╦")
                    append("═══")
                    if (j == row.size - 1) append("╗")
                }
                append(lineSeparator)
            }
            row.forEach { square ->
                append("║")
                append(' ')
                append(square)
                append(' ')
            }
            append("║")
            append(lineSeparator)
            if (i < row.size - 1) {
                append("╠")
                repeat(row.size) { j ->
                    if (j > 0) append("╬")
                    append("═══")
                    if (j == row.size - 1) append("╣")
                }
                append(lineSeparator)
            } else {
                append("╚")
                repeat(row.size) { j ->
                    if (j > 0) append("╩")
                    append("═══")
                    if (j == row.size - 1) append("╝")
                }
                append(lineSeparator)
            }
        }
    }

    override fun toString() = buildString {
        board.forEach { rows ->
            rows.forEach { square ->
                append(square)
            }
            append('|')
        }
    }

    fun put(row: Int, column: Int, c: Char): Board {
        val newBoard = Array(board.size) { i -> board[i].copyOf() }
        newBoard[row][column] = c
        return Board(*newBoard)
    }


    fun descendingDiagonalContains(row: Int, column: Int, c: Char): Boolean {
        var i = row
        var j = column
        while (i < size && j < size) {
            if (board[i][j] == c) return true
            i += 1
            j += 1
        }

        i = row - 1
        j = column - 1
        while (i >= 0 && j >= 0) {
            if (board[i][j] == c) return true
            i -= 1
            j -= 1
        }

        return false
    }

    fun ascendingDiagonalContains(row: Int, column: Int, c: Char): Boolean {
        var i = row
        var j = column
        while (i < size && j >= 0) {
            if (board[i][j] == c) return true
            i += 1
            j -= 1
        }

        i = row - 1
        j = column + 1
        while (i >= 0 && j < size) {
            if (board[i][j] == c) return true
            i -= 1
            j += 1
        }

        return false
    }

    fun rowContains(i: Int, c: Char): Boolean {
        for (j in 0..<size) {
            if (board[i][j] == c) return true
        }
        return false
    }

    fun columnContains(j: Int, c: Char): Boolean {
        for (i in 0..<size) {
            if (board[i][j] == c) return true
        }
        return false
    }
}

class BoardTest {
    @Test
    fun `row of a board of size 0 doesn't contains x`() {
        val board = Board(0)

        val result = board.rowContains(0, 'x')

        assertThat(result).isFalse()
    }

    @Test
    fun `row doesn't contain x`() {
        val board = Board(10)

        val result = board.rowContains(0, 'x')

        assertThat(result).isFalse()
    }

    @Test
    fun `row contains x`() {
        val board = Board(charArrayOf('x'))

        val result = board.rowContains(0, 'x')

        assertThat(result).isTrue()
    }

    @Test
    fun `column of a board of size 0 doesn't contains x`() {
        val board = Board(0)

        val result = board.columnContains(0, 'x')

        assertThat(result).isFalse()
    }

    @Test
    fun `column doesn't contain x`() {
        val board = Board(10)

        val result = board.columnContains(0, 'x')

        assertThat(result).isFalse()
    }

    @Test
    fun `column contains x`() {
        val board = Board(charArrayOf('x'))

        val result = board.columnContains(0, 'x')

        assertThat(result).isTrue()
    }

    @Test
    fun `descending diagonal of a board of size 0 doesn't contains x`() {
        val board = Board(0)

        val result = board.descendingDiagonalContains(0, 0, 'x')

        assertThat(result).isFalse()
    }

    @Test
    fun `descending diagonal contains x`() {
        val board = Board(
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf('*', ' ', ' ', ' ', ' '),
            charArrayOf(' ', 'x', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
        )

        val result = board.descendingDiagonalContains(2, 0, 'x')

        assertThat(result).isTrue()
    }

    @Test
    fun `descending diagonal contains x in the upper section`() {
        val board = Board(
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', 'x', ' ', ' ', ' '),
            charArrayOf(' ', ' ', '*', ' ', ' '),
        )

        val result = board.descendingDiagonalContains(4, 2, 'x')

        assertThat(result).isTrue()
    }

    @Test
    fun `ascending diagonal contains x`() {
        val board = Board(
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', 'x', ' ', ' ', ' '),
            charArrayOf('*', ' ', ' ', ' ', ' '),
        )

        val result = board.ascendingDiagonalContains(4, 0, 'x')

        assertThat(result).isTrue()
    }

    @Test
    fun `ascending diagonal contains x in the upper section`() {
        val board = Board(
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
            charArrayOf(' ', ' ', '*', ' ', ' '),
            charArrayOf(' ', 'x', ' ', ' ', ' '),
            charArrayOf(' ', ' ', ' ', ' ', ' '),
        )

        val result = board.ascendingDiagonalContains(2, 2, 'x')

        assertThat(result).isTrue()
    }
}
