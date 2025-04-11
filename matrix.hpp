#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <vector>
#include <stdexcept> // For std::out_of_range, std::invalid_argument
#include <iostream>
#include <iomanip> // For std::setw, std::fixed, std::setprecision
#include <numeric> // For std::accumulate (optional, can use loop)
#include <algorithm> // For std::swap

template <typename T>
class Matrix {
private:
    std::size_t size_n; // Store N (size x size)
    std::vector<std::vector<T>> data;

    // Helper to check bounds
    void check_bounds(std::size_t r, std::size_t c) const {
        if (r >= size_n || c >= size_n) {
            throw std::out_of_range("Matrix index out of bounds");
        }
    }

public:
    // Constructor: Creates an N x N matrix initialized with default T (e.g., 0 for int/double)
    Matrix(std::size_t N) : size_n(N), data(N, std::vector<T>(N)) {
        if (N == 0) {
             throw std::invalid_argument("Matrix size must be positive.");
        }
    }

    // Constructor: Creates a matrix from existing 2D vector data
    Matrix(const std::vector<std::vector<T>>& initial_data) : data(initial_data) {
        if (initial_data.empty() || initial_data[0].empty()) {
            // Handle empty input if necessary, or assume valid input based on context
             throw std::invalid_argument("Initial data cannot be empty.");
        }
        size_n = initial_data.size();
        // Validate if it's a square matrix
        for (const auto& row : data) {
            if (row.size() != size_n) {
                throw std::invalid_argument("Input data must form a square matrix.");
            }
        }
    }

    // Get the size (N) of the matrix
    std::size_t get_size() const {
        return size_n;
    }

    // Set value at (i, j)
    void set_value(std::size_t i, std::size_t j, T value) {
        check_bounds(i, j);
        data[i][j] = value;
    }

    // Get value at (i, j)
    T get_value(std::size_t i, std::size_t j) const {
        check_bounds(i, j);
        return data[i][j];
    }

    // Overload operator+ for matrix addition
    Matrix operator+(const Matrix& rhs) const {
        if (size_n != rhs.size_n) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }
        Matrix result(size_n);
        for (std::size_t i = 0; i < size_n; ++i) {
            for (std::size_t j = 0; j < size_n; ++j) {
                result.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    // Overload operator* for matrix multiplication
    Matrix operator*(const Matrix& rhs) const {
        if (size_n != rhs.size_n) {
            throw std::invalid_argument("Matrices must have the same dimensions for multiplication.");
        }
        Matrix result(size_n); // Initialize with zeros
        for (std::size_t i = 0; i < size_n; ++i) {
            for (std::size_t j = 0; j < size_n; ++j) {
                T sum = 0; // Use T for the sum type
                for (std::size_t k = 0; k < size_n; ++k) {
                    sum += data[i][k] * rhs.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    // Calculate sum of main diagonal elements
    T sum_diagonal_major() const {
        T sum = 0;
        for (std::size_t i = 0; i < size_n; ++i) {
            sum += data[i][i];
        }
        return sum;
    }

    // Calculate sum of secondary diagonal elements
    T sum_diagonal_minor() const {
        T sum = 0;
        for (std::size_t i = 0; i < size_n; ++i) {
            sum += data[i][size_n - 1 - i];
        }
        return sum;
    }

    // Swap two rows
    void swap_rows(std::size_t r1, std::size_t r2) {
        if (r1 >= size_n || r2 >= size_n) {
            throw std::out_of_range("Row index out of bounds for swapping.");
        }
        if (r1 != r2) {
            std::swap(data[r1], data[r2]);
        }
    }

    // Swap two columns
    void swap_cols(std::size_t c1, std::size_t c2) {
        if (c1 >= size_n || c2 >= size_n) {
            throw std::out_of_range("Column index out of bounds for swapping.");
        }
        if (c1 != c2) {
            for (std::size_t i = 0; i < size_n; ++i) {
                std::swap(data[i][c1], data[i][c2]);
            }
        }
    }

    // Friend function to overload operator<< for printing
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        // Determine max width for alignment (optional, but good for clean output)
        int max_width = 0;
        for (std::size_t i = 0; i < matrix.size_n; ++i) {
            for (std::size_t j = 0; j < matrix.size_n; ++j) {
                std::ostringstream oss;
                 // Print as double for consistent formatting if needed, or use T
                oss << std::fixed << std::setprecision(2) << static_cast<double>(matrix.data[i][j]);
                if (oss.str().length() > max_width) {
                    max_width = oss.str().length();
                }
            }
        }
        // Add a little padding
        max_width += 2;

        os << std::fixed << std::setprecision(2); // Set precision for floating point types
        for (std::size_t i = 0; i < matrix.size_n; ++i) {
            for (std::size_t j = 0; j < matrix.size_n; ++j) {
                 // Print as double as requested for simplicity
                os << std::setw(max_width) << static_cast<double>(matrix.data[i][j]);
            }
            os << std::endl;
        }
        return os;
    }

    // Friend function to overload operator>> for reading from stream
    friend std::istream& operator>>(std::istream& is, Matrix<T>& matrix) {
         for (std::size_t i = 0; i < matrix.size_n; ++i) {
            for (std::size_t j = 0; j < matrix.size_n; ++j) {
                T value;
                if (!(is >> value)) {
                    // Set failbit and potentially throw or let caller check stream state
                    is.setstate(std::ios::failbit);
                     throw std::runtime_error("Error reading matrix data from stream. Insufficient data or invalid format.");
                }
                // Use set_value to implicitly check bounds if needed, though direct access is fine here
                // matrix.set_value(i, j, value);
                 matrix.data[i][j] = value; // Direct access okay after constructor ensures size
            }
        }
        return is;
    }
};

#endif // __MATRIX_HPP__
