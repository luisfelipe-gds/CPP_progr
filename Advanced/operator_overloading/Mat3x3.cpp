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
 * ***************************************************************************
 * Class Description: Mat3x3 class cpp file containing the definition of all
 * member functions and operators. The class is responsible for handling 3x3 
 * matrices and performing operations on them. This class's purpose is to 
 * provide practice on operator overloading.
 * 
 * ***************************************************************************
 */


#include "Mat3x3.h"

/* CONSTRUCTORS */
// Default constructor
Mat3x3::Mat3x3()
{
	theMatrix = 
	{ 
		{ 
			{0, 0, 0}, 
			{0, 0, 0}, 
			{0, 0, 0} 
		} 
	};
}

// Custom constructor
Mat3x3::Mat3x3(std::array<double, 9> val)
{
	theMatrix = 
	{ 
		{
			{val[0], val[1], val[2]}, 
			{val[3], val[4], val[5]}, 
			{val[6], val[7], val[8]} 
		} 
	};
}

/* SPECIAL MEMBER FUNCTIONS */
// Copy constructor
Mat3x3::Mat3x3(const Mat3x3& m) = default;

// Move constructor
Mat3x3::Mat3x3(Mat3x3&& m) noexcept = default;

// Copy assignment operator
Mat3x3& Mat3x3::operator=(const Mat3x3& m) = default;

// Move assignment operator
Mat3x3& Mat3x3::operator=(Mat3x3&& m) noexcept = default;

// Destructor
Mat3x3::~Mat3x3() = default;

/* MEMBER FUNCTIONS */
// read()
void Mat3x3::read(std::istream& is)
{
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) is >> theMatrix[i][j];
		}
	}
}

// write()
void Mat3x3::write(std::ostream& os) const
{
	// Printing the elements of the matrix
	// rounded to the nearest zero for better readability
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			os << roundNearZero(theMatrix[i][j]) << " ";
		}
		os << "\n";
	}
}

// determinant()
double Mat3x3::determinant() const
{
	double det;

	/*
	 * The determinant of a 3x3 matrix calculated by the formula as 
	 * shown in the assignment prompt. 
	*/

	det = 
		theMatrix[0][0] * (theMatrix[1][1] * theMatrix[2][2] - theMatrix[1][2] * theMatrix[2][1]) -
		theMatrix[0][1] * (theMatrix[1][0] * theMatrix[2][2] - theMatrix[1][2] * theMatrix[2][0]) +
		theMatrix[0][2] * (theMatrix[1][0] * theMatrix[2][1] - theMatrix[1][1] * theMatrix[2][0]);
	
	return det;
}

// trace()
double Mat3x3::trace() const
{
	return 
		theMatrix[0][0] + 
		theMatrix[1][1] + 
		theMatrix[2][2];  // Sum of the diagonal elements
}

// norm() const
double Mat3x3::norm() const
{
	double norm = 0;

	// Calculating the norm of the matrix
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) norm += theMatrix[i][j] * theMatrix[i][j];
	}
	return std::sqrt(norm);
}

// conditionNumber() const
double Mat3x3::conditionNumber() const
{
	if (!isInvertible())
	{
		throw std::overflow_error("Condition number undefined!");
	}
	else
	{
		return norm() * inverse().norm();
	}
}

// isAntiSymmetric() const
bool Mat3x3::isAntiSymmetric() const
{
	return *this == -transpose();
}

// isOrthogonal()
bool Mat3x3::isOrthogonal() const
{
	return 
		*this * transpose() == Mat3x3(
			{
				1, 0, 0, 
				0, 1, 0, 
				0, 0, 1
			});			// The product of the matrix and its 
						// transpose should be the identity matrix
}

// isInvertible()
bool Mat3x3::isInvertible() const 
{
	return determinant() != 0;
}

// isSymmetric()
bool Mat3x3::isSymmetric() const
{
	return transpose() == *this;
}

