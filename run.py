#
# -> COPYRIGHT RiemannOS, 2021
# -> ALL SOURCE CODE is proprietary and hence is PRIVATE PROPERTY
# -> COPYING/STEALING source code WITHOUT CONSENT will result VIOLATION of terms.
#

import os

buildConfiguration = "debug"
ProjectName = "SugarHTTP"


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


print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")

print(f"{bcolors.WARNING}[BUILDING]{bcolors.ENDC}\n")

print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")

os.system("cmake --build build --config "+buildConfiguration+
          " --target clean -- && cd build && make")

print(f"\n{bcolors.HEADER}===================={bcolors.ENDC}\n")

print(f"{bcolors.WARNING}[EXECUTING]{bcolors.ENDC}\n")

print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")

command = os.system("cd build && ./" + ProjectName)

if(command != 0):
    print(f"\n{bcolors.HEADER}===================={bcolors.ENDC}\n")

    print(f"{bcolors.WARNING}[EXECUTION FAILED]{bcolors.ENDC}\n")

    print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")
else:
    print(f"\n{bcolors.HEADER}===================={bcolors.ENDC}\n")

    print(f"{bcolors.WARNING}[EXECUTION FINISHED]{bcolors.ENDC}\n")

    print(f"{bcolors.HEADER}===================={bcolors.ENDC}\n")