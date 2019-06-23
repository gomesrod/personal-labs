import os

print(os.getcwd())

os.chdir("/tmp")
print(os.getcwd())

os.system("echo `whoami`")

