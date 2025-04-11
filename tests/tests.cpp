#include <gtest/gtest.h>
#include <vector>
#include <stdexcept> // Include for std::out_of_range

#include "matrix.hpp" // Include the header with the template class

// --- Tests for Integer Matrices ---

TEST(MatrixImplementationInt, GetSize_3) {
    Matrix<int> matrix({ // Use Matrix<int>
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });
    EXPECT_EQ(matrix.get_size(), 3);
}

TEST(MatrixImplementationInt, GetSize_4) {
    Matrix<int> matrix({ // Use Matrix<int>
        { 25, 35, 45, 28 },
        { 15, 45, 45, 34 },
        { 80, 80, 80, 11 },
        { 4,   8,  9, 11 },
    });
    EXPECT_EQ(matrix.get_size(), 4);
}

TEST(MatrixImplementationInt, GetValue_Basic) {
    std::vector<std::vector<int>> expected = {
        { 0, 1, 2 },
        { 3, 4, 5 },
        { 6, 7, 8 },
    };
    Matrix<int> matrix(expected); // Use Matrix<int>

    // Fix loop bounds in original test
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, GetValue_Random) {
    std::vector<std::vector<int>> expected = {
        { 25, 35, 45, 28 },
        { 15, 45, 45, 34 },
        { 80, 80, 80, 11 },
        { 4,   8,  9, 11 },
    };
    Matrix<int> matrix(expected); // Use Matrix<int>

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
         for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, SetValue_Basic) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 },
    };
    std::vector<std::vector<int>> expected = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };
    Matrix<int> matrix(initial); // Use Matrix<int>

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            matrix.set_value(i, j, expected[i][j]);
        }
    }
    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, SetValue_Random) {
     std::vector<std::vector<int>> initial = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };
    std::vector<std::vector<int>> expected = {
        { 15, 22, 33, 44},
        { 55, 22, 33, 44},
        { 45, 22, 33, 11},
        { 15, 22, 37, 44},
    };
    Matrix<int> matrix(initial); // Use Matrix<int>

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
             matrix.set_value(i, j, expected[i][j]);
        }
    }
    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}


TEST(MatrixImplementationInt, Addition_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };
    Matrix<int> matrix1(initial); // Use Matrix<int>
    Matrix<int> matrix2(initial); // Use Matrix<int>
    auto result = matrix1 + matrix2;

    // Fix loop bounds
    for (size_t i = 0; i < initial.size(); ++i) {
        for (size_t j = 0; j < initial[i].size(); ++j) { // Use j < initial[i].size()
            EXPECT_EQ(result.get_value(i, j), 2);
        }
    }
}

TEST(MatrixImplementationInt, Addition_Random) {
    std::vector<std::vector<int>> initial1 = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 6, 3, 7 },
        { 8, 6, 6 },
        { 3, 3, 5 },
    };
    std::vector<std::vector<int>> expected = {
        { 6,  3,  15 },
        { 14, 13, 14 },
        { 7,  4,  11 },
    };
    Matrix<int> matrix1(initial1); // Use Matrix<int>
    Matrix<int> matrix2(initial2); // Use Matrix<int>
    auto result = matrix1 + matrix2;

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}


TEST(MatrixImplementationInt, Multiplication_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };
    Matrix<int> matrix1(initial); // Use Matrix<int>
    Matrix<int> matrix2(initial); // Use Matrix<int>
    auto result = matrix1 * matrix2;

    // Fix loop bounds
    for (size_t i = 0; i < initial.size(); ++i) {
        for (size_t j = 0; j < initial[i].size(); ++j) { // Use j < initial[i].size()
            EXPECT_EQ(result.get_value(i, j), 3);
        }
    }
}

TEST(MatrixImplementationInt, Multiplication_Random) {
    std::vector<std::vector<int>> initial1 = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 6, 3, 7 },
        { 8, 6, 6 },
        { 3, 3, 5 },
    };
    std::vector<std::vector<int>> expected = {
        { 24,  24, 40  },
        { 116, 84, 124 },
        { 50,  36, 64  },
    };
    Matrix<int> matrix1(initial1); // Use Matrix<int>
    Matrix<int> matrix2(initial2); // Use Matrix<int>
    auto result = matrix1 * matrix2;

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, DiagonalSumMajor) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    Matrix<int> matrix(initial); // Use Matrix<int>
    EXPECT_EQ(matrix.sum_diagonal_major(), 13); // 0 + 7 + 6
}

TEST(MatrixImplementationInt, DiagonalSumMinor) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    Matrix<int> matrix(initial); // Use Matrix<int>
    EXPECT_EQ(matrix.sum_diagonal_minor(), 19); // 8 + 7 + 4
}

