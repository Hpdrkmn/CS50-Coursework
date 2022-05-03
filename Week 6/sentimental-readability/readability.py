# TODO
from cs50 import get_string

text = get_string("Text: ").strip()
num_words, num_letters, num_sentences = 0, 0, 0

# using index to use entered text to find wnumber of words, number of letters and sentences
for i in range(len(text)):
    if (i == 0 and text[i] != ' ') or (i != len(text) - 1 and text[i] == ' ' and text[i + 1] != ' '):
        num_words += 1
    if text[i].isalpha():
        num_letters += 1
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        num_sentences += 1

length = num_letters / num_words * 100
sentence = num_sentences / num_words * 100

# equation to find grade level
index = round(0.0588 * length - 0.296 * sentence - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")