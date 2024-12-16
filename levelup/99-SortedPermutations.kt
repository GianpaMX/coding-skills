package io.github.gianpamx.sharedtab.tabs

import assertk.assertThat
import assertk.assertions.isEqualTo
import org.junit.jupiter.api.Test


class SortedPermutations {
    fun findSortedPermutations(input: String): List<String> {
        if (input.length == 1) return listOf(input)

        val result: MutableList<String> = mutableListOf()

        val n = input.length.dec()
        for (i in 0..n) {
            val currentChar = input[i]
            val remaining = input.take(i) + input.takeLast(n - i)
            result += findSortedPermutations(remaining).map {
                currentChar + it
            }
        }

        return result
    }

    @Test
    fun `Sorted Permutations`() {
        val result = findSortedPermutations("abc")

        assertThat(result.sorted()).isEqualTo(
            listOf(
                "abc",
                "acb",
                "bac",
                "bca",
                "cab",
                "cba"
            ).sorted()
        )
    }
}