TEST(MatrixImplementationInt, SwapRows_Basic) {
     std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 2, 2, 2 },
        { 3, 3, 3 },
    };
    std::vector<std::vector<int>> expected = {
        { 2, 2, 2 },
        { 1, 1, 1 },
        { 3, 3, 3 },
    };
    Matrix<int> matrix(initial); // Use Matrix<int>
    matrix.swap_rows(0, 1);

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, SwapRows_Random) {
    std::vector<std::vector<int>> initial = {
        { 3, 1, 4, 1 },
        { 5, 9, 2, 6 },
        { 5, 3, 5, 8 },
        { 9, 7, 9, 3 }
    };
    std::vector<std::vector<int>> expected = {
        { 5, 3, 5, 8 }, // Row 2 moved to 0
        { 5, 9, 2, 6 }, // Row 1 stays
        { 3, 1, 4, 1 }, // Row 0 moved to 2
        { 9, 7, 9, 3 }  // Row 3 stays
    };
    Matrix<int> matrix(initial); // Use Matrix<int>
    matrix.swap_rows(0, 2);

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, SwapCols_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 1, 2, 3 },
        { 1, 2, 3 },
    };
    std::vector<std::vector<int>> expected = {
        { 3, 2, 1 },
        { 3, 2, 1 },
        { 3, 2, 1 },
    };
    Matrix<int> matrix(initial); // Use Matrix<int>
    matrix.swap_cols(0, 2);

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}


TEST(MatrixImplementationInt, SwapCols_Random) {
    std::vector<std::vector<int>> initial = {
        { 3, 1, 4, 1 },
        { 5, 9, 2, 6 },
        { 5, 3, 5, 8 },
        { 9, 7, 9, 3 }
    };
    std::vector<std::vector<int>> expected = {
        { 1, 1, 4, 3 }, // Col 3 swapped with 0
        { 6, 9, 2, 5 },
        { 8, 3, 5, 5 },
        { 3, 7, 9, 9 }
    };
    Matrix<int> matrix(initial); // Use Matrix<int>
    matrix.swap_cols(0, 3);

    // Fix loop bounds
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) { // Use j < expected[i].size()
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementationInt, OutOfBoundsThrowsException_GetValue) {
    Matrix<int> matrix({ // Use Matrix<int>
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });
    EXPECT_THROW(matrix.get_value(3, 0), std::out_of_range); // Row out of bounds
    EXPECT_THROW(matrix.get_value(0, 3), std::out_of_range); // Col out of bounds
    EXPECT_THROW(matrix.get_value(4, 4), std::out_of_range); // Both out of bounds
}

TEST(MatrixImplementationInt, OutOfBoundsThrowsException_SetValue) {
    Matrix<int> matrix({ // Use Matrix<int>
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });
    EXPECT_THROW(matrix.set_value(3, 0, 100), std::out_of_range); // Row out of bounds
    EXPECT_THROW(matrix.set_value(0, 3, 100), std::out_of_range); // Col out of bounds
    EXPECT_THROW(matrix.set_value(4, 4, 100), std::out_of_range); // Both out of bounds
}

TEST(MatrixImplementationInt, OutOfBoundsThrowsException_SwapRows) {
    Matrix<int> matrix({ {1,2}, {3,4} }); // Use Matrix<int>
    EXPECT_THROW(matrix.swap_rows(0, 2), std::out_of_range);
    EXPECT_THROW(matrix.swap_rows(2, 0), std::out_of_range);
    EXPECT_NO_THROW(matrix.swap_rows(0, 1)); // Valid swap
}

TEST(MatrixImplementationInt, OutOfBoundsThrowsException_SwapCols) {
    Matrix<int> matrix({ {1,2}, {3,4} }); // Use Matrix<int>
    EXPECT_THROW(matrix.swap_cols(0, 2), std::out_of_range);
    EXPECT_THROW(matrix.swap_cols(2, 0), std::out_of_range);
    EXPECT_NO_THROW(matrix.swap_cols(0, 1)); // Valid swap
}


// --- Add Tests for Double Matrices (similar structure) ---

TEST(MatrixImplementationDouble, GetSize_2) {
    Matrix<double> matrix({ // Use Matrix<double>
        { 1.1, 2.2 },
        { 3.3, 4.4 }
    });
    EXPECT_EQ(matrix.get_size(), 2);
}

TEST(MatrixImplementationDouble, Addition) {
    Matrix<double> matrix1({ {1.0, 2.0}, {3.0, 4.0} }); // Use Matrix<double>
    Matrix<double> matrix2({ {0.1, 0.2}, {0.3, 0.4} }); // Use Matrix<double>
    Matrix<double> expected({ {1.1, 2.2}, {3.3, 4.4} });
    auto result = matrix1 + matrix2;
    EXPECT_NEAR(result.get_value(0, 0), expected.get_value(0, 0), 1e-9);
    EXPECT_NEAR(result.get_value(0, 1), expected.get_value(0, 1), 1e-9);
    EXPECT_NEAR(result.get_value(1, 0), expected.get_value(1, 0), 1e-9);
    EXPECT_NEAR(result.get_value(1, 1), expected.get_value(1, 1), 1e-9);
}

