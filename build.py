#!/usr/bin/env python3

# A small script to compile code for Project Euler.
# Example: src/problem1.cpp => bin/problem1

import sys
import os
import glob
import subprocess
import logging
import time
import math

def compile_file(path):
    filename = os.path.basename(path)

    source_path = "src/{}".format(filename)
    bin_path = "bin/{}".format(filename)

    print("Compiling '{}' into '{}'".format(source_path, bin_path))

    command = "g++ -std=c++11 -Wall -Werror {0} -o {1}".format(source_path, bin_path)
    p = subprocess.Popen(command.split(" "), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    p.communicate()

# Runs 'compile_file' on every file with certain extension in a directory
def compile_directory(directory, ext):
    files_compiled = 0
    start = time.time()

    print("Compiling directory '{}'".format(directory))
    for root, dirs, files in os.walk(directory):
        for name in files:
            if name.split(".")[-1] == ext:
                full_file_path = os.path.abspath(name)
                compile_file(full_file_path)
                files_compiled += 1
    end = time.time()
    delta = math.ceil(end - start)
    print("Compiled {} files in {} seconds".format(files_compiled, delta))

def main():
    source_dir = os.path.join(os.getcwd(), "src/")
    compile_directory(source_dir, "cpp")


if __name__ == "__main__":
    main()


