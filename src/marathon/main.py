import matplotlib
import matplotlib.pyplot as plt


def main():
    iterations = []
    scores = []
    with open('./out.txt') as output_file:
        lines = output_file.readlines()
        for line in lines:
            iteration, score = map(int, line.split())
            iterations.append(iteration)
            scores.append(score)
    plt.plot(iterations, scores)
    plt.show()


if __name__ == '__main__':
    main()
