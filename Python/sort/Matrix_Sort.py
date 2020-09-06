def sort_matrix(mat, size):
    temp_mat = [0]*(size*size)
    count = 0
    for i in range(size):
        for j in range(size):
            temp_mat[count] = mat[i][j]
            count += 1
    temp_mat.sort()

    count = 0
    for i in range(size):
        for j in range(size):
            mat[i][j] = temp_mat[count]
            count += 1
    return mat


def display_matrix(mat, size):
    for i in range(size):
        for j in range(size):
            print(mat[i][j], end=' ')
        print()


if __name__ == '__main__':
    size = int(input('Enter size: '))
    mat = []
    for i in range(size):
        print(f'Enter all elements of row {i+1} separated by space: ', end='')
        row = list(map(int, input().split()))
        mat.append(row)

    print('Before sorting: ')
    display_matrix(mat, size)
    mat = sort_matrix(mat, size)
    print('After sorting: ')
    display_matrix(mat, size)


# Sample Output

# Enter size: 3
# Enter all elements of row 1 separated by space: 8 3 5
# Enter all elements of row 2 separated by space: 9 1 2
# Enter all elements of row 3 separated by space: 4 7 6
# Before sorting:
# 8 3 5
# 9 1 2
# 4 7 6
# After sorting:
# 1 2 3
# 4 5 6
# 7 8 9


# time complexity = O(n^2log2(n))
# space complexity = O(n^2)
