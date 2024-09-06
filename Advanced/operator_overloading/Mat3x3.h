/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 3 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Due Date: July 7th, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * **************************************************************************
 * Class Description: Mat3x3 class header file containing the class definition
 * and the declaration of all member functions and operators. The class is
 * responsible for handling 3x3 matrices and performing operations on them.
 * This class's purpose is to provide practice on operator overloading.
 * 
 * ***************************************************************************
 */

#pragma once

#include <iostream>
#include <array>
using std::cout;
using std::cin;
using std::endl;

class Mat3x3
{
public:
	std::array<std::array<double, 3>, 3> theMatrix; // 3x3 matrix instance variable

	static constexpr double NEAR_ZERO = 1.0e-6; // tolerance value

	/* CONSTRUCTORS */
	/* Default constructor
	 * Initializes the matrix all entries to 0
	 */
	Mat3x3();

	/* Custom constructor
	 * Initializes the matrix to the values passed as parameter
	 */
	Mat3x3(std::array<double, 9> val);

	/* SPECIAL MEMBER FUNCTIONS */
	/* Copy constructor
	 * Initializes the matrix to the values of the matrix passed as parameter
	 */
	Mat3x3(const Mat3x3& m);

	/* Move constructor
	 * Initializes the matrix to the values of the matrix passed as parameter
	 */
	Mat3x3(Mat3x3&& m) noexcept;

	/* Copy assignment operator
	 * Assigns the values of the matrix passed as parameter to the current matrix
	 */
	Mat3x3& operator=(const Mat3x3& m);

	/* Move assignment operator
	 * Assigns the values of the matrix passed as parameter to the current matrix
	 */
	Mat3x3& operator=(Mat3x3&& m) noexcept;

	/* Destructor
	 * Default destructor
	 */
	~Mat3x3();

	/* MEMBER FUNCTIONS */
	/* read()
	 * Reads the matrix from the input stream
	 */
	void read(std::istream& sin);

	/* write()
	 * Writes the matrix to the output stream
	 */
	void write(std::ostream& os) const;

	/* determinant()
	 * Returns the determinant of the matrix
	 */
	double determinant() const;

	/* trace()
	 * Returns the trace of the matrix, which is the sum of the diagonal elements
	 */
	double trace() const;

	/* norm()
	 * Returns the norm of the matrix, as the square root of the sum of the squares of all elements
	 */
	double norm() const;

	/* conditionNumber() 
	 * Returns the condition number of the matrix, which is the ratio of the norm of the matrix to the norm of its inverse
	 */
	double conditionNumber() const;

	/* isAntiSymmetric()
	 * Returns true if the matrix is antisymmetric, false otherwise. An antisymmetric
	 * matrix is a square matrix that satisfies A = -A^T
	 */
	bool isAntiSymmetric() const;

	/* isOrthogonal()
	 * Returns true if AA^T = I, false otherwise. That is, the matrix is orthogonal
	 * if its transpose is equal to the identity matrix
	 */
	bool isOrthogonal() const;

	/* isInvertible()
	 * Returns true if the matrix is invertible, false otherwise
	 */
	bool isInvertible() const;

	/* isSymmetric()
	 * Returns true if the matrix is symmetric, false otherwise. A symmetric matrix
	 * is a square matrix that satisfies A = A^T
	 */
	bool isSymmetric() const;

	/* transpose()
	 * Returns the transpose of the matrix. The transpose of a matrix is the matrix
	 * obtained by exchanging the rows and columns of the original matrix
	 */
	Mat3x3 transpose() const;

	/* inverse()
	 * Returns the inverse of the matrix
	 * throws std::overflow_error("Inverse undefined") if the matrix is not invertible
	 * The inverse of a matrix is a matrix that, when multiplied with the original matrix,
	 * gives the identity matrix.
	 */
	Mat3x3 inverse() const;

