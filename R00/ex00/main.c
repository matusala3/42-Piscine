#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

int calculate_visibility(int arr[], int size, const char* direction) {
    int max_h = 0, count = 0;

    if (strcmp(direction, "right") == 0 || strcmp(direction, "bottom") == 0) {
        for (int i = size - 1; i >= 0; i--) {
            if (arr[i] > max_h) {
                max_h = arr[i];
                count++;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (arr[i] > max_h) {
                max_h = arr[i];
                count++;
            }
        }
    }

    return count;
}

void generate_permutations(int* perm, int* used, int n, int depth, int perms[][SIZE], int* perm_count) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            perms[*perm_count][i] = perm[i];
        }
        (*perm_count)++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = 1;
            perm[depth] = i;
            generate_permutations(perm, used, n, depth + 1, perms, perm_count);
            used[i] = 0;
        }
    }
}

bool is_valid(int grid[SIZE][SIZE], int constraints[], int row) {
    // Check rows for left and right visibility constraints
    for (int r = 0; r <= row; r++) {
        int left_vis = calculate_visibility(grid[r], SIZE, "left");
        int right_vis = calculate_visibility(grid[r], SIZE, "right");

        if (left_vis != constraints[8 + r] || right_vis != constraints[12 + r]) {
            return false;
        }
    }

    // Check columns for uniqueness and visibility constraints
    for (int col = 0; col < SIZE; col++) {
        int column[SIZE];
        bool used[SIZE + 1] = {false};

        for (int r = 0; r <= row; r++) {
            column[r] = grid[r][col];
            if (used[column[r]]) {
                return false;
            }
            used[column[r]] = true;
        }

        if (row == SIZE - 1) { // Final column check
            int top_vis = calculate_visibility(column, SIZE, "top");
            int bottom_vis = calculate_visibility(column, SIZE, "bottom");
            if (top_vis != constraints[col] || bottom_vis != constraints[4 + col]) {
                return false;
            }
        }
    }

    return true;
}

bool solve_puzzle(int grid[SIZE][SIZE], int constraints[], int row) {
    if (row == SIZE) {
        return true; // Puzzle solved
    }

    int perms[24][SIZE] = {0};
    int perm[SIZE] = {0};
    int used[SIZE + 1] = {0};
    int perm_count = 0;
    generate_permutations(perm, used, SIZE, 0, perms, &perm_count);

    for (int p = 0; p < perm_count; p++) {
        for (int i = 0; i < SIZE; i++) {
            grid[row][i] = perms[p][i];
        }

        if (is_valid(grid, constraints, row)) {
            if (solve_puzzle(grid, constraints, row + 1)) {
                return true;
            }
        }
    }

    return false;
}

void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int test_cases[][16] = {
        {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2},
        {4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1},
        {2, 1, 4, 2, 2, 4, 1, 2, 2, 1, 4, 2, 2, 4, 1, 2}
    };

    for (int t = 0; t < 3; t++) {
        int grid[SIZE][SIZE] = {0};

        printf("Test Case %d:\n", t + 1);
        if (solve_puzzle(grid, test_cases[t], 0)) {
            print_grid(grid);
        } else {
            printf("No solution exists.\n");
        }
        printf("\n");
    }

    return 0;
}
