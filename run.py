#!/usr/bin/env python3

# BSD License: SteveGremory, 2021.

import os

# Name of the project, ideally copied from the meson.build file.
project_name = "Something"

# Colors class, just to make my day a little easier.
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    pUNDERLINE = '\033[4m'

# Check If the build Folder Exists
path = './build'
isFile = os.path.exists(path)

# If it does, then just build and run.
if isFile == True:
    print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")
    print(f"{bcolors.WARNING}[BUILD FOLDER EXISTS, RUNNING NOW...]{bcolors.ENDC}\n")
    print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")
# Commands to make the stuff:
    # Delete the old executable
    os.system("rm -rf ./build/" + project_name)
    # Make the new executable
    os.system("ninja -C build")

    # Run the executable
    print(f"{bcolors.HEADER}\n===================={bcolors.ENDC}\n")
    os.system("./build/" + project_name)
    print(f"{bcolors.HEADER}\n===================={bcolors.ENDC}\n")

# If it doesn't, make one.
if isFile == False:
    print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")
    print(f"{bcolors.WARNING}[BUILD FOLDER DOESN'T EXIST, MAKING ONE AND RUNNING NOW...]{bcolors.ENDC}\n")
    print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")
# Commands to do stuff:
    # Make a meson build folder and then make an exec. with ninja.
    os.system("touch meson.build && mkdir src && mkdir include && mkdir build && touch src/main.cpp && touch include/main.hpp")
    meson_build_file = open('meson.build', 'a')
    meson_build_file.write(
    f"""project('{project_name}', ['cpp', 'c'])
incdir = include_directories(
    'include'
)
libs  = []
executable('{project_name}', ['src/main.cpp'], include_directories: incdir, dependencies: libs)
"""
    )
    meson_build_file.close()

    cpp_file = open('src/main.cpp', 'a')
    cpp_file.write(
    """#include <iostream>

int main() {
    std::cout << 60 + 9;
}
    """
    )
    cpp_file.close()

    os.system("meson build && ninja -C build")

    # Run the executable
    print(f"{bcolors.HEADER}\n===================={bcolors.ENDC}\n")
    os.system("./build/" + project_name)
    print(f"{bcolors.HEADER}\n===================={bcolors.ENDC}\n")