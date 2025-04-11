#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits> // Required for numeric_limits

#include "matrix.hpp"

// Generic function to perform and display all operations
template <typename T>
void process_matrices(Matrix<T>& matrix1, Matrix<T>& matrix2, const std::string& type_name) {
    std::size_t N = matrix1.get_size();

    std::cout << "\n--- Processing " << type_name << " Matrices (N=" << N << ") ---\n";

    // 1. Display original matrices
    std::cout << "\nMatrix 1 (" << type_name << "):\n" << matrix1;
    std::cout << "\nMatrix 2 (" << type_name << "):\n" << matrix2;

    try {
        // 2. Add matrices
        Matrix<T> sum = matrix1 + matrix2;
        std::cout << "\nMatrix Sum (" << type_name << "):\n" << sum;

        // 3. Multiply matrices
        Matrix<T> product = matrix1 * matrix2;
        std::cout << "\nMatrix Product (" << type_name << "):\n" << product;

        // 4. Diagonal sums (demonstrating on Matrix 1)
        T major_diag_sum = matrix1.sum_diagonal_major();
        T minor_diag_sum = matrix1.sum_diagonal_minor();
        std::cout << "\nMatrix 1 Diagonal Sums (" << type_name << "):"
                  << " Major = " << major_diag_sum
                  << ", Minor = " << minor_diag_sum << std::endl;

        // 5. Swap rows (demonstrating on Matrix 1)
        if (N > 1) {
            Matrix<T> matrix1_row_swap = matrix1; // Create a copy
            std::size_t row1 = 0, row2 = N - 1;
             std::cout << "\nSwapping rows " << row1 << " and " << row2 << " in Matrix 1..." << std::endl;
            matrix1_row_swap.swap_rows(row1, row2);
            std::cout << "Matrix 1 after Row Swap (" << type_name << "):\n" << matrix1_row_swap;
        } else {
            std::cout << "\nSkipping row swap for N=1 matrix." << std::endl;
        }


        // 6. Swap columns (demonstrating on Matrix 1)
         if (N > 1) {
            Matrix<T> matrix1_col_swap = matrix1; // Create a copy
            std::size_t col1 = 0, col2 = N - 1;
             std::cout << "\nSwapping columns " << col1 << " and " << col2 << " in Matrix 1..." << std::endl;
            matrix1_col_swap.swap_cols(col1, col2);
            std::cout << "Matrix 1 after Column Swap (" << type_name << "):\n" << matrix1_col_swap;
        } else {
             std::cout << "\nSkipping column swap for N=1 matrix." << std::endl;
        }

        // 7. Update element (demonstrating on Matrix 1)
        Matrix<T> matrix1_update = matrix1; // Create a copy
        std::size_t update_row = 0, update_col = 0;
        T new_value;
        // Assign a noticeable value based on type
        if constexpr (std::is_same_v<T, int>) {
            new_value = 999;
        } else if constexpr (std::is_same_v<T, double>) {
            new_value = 999.99;
        } else {
            new_value = T{}; // Default value otherwise
        }
         std::cout << "\nUpdating element at (" << update_row << ", " << update_col << ") in Matrix 1 to " << new_value << "..." << std::endl;
        matrix1_update.set_value(update_row, update_col, new_value);
        std::cout << "Matrix 1 after Update (" << type_name << "):\n" << matrix1_update;

    } catch (const std::exception& e) {
        std::cerr << "\n*** An error occurred during processing: " << e.what() << " ***" << std::endl;
    }
     std::cout << "\n--- End Processing " << type_name << " Matrices ---\n";
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error: Cannot open file \"" << filename << "\"" << std::endl;
        return 1;
    }

    std::size_t N;
    int type_flag;

    // Read N and type_flag from the first line
    if (!(inputFile >> N >> type_flag)) {
        std::cerr << "Error: Could not read matrix size (N) and type flag from file." << std::endl;
         if (inputFile.eof()) {
             std::cerr << " File might be empty or incorrectly formatted at the beginning." << std::endl;
         }
        return 1;
    }

     // Input validation
    if (N == 0) {
         std::cerr << "Error: Matrix size N must be a positive integer." << std::endl;
         return 1;
    }
     if (type_flag != 0 && type_flag != 1) {
        std::cerr << "Error: Invalid type flag " << type_flag << ". Must be 0 (for int) or 1 (for double)." << std::endl;
        return 1;
    }

    std::cout << "Matrix size N = " << N << std::endl;
    std::cout << "Type flag = " << type_flag << (type_flag == 0 ? " (int)" : " (double)") << std::endl;

    try {
        if (type_flag == 0) { // Integer matrices
            Matrix<int> matrix1(N);
            Matrix<int> matrix2(N);

            std::cout << "Reading integer matrices from file..." << std::endl;
            inputFile >> matrix1; // Read first matrix
             if (!inputFile) { throw std::runtime_error("Failed to read the first integer matrix completely."); }
            inputFile >> matrix2; // Read second matrix
             if (!inputFile) { throw std::runtime_error("Failed to read the second integer matrix completely."); }

            process_matrices(matrix1, matrix2, "int");

        } else { // Double matrices
            Matrix<double> matrix1(N);
            Matrix<double> matrix2(N);

            std::cout << "Reading double matrices from file..." << std::endl;
            inputFile >> matrix1; // Read first matrix
            if (!inputFile) { throw std::runtime_error("Failed to read the first double matrix completely."); }
            inputFile >> matrix2; // Read second matrix
            if (!inputFile) { throw std::runtime_error("Failed to read the second double matrix completely."); }

            process_matrices(matrix1, matrix2, "double");
        }
    } catch (const std::exception& e) {
        std::cerr << "\n*** An error occurred: " << e.what() << " ***" << std::endl;
        inputFile.close();
        return 1;
    }

    inputFile.close();
    return 0;
}
