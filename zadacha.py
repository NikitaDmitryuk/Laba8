import math
import scipy.integrate
import numpy as np
import matplotlib.pyplot as plt
import sys



def loadData(name):
    data = []
    with open(name) as f:
        for line in f:
            data.append([float(x) for x in line.split()])
    return data

def main():
    
    
    data = np.array(loadData('F0.txt'))
    x0 = data[:, 0]
    y0 = data[:, 1]
    data = np.array(loadData('ZADACHA1.txt'))
    x1 = data[:, 0]
    y1 = data[:, 1]

    fig = plt.figure()

    print
    type(fig)
    
    ax = fig.add_subplot(111)
    
    ax.plot(x0, y0, label="точное решение")
    ax.plot(x1, y1, label="метод Эйлера")
    ax.legend()

    ax.set_title('Решенное дифференциальное уравнение x\'\' + 2*Lamda*x\' + omega0*x = 0')
    ax.set_xlabel('t')
    ax.set_ylabel('x(t)')
    ax.grid(True)

    plt.show()

    fig.savefig('plot_zadacha.pdf')


if __name__ == "__main__":
    main()
