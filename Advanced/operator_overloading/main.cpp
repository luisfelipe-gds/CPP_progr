/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: this is the main file for the assignment. It contains
 * the main function that tests all the functionalities of the Mat3x3 class.
 * It contains additional tests versus the ones provided in the assignment.
 * 
 * ***************************************************************************
 */
/*
#include "Mat3x3.h"
#include <cassert>

int main()
{
	
	Mat3x3 im({ 1,0,0,0,1,0,0,0,1 });
	Mat3x3 A({ 1, 1, -2, -3, -2, 5, -6, 4, 4 });
	Mat3x3 m2({ -28,-12,1,-18,-8,1,-24,-10,1 });

	Mat3x3 aInvSolution; // default ctor
	aInvSolution += 0.5 * m2; // op+=, op* (left scaler mult.)

	cout << "im: \n" << im << "\n"; // op<<
	cout << "A: \n" << A << "\n";
	cout << "aInvSolution: \n" << aInvSolution << "\n";

	assert(A * aInvSolution == im); // op*, op==
	
	Mat3x3 AinvComputed = A.inverse();
	cout << "AinvComputed: \n" << AinvComputed << "\n";
	
	assert(aInvSolution == AinvComputed); // inverse ok
		
	Mat3x3 B({ -2, 5, -2, -2, 2, 0, -3, -2, 2 });
	Mat3x3 m4({ 4, -6, 4, 4, -10, 4, 10, -19, 6 });
	Mat3x3 bInvSolution = m4 * (-0.125); // op=, op* (right scaler mult.)
	
	cout << "B: \n" << B << "\n";
	cout << "bInvSolution: \n" << bInvSolution << "\n";

	assert(B * bInvSolution == im);
	
	Mat3x3 bInvComputed = B.inverse();
	cout << "bInvComputed: \n" << bInvComputed << "\n";

	assert(bInvSolution == bInvComputed); // inverse ok
	assert((A * B).inverse() == B.inverse() * A.inverse());
	
	Mat3x3 C({ 2,7,3,1,5,8,0,4,1 });
	cout << "C: \n" << C << "\n";
	Mat3x3 D({ 3,0,1,2,1,0,1,2,4 });
	cout << "D: \n" << D << "\n";
	Mat3x3 CxD({ 23,13,14,21,21,33,9,6,4 });
	cout << "CxD: \n" << CxD << "\n";
	
	assert(C * D == CxD);
	
	cout << "CxD / D: \n" << (CxD / D) << "\n";
	
	assert(C == CxD / D);

	cout << "CxD / C: \n" << (CxD / C) << "\n";

	assert(C.inverse() * CxD == D);
	assert(--A == ++A); // unary + and -
	assert(-6 == Mat3x3({ 1,3,-2,4,1,-1,5,-3,2 }).determinant());
	assert(A.transpose().transpose() == A);
	assert(1.0 / (A.determinant()) == (A.inverse()).determinant());
	assert(A.transpose().determinant() == A.determinant());
	assert((A * B).transpose() == (B.transpose()) * (A.transpose()));
	
	Mat3x3 oldC{ C };
	cout << "oldC: \n" << oldC << "\n";
	cout << "C: \n" << C << "\n";
	Mat3x3 Cpp{ C++ };
	cout << "Cpp: \n" << Cpp << "\n";
	cout << "C: \n" << C << "\n";

	assert(Cpp == oldC);
	assert(--C == oldC);

	cout << "C: \n" << C << "\n";
	cout << "oldC: \n" << oldC << "\n";

	// OTHER TESTS
	assert(A.trace() == 3);	  // trace

	Mat3x3 AntiSym({0,4,7,-4,0,-3,-7,3,0});

	assert(AntiSym.isAntiSymmetric() == true);  // isAntiSymmetric : expected true
	assert(A.isAntiSymmetric() == false);		// isAntiSymmetric : expected false
	assert(im.isSymmetric() == true);			// isSymmetric	   : expected true
	assert(A.isSymmetric() == false);			// isSymmetric     : expected false
	assert(im.isOrthogonal() == true);			// isOrthogonal    : expected true
	assert(A.isOrthogonal() == false);			// isOrthogonal    : expected false
	assert(A.isInvertible() == true);			// isInvertible    : expected true
	assert(AntiSym.isInvertible() == false);	// isInvertible    : expected false

	assert(A < im == false);					// op<			   : expected false

	Mat3x3 Smaller({ -1,-1,-1,-1,-1,-1,-1,-1,-1 });

	assert(Smaller < A == true);				// op<			   : expected true
	assert(Smaller < Smaller == false);			// op<			   : expected false

	assert(Smaller <= Smaller == true);			// op<=			   : expected true
	assert(Smaller >= Smaller == true);			// op>=			   : expected true

	assert(m2[1] == -28);						// op[]			   : expected -28
	assert(m2[9] == 1);							// op[]			   : expected 1

	assert(!A == false);						// op!			   : expected false
	assert(!AntiSym == true);					// op!			   : expected true

	assert(A() == A.determinant());				// op()			   

	// testing the bool conversion
	if (A) 
	{ 
		cout << "A is invertible \n"; 
	}
	else { 
		cout << "A is not invertible \n"; 
	} 

	assert(-(-A) == +(+A));

	cout << endl;

	cout << A.norm() << "\n"; // norm
	cout << A.conditionNumber() << "\n"; // conditionNumber

	cout << endl;

	cout << "All tests passed! \n";

	return 0;
}


*/
