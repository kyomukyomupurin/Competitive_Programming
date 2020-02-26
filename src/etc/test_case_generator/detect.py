import filecmp
import subprocess
import sys

import colorama
from termcolor import colored, cprint


def main():
    colorama.init()
    print("Compiling 'sol.cc'...")
    subprocess.run(
        ['g++', '-O2', '-DLOCAL', '-std=c++17', 'sol.cc', '-o', 'sol'])
    print("Compiled 'sol.cc'")

    print("Compiling 'stupid.cc'...")
    subprocess.run(['g++', '-O2', '-DLOCAL', '-std=c++17',
                    'stupid.cc', '-o', 'stupid'])
    print("Compiled 'stupid.cc'")

    print("Compiling 'gen.cc'...")
    subprocess.run(
        ['g++', '-O2', '-DLOCAL', '-std=c++17', 'gen.cc', '-o', 'gen'])
    print("Compiled 'gen.cc'")

    print("Running...")

    for i in range(int(sys.argv[1])):
        subprocess.run('./gen.exe', stdout=open('./test.txt', 'w'))
        subprocess.run('./sol.exe', stdin=open('./test.txt'),
                       stdout=open('./out1.txt', 'w'))
        subprocess.run('./stupid.exe', stdin=open('./test.txt'),
                       stdout=open('./out2.txt', 'w'))
        if not filecmp.cmp('./out1.txt', './out2.txt'):
            print("[test {:<3}] : ".format(i + 1), end="")
            cprint("WA", "yellow")
            print('Wrong answer on test {:<3}'.format(i + 1))
            print('------------------------------------------------\n')
            with open('./test.txt', 'r') as corner_case:
                lines = corner_case.readlines()
                for line in lines:
                    print(line)
            print('------------------------------------------------')
            exit(0)
        else:
            print("[test {:<3}] : ".format(i + 1), end="")
            cprint("AC", "green")


if __name__ == '__main__':
    main()