TEST(MatrixImplementationDouble, Multiplication) {
    Matrix<double> matrix1({ {1.0, 2.0}, {3.0, 0.0} }); // Use Matrix<double>
    Matrix<double> matrix2({ {1.0, 0.5}, {2.0, 1.0} }); // Use Matrix<double>
    // Expected:
    // [ (1*1 + 2*2)  (1*0.5 + 2*1) ] = [ 5.0  2.5 ]
    // [ (3*1 + 0*2)  (3*0.5 + 0*1) ] = [ 3.0  1.5 ]
    Matrix<double> expected({ {5.0, 2.5}, {3.0, 1.5} });
    auto result = matrix1 * matrix2;
    EXPECT_NEAR(result.get_value(0, 0), expected.get_value(0, 0), 1e-9);
    EXPECT_NEAR(result.get_value(0, 1), expected.get_value(0, 1), 1e-9);
    EXPECT_NEAR(result.get_value(1, 0), expected.get_value(1, 0), 1e-9);
    EXPECT_NEAR(result.get_value(1, 1), expected.get_value(1, 1), 1e-9);
}


TEST(MatrixImplementationDouble, DiagonalSum) {
    Matrix<double> matrix({ // Use Matrix<double>
        { 1.1, 2.2, 3.3 },
        { 4.4, 5.5, 6.6 },
        { 7.7, 8.8, 9.9 }
    });
    EXPECT_NEAR(matrix.sum_diagonal_major(), 1.1 + 5.5 + 9.9, 1e-9); // 16.5
    EXPECT_NEAR(matrix.sum_diagonal_minor(), 3.3 + 5.5 + 7.7, 1e-9); // 16.5
}

TEST(MatrixImplementationDouble, SwapRows) {
     Matrix<double> matrix({ {1.1, 2.2}, {3.3, 4.4} }); // Use Matrix<double>
     Matrix<double> expected({ {3.3, 4.4}, {1.1, 2.2} });
     matrix.swap_rows(0, 1);
     EXPECT_NEAR(matrix.get_value(0,0), expected.get_value(0,0), 1e-9);
     EXPECT_NEAR(matrix.get_value(0,1), expected.get_value(0,1), 1e-9);
     EXPECT_NEAR(matrix.get_value(1,0), expected.get_value(1,0), 1e-9);
     EXPECT_NEAR(matrix.get_value(1,1), expected.get_value(1,1), 1e-9);
}

TEST(MatrixImplementationDouble, SwapCols) {
     Matrix<double> matrix({ {1.1, 2.2}, {3.3, 4.4} }); // Use Matrix<double>
     Matrix<double> expected({ {2.2, 1.1}, {4.4, 3.3} });
     matrix.swap_cols(0, 1);
     EXPECT_NEAR(matrix.get_value(0,0), expected.get_value(0,0), 1e-9);
     EXPECT_NEAR(matrix.get_value(0,1), expected.get_value(0,1), 1e-9);
     EXPECT_NEAR(matrix.get_value(1,0), expected.get_value(1,0), 1e-9);
     EXPECT_NEAR(matrix.get_value(1,1), expected.get_value(1,1), 1e-9);
}

TEST(MatrixImplementationDouble, SetValue) {
     Matrix<double> matrix({ {1.1, 2.2}, {3.3, 4.4} }); // Use Matrix<double>
     matrix.set_value(1, 1, 9.99);
     EXPECT_NEAR(matrix.get_value(1,1), 9.99, 1e-9);
     // Check others didn't change
     EXPECT_NEAR(matrix.get_value(0,0), 1.1, 1e-9);
     EXPECT_NEAR(matrix.get_value(0,1), 2.2, 1e-9);
     EXPECT_NEAR(matrix.get_value(1,0), 3.3, 1e-9);
}

TEST(MatrixImplementationConstructor, InvalidSize) {
     EXPECT_THROW(Matrix<int> matrix(0), std::invalid_argument);
     EXPECT_THROW(Matrix<double> matrix(0), std::invalid_argument);
}

TEST(MatrixImplementationConstructor, NonSquareData) {
    std::vector<std::vector<int>> non_square = { {1, 2}, {3} };
    EXPECT_THROW(Matrix<int> matrix(non_square), std::invalid_argument);
}

TEST(MatrixImplementationOperations, MismatchedDimensions) {
    Matrix<int> matrix3x3(3);
    Matrix<int> matrix2x2(2);
    EXPECT_THROW(matrix3x3 + matrix2x2, std::invalid_argument);
    EXPECT_THROW(matrix3x3 * matrix2x2, std::invalid_argument);
}
