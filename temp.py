import re
from collections import Counter

Text = '''and Game of Thrones is an American fantasy drama television series created by David Benioff and D. B. Weiss for HBO. The show was both produced and filmed in Belfast elsewhere in the United Kingdom.'''

split_text = Text.split(' ')
count = Counter(split_text)
most_freq_word_new = [key for key,valu in count.items() if valu == max(count.values())]

result =  {i: {"suffix_word": [], "prefix_word": []} for i in most_freq_word_new}     #Create Dict with word as key and list as value
for index, word in enumerate(split_text):
    for i in most_freq_word_new:
        if word == i:
            suffix_word =  split_text[index + 1]
            prefix_word =  split_text[index - 1]
            result[word]["suffix_word"].append(suffix_word)
            result[word]["prefix_word"].append(prefix_word)

print(result)