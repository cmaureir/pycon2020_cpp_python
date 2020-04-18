import time
from glob import glob
from pathlib import Path
from fastglob import glob as fglob
import subprocess

def benchmark(opt, recursive=False):
    print(f"{opt:5s}: ", end="")
    mode = "r" if recursive else "n"
    start = time.time()
    if opt == "glob":
        a = glob("data/**", recursive=recursive)
    elif opt == "Path":
        if mode == "r":
            a = list(Path("data").glob("**/*"))
        else:
            a = list(Path("data").glob("**"))
    elif opt == "fglob":
        a = glob("data", recursive=recursive)
    total = time.time() - start
    print(f"{total:.5f}s")

print("Recursive")
benchmark("glob", recursive=True)
benchmark("Path", recursive=True)
benchmark("fglob", recursive=True)
print("-" * 40)
print()
print("Non recursive")
benchmark("glob", recursive=False)
benchmark("Path", recursive=False)
benchmark("fglob", recursive=False)
print("-" * 40)