// transpose()
Mat3x3 Mat3x3::transpose() const
{
	Mat3x3 transposed;

	/*
	 * The transpose of a 3x3 matrix is calculated by swapping the
	 * elements of the matrix diagonally. The loop below does that.
	 */
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) transposed.theMatrix[i][j] = theMatrix[j][i];
	}
	return transposed;
}

// inverse()
Mat3x3 Mat3x3::inverse() const
{
	if (!isInvertible())
	{
		throw std::overflow_error("Inverse undefined!");
	}
	else
	{
		Mat3x3 inv;
		double det_inv = 1 / determinant();

		/*
		 * The inverse of a 3x3 matrix is calculated by the formula as
		 * shown in the assignment prompt, reproduced below.
		*/

		inv.theMatrix[0][0] = (theMatrix[1][1] * theMatrix[2][2] - theMatrix[1][2] * theMatrix[2][1]) * det_inv;
		inv.theMatrix[0][1] = (theMatrix[0][2] * theMatrix[2][1] - theMatrix[0][1] * theMatrix[2][2]) * det_inv;
		inv.theMatrix[0][2] = (theMatrix[0][1] * theMatrix[1][2] - theMatrix[0][2] * theMatrix[1][1]) * det_inv;
		inv.theMatrix[1][0] = (theMatrix[1][2] * theMatrix[2][0] - theMatrix[1][0] * theMatrix[2][2]) * det_inv;
		inv.theMatrix[1][1] = (theMatrix[0][0] * theMatrix[2][2] - theMatrix[0][2] * theMatrix[2][0]) * det_inv;
		inv.theMatrix[1][2] = (theMatrix[1][0] * theMatrix[0][2] - theMatrix[0][0] * theMatrix[1][2]) * det_inv;
		inv.theMatrix[2][0] = (theMatrix[1][0] * theMatrix[2][1] - theMatrix[1][1] * theMatrix[2][0]) * det_inv;
		inv.theMatrix[2][1] = (theMatrix[2][0] * theMatrix[0][1] - theMatrix[0][0] * theMatrix[2][1]) * det_inv;
		inv.theMatrix[2][2] = (theMatrix[0][0] * theMatrix[1][1] - theMatrix[0][1] * theMatrix[1][0]) * det_inv;
	
		return inv;
	}
}

// Compound assignment operator+=
Mat3x3& Mat3x3::operator+=(const Mat3x3& m)
{
	return *this = *this + m;
}

// Compound assignment operator-=
Mat3x3& Mat3x3::operator-=(const Mat3x3& m)
{
	return *this += -m;
}

// Compound assignment operator*=
Mat3x3& Mat3x3::operator*=(const Mat3x3& m)
{
	return *this = *this * m;
}

// Compound assignment operator/=
Mat3x3& Mat3x3::operator/=(const Mat3x3& m)
{
	return *this = *this / m;
}

// Compound assignment operator+=
Mat3x3& Mat3x3::operator+=(double scalar)
{
	return *this = *this + scalar;
}

// Compound assignment operator-=
Mat3x3& Mat3x3::operator-=(double scalar)
{
	return *this = *this - scalar;
}

// Compound assignment operator*=
Mat3x3& Mat3x3::operator*=(double scalar)
{
	return *this = *this * scalar;
}

// Compound assignment operator/=
Mat3x3& Mat3x3::operator/=(double scalar)
{
	return *this = *this / scalar;
}

// Pre-increment operator++
Mat3x3& Mat3x3::operator++()
{
	return *this += 1;
}

// Post-increment operator++
Mat3x3 Mat3x3::operator++(int)
{
	Mat3x3 temp = *this;  // Save the current value
	++*this;              // Increment the value	
	return temp;		  // Return the saved value
}

// Pre-decrement operator--
Mat3x3& Mat3x3::operator--()
{
	return *this -= 1;
}

// Post-decrement operator--
Mat3x3 Mat3x3::operator--(int)
{
	Mat3x3 temp = *this; // Save the current value
	--*this;			 // Decrement the value
	return temp;		 // Return the saved value
}

