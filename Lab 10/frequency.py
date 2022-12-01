# code to find the frequency of words
# Author : Ameeya Ranjan Sethy

text_file = open("sample_file.txt", "r")

c = dict()

for line in text_file:
	line = line.strip()
	line = line.lower()
	words = line.split(" ")
	
	for word in words:
		if word in c:
		   c[word] = c[word] + 1
		else:
		   c[word] = 1
		   
for key in list(c.keys()):
	print(key, "-", c[key])
