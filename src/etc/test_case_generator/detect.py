import filecmp
import subprocess
import sys


def main():
    """

    Need:
        sol.cc    ... my solution
        stupid.cc ... naive solution
        gen.cc    ... random input generator

    Usage:
        'python detect.py 200'
        args is a number of trials

    Output:
        out1.txt ... output of sol.exe
        out2.txt ... output of stupid.exe
        test.txt ... generated random case

    """
    print("Compiling 'sol.cc'...")
    subprocess.run(['g++', '-O2', '-DLOCAL', '-std=c++17', 'sol.cc', '-o', 'sol'])
    print("Compiled 'sol.cc'")

    print("Compiling 'stupid.cc'...")
    subprocess.run(['g++', '-O2', '-DLOCAL', '-std=c++17', 'stupid.cc', '-o', 'stupid'])
    print("Compiled 'stupid.cc'")

    print("Compiling 'gen.cc'...")
    subprocess.run(['g++', '-O2', '-DLOCAL', '-std=c++17', 'gen.cc', '-o', 'gen'])
    print("Compiled 'gen.cc'")

    print("Running...")

    for i in range(int(sys.argv[1])):
        subprocess.run('./gen.exe', stdout=open('./test.txt', 'w'))
        subprocess.run('./sol.exe', stdin=open('./test.txt'), stdout=open('./out1.txt', 'w'))
        subprocess.run('./stupid.exe', stdin=open('./test.txt'), stdout=open('./out2.txt', 'w'))
        if not filecmp.cmp('./out1.txt', './out2.txt'):
            print('Wrong answer on test {:<3}'.format(i + 1))
            exit(0)
        else:
            print("test {:<3} : ok".format(i + 1))

if __name__ == '__main__':
    main()
