import subprocess

max_seed = 100

for i in range(max_seed):
    print("Running randomized test {i} of {max}...".format(i=i, max=max_seed))
    r = subprocess.check_output("./trand {i} | sed 1,2d | sed \\$d".format(i=i), shell=True)
    myr = subprocess.check_output("./mytrand {i} | sed 1,2d | sed \\$d".format(i=i), shell=True)

    if r == myr:
        print("Results are the same! test {i} passed!".format(i=i))
    else:
        print("Results are different for seed = {i}!".format(i=i))
