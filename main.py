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
    fontsize = 14
    
    data = np.array(loadData('EULER.txt'))
    x0 = data[:, 0]
    y0 = data[:, 1]
    data = np.array(loadData('MOD_EULER.txt'))
    x1 = data[:, 0]
    y1 = data[:, 1]
    data = np.array(loadData('IMPR_EULER.txt'))
    x2 = data[:, 0]
    y2 = data[:, 1]
    data = np.array(loadData('RUNGE_KUTTA.txt'))
    x3 = data[:, 0]
    y3 = data[:, 1]
    data = np.array(loadData('TOCH.txt'))
    x4 = data[:, 0]
    y4 = data[:, 1]

    h = float(sys.argv[1].replace(',', '.'))

    plt.rcParams.update({'font.size': 10})
    fig = plt.figure()
    ax = fig.add_subplot(111)

    ax.plot(x4, y4, '-', label="точное решение")
    ax.plot(x0, y0, 'x:', label="метод Эйлера")
    ax.plot(x1, y1,'--', label="модифицированный метод Эйлера")
    ax.plot(x2, y2,'-.', label="усовершенствованный метод Эйлера")
    ax.plot(x3, y3,':', label="метод Рунге-Кутта")
    ax.legend()
    ax.set_title('Решенное дифференциальное уравнение u\' = 2(x^4 + u)/x с шагом ' + str(h))
    ax.set_xlabel('x', fontsize=fontsize)
    ax.set_ylabel('u(x)', fontsize=fontsize)
    ax.grid(True)
    plt.show()
    fig.savefig('plot h = ' + str(h) + '.pdf', bbox_inches='tight')




if __name__ == "__main__":
    main()