/* UNARY OPERATORS */
// Unary operator+
Mat3x3 Mat3x3::operator+() const
{
	return *this;
}

// Unary operator-
Mat3x3 Mat3x3::operator-() const
{
	return *this * -1;
}

// Overloaded operator+
Mat3x3 operator+(const Mat3x3& lhs, const Mat3x3& rhs)
{
	Mat3x3 sum;

	// Summing the elements of the matrices
	sum.theMatrix[0][0] = lhs.theMatrix[0][0] + rhs.theMatrix[0][0];
	sum.theMatrix[0][1] = lhs.theMatrix[0][1] + rhs.theMatrix[0][1];
	sum.theMatrix[0][2] = lhs.theMatrix[0][2] + rhs.theMatrix[0][2];
	sum.theMatrix[1][0] = lhs.theMatrix[1][0] + rhs.theMatrix[1][0];
	sum.theMatrix[1][1] = lhs.theMatrix[1][1] + rhs.theMatrix[1][1];
	sum.theMatrix[1][2] = lhs.theMatrix[1][2] + rhs.theMatrix[1][2];
	sum.theMatrix[2][0] = lhs.theMatrix[2][0] + rhs.theMatrix[2][0];
	sum.theMatrix[2][1] = lhs.theMatrix[2][1] + rhs.theMatrix[2][1];
	sum.theMatrix[2][2] = lhs.theMatrix[2][2] + rhs.theMatrix[2][2];

	return sum;
}

// Overloaded operator-
Mat3x3 operator-(const Mat3x3& lhs, const Mat3x3& rhs)
{
	Mat3x3 dif;

	// Subtracting the elements of the matrices
	dif.theMatrix[0][0] = lhs.theMatrix[0][0] - rhs.theMatrix[0][0];
	dif.theMatrix[0][1] = lhs.theMatrix[0][1] - rhs.theMatrix[0][1];
	dif.theMatrix[0][2] = lhs.theMatrix[0][2] - rhs.theMatrix[0][2];
	dif.theMatrix[1][0] = lhs.theMatrix[1][0] - rhs.theMatrix[1][0];
	dif.theMatrix[1][1] = lhs.theMatrix[1][1] - rhs.theMatrix[1][1];
	dif.theMatrix[1][2] = lhs.theMatrix[1][2] - rhs.theMatrix[1][2];
	dif.theMatrix[2][0] = lhs.theMatrix[2][0] - rhs.theMatrix[2][0];
	dif.theMatrix[2][1] = lhs.theMatrix[2][1] - rhs.theMatrix[2][1];
	dif.theMatrix[2][2] = lhs.theMatrix[2][2] - rhs.theMatrix[2][2];

	return dif;
}

