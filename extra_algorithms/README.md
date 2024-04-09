This algorithm is to find the inverese of a nxn matrix.
the formula we will be using is inverse(A) = adjoint(A)/det(A)
adjoint(A) is definied as the inverse of the cofactor matrix 
cofactor matrix is given as the matrix whose terms

C[i][j] = (-1)^(i+j) * M(ij)

where M is given by the determinant of the sub matrix

it requires the following steps:
    1. form the matrix
    2. find the determinant of the matrix
    3. find the adjoint of the matrix

these are the following substeps
1. forming the matrix:
	A. Take the input row by row
	B. Append the input as a nested list to matrix list
2. finding the determinant of the matrix:
	This will use recursion, recursively finding the value of the 
	determinants of the submatrices to find out the value of the 
	end matrix
	to find out the determinant of a nxn matrix we will keep dividing
	it as (n-1)x(n-1) matrices until we reach the base condition 
	which is a 2x2 matrix, when we reach this we will solve the problem
	using the forumla ad - bc
	
	2A. we will require to pass a submatrix recursively. this needs to
	    to be done for every element in the first row the matrix

	
3. finding the adjoint of the matrix
	This too will use recursion, very similar to the determinant of 
	the matrix since this too requires the same formula but without
	ddition
	3A. (refering 2A) we need to pass the submatrix but here we need 
	    to do it for every element in the matrix and not just the first 
	    row


