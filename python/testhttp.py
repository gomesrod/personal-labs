from urllib.request import urlopen

pagecontent = urlopen("http://localhost")
for line in pagecontent:
	line = line.decode("utf-8")
	print(">>>>>>> " + line)




