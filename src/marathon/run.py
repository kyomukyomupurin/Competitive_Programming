import subprocess


def main():
    print("Compiling 'main.cc'...")
    subprocess.run(['g++', '-O2', '-DLOCAL', '-std=c++17', 'main.cc'])
    print("Compiled 'main.cc'")
    print("Running 'main.cc'...")
    subprocess.run('./a.exe', stdin=open('./in.txt'))
    print("Plotting...")
    subprocess.run(['python', 'main.py'])


if __name__ == '__main__':
    main()
