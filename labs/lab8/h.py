s_array = []
num = int(input())
for i in range(num):
    b = str(input())
    s_array.append(b)

s = ''
if len(s_array) > 1 and len(s_array[0]) > 0:
    for i in range(len(s_array[0])):
        for j in range(len(s_array[0]) - i + 1):
            if j > len(s) and all(s_array[0][i:i + j] in x for x in s_array):
                s = s_array[0][i:i + j]

print(s)