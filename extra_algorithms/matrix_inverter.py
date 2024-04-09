"""
the main purpose of this program is to find the inverse of a nxn matrix 
using python 

refer the readme file for the write up of the program
"""


def MatrixCreator(n):
    matrix = []
    for i in range(0, n):
        row = input(f"Enter row {i}:")
        temp_list = []
        for j in row.split():
            temp_list.append(float(j))
        matrix.append(temp_list)

    return matrix


MATRIX = MatrixCreator(int(input("Enter the order of the matrix:")))

# print(Matrix)


def MatrixDisplay(Matrix, n):
    for i in range(0, n):
        for j in range(0, n):
            print(Matrix[i][j], end=" ")
        print()


def Submatrix(matrix, i, j):
    submatrix = []

    for row in range(0, len(matrix)):
        temp_list = []
        for column in range(0, len(matrix)):
            # print(row,column)
            if row != i and column != j:
                # print(row, column,matrix[row][column])
                temp_list.append(matrix[row][column])
        if len(temp_list) != 0:
            submatrix.append(temp_list)
    return submatrix


def Determinant(Matrix, n):
    sum1 = 0
    if n == 2:
        return ((Matrix[0][0]) * (Matrix[1][1])) - ((Matrix[0][1]) * (Matrix[1][0]))
    elif n == 1:
        return Matrix[0][0]
    for i in range(0, n):
        sum1 += (
            ((-1) ** (i + 0 + 2))
            * (Matrix[0][i])
            * (Determinant(Submatrix(Matrix, 0, i), n - 1))
        )
    return sum1


Det = Determinant(MATRIX, len(MATRIX))

# print(Det)


def Adjoint(Matrix, n):
    AdjMatrix = []

    for i in range(0, n):
        temp_list = []
        for j in range(0, n):
            cij = ((-1) ** (i + j + 2)) * (Determinant(Submatrix(Matrix, j, i), n - 1))
            temp_list.append(cij)
        AdjMatrix.append(temp_list)
    return AdjMatrix


AdjMatrix = Adjoint(MATRIX, len(MATRIX))

# print(AdjMatrix)


def Inverter(AdjMatrix, Det, n):
    InvertedMatrix = []
    if Det == 0:
        return "The matrix cannot be inverted since the determinant is 0"
    for i in range(0, n):
        temp_list = []
        for j in range(0, n):
            val = (1 / Det) * AdjMatrix[i][j]
            temp_list.append(val)
        InvertedMatrix.append(temp_list)
    return InvertedMatrix


InvertedMatrix = Inverter(AdjMatrix, Det, len(MATRIX))

if Det != 0:
    MatrixDisplay(InvertedMatrix, len(InvertedMatrix))
else:
    print(InvertedMatrix)
