import subprocess

for i in range(100):
    subprocess.call("./t7 " + str(i), shell=True)
