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
    data = np.array(loadData('ZADACHA2.txt'))
    x2 = data[:, 0]
    y2 = data[:, 1]
    data = np.array(loadData('Fdelta1.txt'))
    x3 = data[:, 0]
    y3 = data[:, 1]
    data = np.array(loadData('Fdelta2.txt'))
    x4 = data[:, 0]
    y4 = data[:, 1]

    h = float(sys.argv[1].replace(',', '.'))

    plt.figure()
    ax = plt.subplot(211)

    ax.plot(x0, y0, label="точное решение")
    ax.plot(x1, y1, label="метод Эйлера")
    ax.plot(x2, y2, label="метод Эйлера-Кромера")
    ax.legend()
    ax.set_title('Решенное дифференциальное уравнение x\'\' + 2' + r'$\lambda$' + 'x\' + ' + r'$\omega_0$' + 'x = 0 с шагом ' + str(h))
    ax.set_xlabel('t')
    ax.set_ylabel('x(t)')
    ax.grid(True)
    plt.xlim(min(x1), max(x1))

    bx = plt.subplot(212)
    bx.plot(x3, y3, label="погрешность метода Эйлера")
    bx.plot(x4, y4, label="погрешность метода Эйлера-Кромера")
    bx.legend()
    bx.set_title('Погрешность решения дифференциального уравнения x\'\' + 2' + r'$\lambda$' + 'x\' + ' + r'$\omega_0$' + 'x = 0 с шагом ' + str(h))
    bx.set_xlabel('t')
    bx.set_ylabel('x(t) - x(tn)')
    bx.grid(True)
    plt.xlim(min(x1), max(x1))

    plt.show()
    plt.savefig('plot_zadacha.pdf', bbox_inches='tight')




if __name__ == "__main__":
    main()