// Overloaded operator*
Mat3x3 operator*(const Mat3x3& lhs, const Mat3x3& rhs)
{
	Mat3x3 prod;

	// Multiplying the matrices using the formula
	// as shown in the assignment prompt
	prod.theMatrix[0][0] = (lhs.theMatrix[0][0] * rhs.theMatrix[0][0] + lhs.theMatrix[0][1] * rhs.theMatrix[1][0] + lhs.theMatrix[0][2] * rhs.theMatrix[2][0]);
	prod.theMatrix[0][1] = (lhs.theMatrix[0][0] * rhs.theMatrix[0][1] + lhs.theMatrix[0][1] * rhs.theMatrix[1][1] + lhs.theMatrix[0][2] * rhs.theMatrix[2][1]);
	prod.theMatrix[0][2] = (lhs.theMatrix[0][0] * rhs.theMatrix[0][2] + lhs.theMatrix[0][1] * rhs.theMatrix[1][2] + lhs.theMatrix[0][2] * rhs.theMatrix[2][2]);
	
	prod.theMatrix[1][0] = (lhs.theMatrix[1][0] * rhs.theMatrix[0][0] + lhs.theMatrix[1][1] * rhs.theMatrix[1][0] + lhs.theMatrix[1][2] * rhs.theMatrix[2][0]);
	prod.theMatrix[1][1] = (lhs.theMatrix[1][0] * rhs.theMatrix[0][1] + lhs.theMatrix[1][1] * rhs.theMatrix[1][1] + lhs.theMatrix[1][2] * rhs.theMatrix[2][1]);
	prod.theMatrix[1][2] = (lhs.theMatrix[1][0] * rhs.theMatrix[0][2] + lhs.theMatrix[1][1] * rhs.theMatrix[1][2] + lhs.theMatrix[1][2] * rhs.theMatrix[2][2]);

	prod.theMatrix[2][0] = (lhs.theMatrix[2][0] * rhs.theMatrix[0][0] + lhs.theMatrix[2][1] * rhs.theMatrix[1][0] + lhs.theMatrix[2][2] * rhs.theMatrix[2][0]);
	prod.theMatrix[2][1] = (lhs.theMatrix[2][0] * rhs.theMatrix[0][1] + lhs.theMatrix[2][1] * rhs.theMatrix[1][1] + lhs.theMatrix[2][2] * rhs.theMatrix[2][1]);
	prod.theMatrix[2][2] = (lhs.theMatrix[2][0] * rhs.theMatrix[0][2] + lhs.theMatrix[2][1] * rhs.theMatrix[1][2] + lhs.theMatrix[2][2] * rhs.theMatrix[2][2]);

	return prod;
}

// Overloaded operator/
Mat3x3 operator/(const Mat3x3& lhs, const Mat3x3& rhs)
{
	return lhs * rhs.inverse();
}

 // Overloaded operator+ (right)
Mat3x3 operator+(const Mat3x3& m, double scalar)
{
	Mat3x3 sum;
	sum.theMatrix[0][0] = m.theMatrix[0][0] + scalar;
	sum.theMatrix[0][1] = m.theMatrix[0][1] + scalar;
	sum.theMatrix[0][2] = m.theMatrix[0][2] + scalar;
	sum.theMatrix[1][0] = m.theMatrix[1][0] + scalar;
	sum.theMatrix[1][1] = m.theMatrix[1][1] + scalar;
	sum.theMatrix[1][2] = m.theMatrix[1][2] + scalar;
	sum.theMatrix[2][0] = m.theMatrix[2][0] + scalar;
	sum.theMatrix[2][1] = m.theMatrix[2][1] + scalar;
	sum.theMatrix[2][2] = m.theMatrix[2][2] + scalar;
	return sum;
}

// Overloaded operator+ (left)
Mat3x3 operator+(double scalar, const Mat3x3& m)
{
	return m + scalar;
}

// Overloaded operator-
Mat3x3 operator-(const Mat3x3& m, double scalar)
{
	return m + (-scalar);
}

// Overloaded operator-
Mat3x3 operator-(double scalar, const Mat3x3& m)
{
	return scalar + (-m);
}

// Overloaded operator * (left scalar)
Mat3x3 operator*(double scalar, const Mat3x3& m)
{
	Mat3x3 prod;
	
	// Multiplying the matrix by a scalar
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			prod.theMatrix[i][j] = scalar * m.theMatrix[i][j];
		}
	}
	return prod;
}

// Overloaded operator* (right scalar)
Mat3x3 operator*(const Mat3x3& m, double scalar)
{
	Mat3x3 prod;
	prod = scalar * m;
	return prod;
}

// Overloaded operator/ (left scalar)
Mat3x3 operator/(double scalar, const Mat3x3& m)
{	
	// Checking if the matrix is invertible
	if (!m.isInvertible())
	{
		throw std::overflow_error("Inverse undefined!");
	}
	Mat3x3 div;
	div = scalar * m.inverse(); // Multiplying the matrix by the inverse
	return div;
}