	/* COMPOUND ASSIGNMENT OPERATORS */
	/* Compound assignment operator+=
	 * Adds the matrix passed as parameter to the current matrix
	 * @param m: matrix to be added
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator+=(const Mat3x3& m);

	/* Compound assignment operator-=
	 * Subtracts the matrix passed as parameter to the current matrix
	 * @param m: matrix to be subtracted
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator-=(const Mat3x3& m);

	/* Compound assignment operator*=
	 * Multiplies the current matrix by the matrix passed as parameter
	 * @param m: matrix to be multiplied
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator*=(const Mat3x3& m);

	/* Compound assignment operator/=
	 * Divides the current matrix by the matrix passed as parameter
	 * Throws std::overflow_error("Division by zero") if the matrix is not invertible
	 * @param m: matrix to be divided
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator/=(const Mat3x3& m);

	/* Compound assignment operator+=
	 * Adds the scalar passed as parameter to the current matrix
	 * @param scalar: scalar to be added
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator+=(double scalar);

	/* Compound assignment operator-=
	 * Subtracts the scalar passed as parameter to the current matrix
	 * @param scalar: scalar to be subtracted
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator-=(double scalar);

	/* Compound assignment operator*=
	 * Multiplies the current matrix by the scalar passed as parameter
	 * @param scalar: scalar to be multiplied
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator*=(double scalar);

	/* Compound assignment operator/=
	 * Divides the current matrix by the scalar passed as parameter
	 * Throws std::overflow_error("Division by zero") if the scalar is 0
	 * @param scalar: scalar to be divided
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator/=(double scalar);

	/* PRE/POST INCREMENT/DECREMENT OPERATORS */
	/* Pre-increment operator++
	 * Increments all the values of the matrix by 1
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator++();

	/* Post-increment operator++
	 * Increments all the values of the matrix by 1
	 * @return: copy of the current matrix
	 */
	Mat3x3 operator++(int);

	/* Pre-decrement operator--
	 * Decrements all the values of the matrix by 1
	 * @return: reference to the current matrix
	 */
	Mat3x3& operator--();

	/* Post-decrement operator--
	 * Decrements all the values of the matrix by 1
	 * @return: copy of the current matrix
	 */
	Mat3x3 operator--(int);

	/* UNARY OPERATORS */
	/* Unary operator+
	 * Returns the matrix as is
	 * @return: copy of the current matrix
	 */
	Mat3x3 operator+() const;

	/* Unary operator-
	 * Returns the matrix with all values negated
	 * @return: copy of the current matrix
	 */
	Mat3x3 operator-() const;

	/* Subscript operator[]
	 * Returns the element at the index specified as follows: from 1 to 9
	 * Throws std::invalid_argument("Index out of bounds") if the index is out of range
	 * @param index: index of the element to be returned
	 * @return: reference to the element at the index
	 */
	double& operator[](int index);

	/* Subscript operator[] const
	 * Returns the element at the index specified as follows: from 1 to 9
	 * Throws std::invalid_argument("Index out of bounds") if the index is out of range
	 * @param index: index of the element to be returned
	 * @return: copy of the element at the index
	 */
	double operator[](int index) const;

	/* Negation operator!
	 * Returns true if the matrix is non-invertible, false otherwise
	 * @return: true if the matrix is non-invertible, false otherwise
	 */
	bool operator!() const;

	/* Function object
	 * Overload the function call operator() such that it takes no arguments and returns 
	 * the determinant of the invoking matrix
	 * @return: determinant of the invoking matrix
	 */
	double operator()() const;

	/* Conversion operator
	 * Implement an explicit bool conversion operator that converts a Mat3x3 to bool. It 
	 * should return true if the matrix is invertible, false otherwise
	 * To call this operator, it is necessary to cast the object to bool
	 * @return: true if the matrix is invertible, false otherwise
	 */
	explicit operator bool() const;
};

/*
 * NON-MEMBER FUNCTIONS
 */

/* Overloaded operator<<
 * Prints the matrix to the output stream
 * @param os: output stream
 * @param m: matrix to be printed
 * @return: reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Mat3x3& m);

/* Overloaded operator>>
 * Reads the matrix from the input stream
 * @param is: input stream
 * @param m: matrix to be read
 * @return: reference to the input stream
 */
std::istream& operator>>(std::istream& is, Mat3x3& m);

/* BINARY OPERATORS */
/* Overloaded operator+
 * Adds two matrices
 * @param lhs: matrix to add
 * @param: rhs: matrix to add
 * @return: copy of the resulting matrix
 */
