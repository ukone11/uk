def add_matrices(matrix1, matrix2):
    return [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def subtract_matrices(matrix1, matrix2):
    return [[matrix1[i][j] - matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def multiply_matrices(matrix1, matrix2):
    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

def transpose_matrix(matrix):
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

def input_matrix(rows, cols):
    print(f"Enter the elements of a {rows}x{cols} matrix row by row:")
    return [[int(input(f"Element [{i+1},{j+1}]: ")) for j in range(cols)] for i in range(rows)]

def display_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

def main():
    print("Matrix Operations")
    rows1 = int(input("Enter the number of rows for the first matrix: "))
    cols1 = int(input("Enter the number of columns for the first matrix: "))
    matrix1 = input_matrix(rows1, cols1)

    rows2 = int(input("Enter the number of rows for the second matrix: "))
    cols2 = int(input("Enter the number of columns for the second matrix: "))
    matrix2 = input_matrix(rows2, cols2)

    print("\nMatrix 1:")
    display_matrix(matrix1)

    print("\nMatrix 2:")
    display_matrix(matrix2)

    if rows1 == rows2 and cols1 == cols2:
        print("\nAddition of matrices:")
        display_matrix(add_matrices(matrix1, matrix2))

        print("\nSubtraction of matrices:")
        display_matrix(subtract_matrices(matrix1, matrix2))
    else:
        print("\nAddition and subtraction not possible. Matrices must have the same dimensions.")

    if cols1 == rows2:
        print("\nMultiplication of matrices:")
        display_matrix(multiply_matrices(matrix1, matrix2))
    else:
        print("\nMultiplication not possible. Number of columns in Matrix 1 must equal the number of rows in Matrix 2.")

    print("\nTranspose of Matrix 1:")
    display_matrix(transpose_matrix(matrix1))

    print("\nTranspose of Matrix 2:")
    display_matrix(transpose_matrix(matrix2))

if __name__ == "__main__":
    main()
