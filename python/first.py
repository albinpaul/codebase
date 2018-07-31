import re
import time

start_time = time.time()
f1 = open('misspelled.txt', 'w+')


def linS(matches, words):
    for s in words:
        if s == matches:
            return True
    return False


words = [s.strip("\n").lower() for s in open("dict.txt")]
words.sort()  # sort the list

with open("texttobetested.txt", encoding="utf8") as text:
    content = text.read().split(" ")
    print(content)
    content = [item.lower() for item in content]
    content = ' '.join(content)
    content = re.findall("[a-z]+", content)

for w in content:
    if not linS(content, words):
        f1.write(w+'\n')

f1.close()

print("--- %s seconds ---" % (time.time() - start_time))
