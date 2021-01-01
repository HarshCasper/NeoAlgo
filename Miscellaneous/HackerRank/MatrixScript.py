first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)
string = ""
for y in range(m):
    for x in range(n):
        string += matrix[x][y]
pattern = re.compile('(\w)(\W)+(\w)')
subs = pattern.sub(r"\1 \3", string)
print(subs)