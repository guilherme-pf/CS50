text = input("Text: ")

# Counting words
words = text.count(" ") + 1

# Counting letters
letters = 0
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    else:
        letters += 0

# Counting sentences
sentences = 0
for i in range(len(text)):
    if text[i] == "?" or text[i] == "!" or text[i] == ".":
        sentences += 1
    else:
        sentences += 0

# Calculating the index
index = round((0.0588 * (letters / words * 100)) - (0.296 * (sentences / words * 100)) - 15.8)

# Printing results
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

print(index)

