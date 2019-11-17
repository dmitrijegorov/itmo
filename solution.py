file_in = open("input.txt", mode="r", encoding="utf-8")
k = (file_in.readline())
k = int(k)
arr = file_in.readlines()
arr_new = []
arr = [i.split()[-3:] for i in arr]
arr = [list(map(int, i)) for i in arr]
total = []
for i in range(len(arr)):
    if (min(arr[i]) >= 40):
        arr_new.append(arr[i])
for i in range(len(arr_new)):
    total.append(sum(arr_new[i]))
total = sorted(total)
file_out = open("output.txt", mode="w", encoding="utf-8")
if k == 0:
    file_out.write("0")
elif len(total) <= k:
    file_out.write("0")
else:
    flag = 0
    if total[-k] == total[-k - 1]:
        for i in range(-k - 1, 0):
            if total[i] != total[-k]:
                file_out.write(str(total[i]))
                flag = 1
        if flag != 1:
            file_out.write("1")
    else:
        file_out.write(str(total[-k]))
file_out.close()