Mat3x3 operator+(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator-
 * Subtracts two matrices
 * @param lhs: matrix to subtract
 * @param: rhs: matrix to subtract
 * @return: copy of the resulting matrix
 */
Mat3x3 operator-(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator*
 * Multiplies two matrices
 * @param lhs: matrix to multiply
 * @param: rhs: matrix to multiply
 * @return: copy of the resulting matrix
 */
Mat3x3 operator*(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator/
 * Divides two matrices
 * Throws std::overflow_error("Division by zero") if the matrix is not invertible
 * @param lhs: matrix dividend
 * @param: rhs: matrix divisor
 * @return: copy of the resulting matrix
 */
Mat3x3 operator/(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator+
 * Adds a scalar to a matrix (right)
 * @param m: matrix to add
 * @param: scalar: scalar to add
 * @return: copy of the resulting matrix
 */
Mat3x3 operator+(const Mat3x3& m, double scalar);

/* Overloaded operator+
 * Adds a scalar to a matrix (left)
 * @param scalar: scalar to add
 * @param: m: matrix to add
 * @return: copy of the resulting matrix
 */
Mat3x3 operator+(double scalar, const Mat3x3& m);

/* Overloaded operator-
 * Subtracts a scalar from a matrix (right)
 * @param m: matrix to subtract
 * @param: scalar: scalar to subtract
 * @return: copy of the resulting matrix
 */
Mat3x3 operator-(const Mat3x3& m, double scalar);

/* Overloaded operator-
 * Subtracts a scalar from a matrix (left)
 * @param scalar: scalar to subtract
 * @param: m: matrix to subtract
 * @return: copy of the resulting matrix
 */
Mat3x3 operator-(double scalar, const Mat3x3& m);

/* Overloaded operator*
 * Multiplies a matrix by a scalar (left)
 * @param scalar: scalar to multiply
 * @param: m: matrix to multiply
 * @return: copy of the resulting matrix
 */
Mat3x3 operator*(double scalar, const Mat3x3& m);

/* Overloaded operator*
 * Multiplies a matrix by a scalar (right)
 * @param m: matrix to multiply
 * @param: scalar: scalar to multiply
 * @return: copy of the resulting matrix
 */
Mat3x3 operator*(const Mat3x3& m, double scalar);

/* Overloaded operator/
 * Divides a matrix by a scalar (left)
 * Throws std::overflow_error("Division by zero") if the scalar is 0
 * @param scalar: scalar to divide
 * @param: m: matrix to divide
 * @return: copy of the resulting matrix
 */
Mat3x3 operator/(double scalar, const Mat3x3& m);

/* Overloaded operator/
 * Divides a matrix by a scalar (right)
 * Throws std::overflow_error("Division by zero") if the scalar is 0
 * @param m: matrix to divide
 * @param: scalar: scalar to divide
 * @return: copy of the resulting matrix
 */
Mat3x3 operator/(const Mat3x3& m, double scalar);

/* Overloaded operator==
 * Compares two matrices
 * @param lhs: matrix to compare
 * @param: rhs: matrix to compare
 * @return: true if the matrices are equal, false otherwise
 */
bool operator==(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator!=
 * Compares two matrices
 * @param lhs: matrix to compare
 * @param: rhs: matrix to compare
 * @return: true if the matrices are different, false otherwise
 */
bool operator!=(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator<
 * Compares two matrices
 * @param lhs: matrix to compare
 * @param: rhs: matrix to compare
 * @return: true if lhs is less than rhs, false otherwise
 */
bool operator<(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator>
 * Compares two matrices
 * @param lhs: matrix to compare
 * @param: rhs: matrix to compare
 * @return: true if lhs is greater than rhs, false otherwise
 */
bool operator>(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator<=
 * Compares two matrices
 * @param lhs: matrix to compare
 * @param: rhs: matrix to compare
 * @return: true if lhs is less than or equal to rhs, false otherwise
 */
bool operator<=(const Mat3x3& lhs, const Mat3x3& rhs);

/* Overloaded operator>=
 * Compares two matrices
 * @param lhs: matrix to compare
 * @param: rhs: matrix to compare
 * @return: true if lhs is greater than or equal to rhs, false otherwise
 */
bool operator>=(const Mat3x3& lhs, const Mat3x3& rhs);

/* roundNearZero()
 * Helper function to round numbers close to an integer
 * It is only used for printing format purposes
 * @param value: value to be rounded
 * @return: rounded value
 */
double roundNearZero(double value);
