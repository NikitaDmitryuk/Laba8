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
    
    
    data2 = np.array(loadData('result.txt'))
    x2 = data2[:, 0]
    y2 = data2[:, 1]

    fig = plt.figure()

    print
    type(fig)
    
    ax = fig.add_subplot(111)
    
    ax.plot(x2, y2, label="u\' = 2(x^4 + u)/x")
    ax.legend()

    ax.set_title('Решенное дифференциальное уравнение')
    ax.set_xlabel('x')
    ax.set_ylabel('u(x)')
    ax.grid(True)

    fig.savefig('plot.pdf')


if __name__ == "__main__":
    main()
