file_in = open("input.txt", mode="r", encoding="utf-8")
k = (file_in.readline())
k = int(k)
m = file_in.readlines()
new_m = []
m = [i.split()[-3:] for i in m]
m = [list(map(int, i)) for i in m]
total = []
for i in range(len(m)):
    if (min(m[i]) >= 40):
        new_m.append(m[i])
for i in range(len(new_m)):
    total.append(sum(new_m[i]))
total = sorted(total)
file_out = open("output.txt", mode="w", encoding="utf-8")
if k == 0:
    file_out.write("0")
elif len(total) <= k:
    file_out.write("0")
else:
    flag = 0
    if total[-k] != total[-k - 1]:
        file_out.write(str(total[-k]))
    else:
        for i in range(-k - 1, 0):
            if total[i] != total[-k]:
                file_out.write(str(total[i]))
                flag = 1
                break
        if flag != 1:
            file_out.write("1")
file_out.close()
