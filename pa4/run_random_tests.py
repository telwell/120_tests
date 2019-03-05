import subprocess

# Designed as a final check to make sure your code matches the provided code.
# Note that a randomized test can be rerun manually from the pa4 directory with
#     ./trand seed
# and
#     ./mytrand seed

max_seed = 1000
success = 0
failure = 0
failures = []

for i in range(max_seed):
    print("Running randomized test {i} of {max}...".format(i=i+1, max=max_seed))
    r = subprocess.check_output("./trand {i} | sed 1,2d | sed \\$d".format(i=i), shell=True)
    myr = subprocess.check_output("./mytrand {i} | sed 1,2d | sed \\$d".format(i=i), shell=True)

    if r == myr:
        print("Results are the same! test {i} passed!".format(i=i+1))
        success += 1
    else:
        print("Results are different for seed = {i}!".format(i=i+1))
        failure += 1
	failures.append(1)

print("\nSuccesses: {s}, Failures: {f}".format(s=success, f=failure))
if failure > 0:
    print("Failed on seeds: {seeds}".format(seeds=failures))