// Overloaded operator/ (right scalar)
Mat3x3 operator/(const Mat3x3& m, double scalar)
{
	// Checking if the scalar is zero
	if (scalar <= Mat3x3::NEAR_ZERO)
	{
		throw std::overflow_error("Division by zero");
	}
	Mat3x3 div;
	div = m * (1 / scalar); // Multiplying the matrix by the inverse of the scalar
	return div;
}

// Overloaded operator==
bool operator==(const Mat3x3& lhs, const Mat3x3& rhs)
{
	// Comparing the elements of the matrices with a tolerance
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (std::abs(lhs.theMatrix[i][j] - rhs.theMatrix[i][j]) > Mat3x3::NEAR_ZERO)
			{
				return false;
			}
		}
	}
	return true;
}

// Overloaded operator!=
bool operator!=(const Mat3x3& lhs, const Mat3x3& rhs)
{
	return !(lhs == rhs);
}

// Overloaded operator<
bool operator<(const Mat3x3& lhs, const Mat3x3& rhs)
{
	if (lhs == rhs) return false; // If the matrices are equal, they are not less than each other

	bool isLess;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// If the element of the left matrix is less than the element of the right matrix
			// the left matrix is less than the right matrix
			if (lhs.theMatrix[i][j] > rhs.theMatrix[i][j])
			{
				isLess = false;
			}
			else
			{
				isLess = true;
			}
		}
	}
	return isLess;
}

// Overloaded operator>
bool operator>(const Mat3x3& lhs, const Mat3x3& rhs)
{
	if (lhs == rhs) return false; // If the matrices are equal, they are not greater than each other

	bool isGreater;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// If the element of the left matrix is less than the element of the right matrix
			// the left matrix is less than the right matrix
			if (lhs.theMatrix[i][j] < rhs.theMatrix[i][j])
			{
				isGreater = false;
			}
			else
			{
				isGreater = true;
			}
		}
	}
	return isGreater;
}

// Overloaded operator<=
bool operator<=(const Mat3x3& lhs, const Mat3x3& rhs)
{
	return ((lhs < rhs) || (lhs == rhs));
}

// Overloaded operator>=
bool operator>=(const Mat3x3& lhs, const Mat3x3& rhs)
{
	return  ((lhs > rhs) || (lhs == rhs));
}

// Overloaded operator[]
double& Mat3x3::operator[](int index)
{
	// Checking if the index is out of bounds
	if (index < 1 || index > 9)
	{
		throw std::invalid_argument("Index out of bounds");
	}

	// Decrementing the index to match the array
	// indexing and returning the element
	index--; 

	// The return divides the index by 3 to get the row
	// and gets the remainder of the division to get the column
	return theMatrix[(index / 3)][(index % 3)];
}

// Overloaded operator[]
double Mat3x3::operator[](int index) const
{
	// Checking if the index is out of bounds
	if (index < 1 || index > 9)
	{
		throw std::invalid_argument("Index out of bounds");
	}

	// Decrementing the index to match the array
	// indexing and returning the element
	index--;

	// The return divides the index by 3 to get the row
	// and gets the remainder of the division to get the column
	return theMatrix[(index / 3)][(index % 3)];
}

// Overloaded operator!
bool Mat3x3::operator!() const
{
	if (isInvertible())
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Overloaded function operator
double Mat3x3::operator()() const
{
	return determinant();
}

// Conversion operator
Mat3x3::operator bool() const
{
	return isInvertible();
}

// Overloaded operator<<
std::ostream& operator<<(std::ostream& os, const Mat3x3& m)
{
	m.write(os);
	return os;
}

// Overloaded operator>>
std::istream& operator>>(std::istream& is, Mat3x3& m)
{
	m.read(is);
	return is;
}

// roundNearZero()
double roundNearZero(double value)
{
	double intPart;
	double fracPart = std::modf(value, &intPart);
	if (std::abs(fracPart) < Mat3x3::NEAR_ZERO) {
		return std::round(value);
	}
	return value;
}




