import sys

text = sys.stdin.read()
string = [i for j in text.split("\n") for i in j.split()]
dictionary = {}
for i in string:
    if i not in dictionary:
        dictionary[i] = 1
    else:
        dictionary[i] += 1
m = 0
value = "zzzzzzzz"
for i, j in zip(dictionary.keys(), dictionary.values()):
    if j > m:
        value = i
        m = j
    if j == m and value > i:
        value = i
print(value)
