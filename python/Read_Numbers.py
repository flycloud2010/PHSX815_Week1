#! /usr/bin/env python


import sys
import matplotlib.pyplot as plt

class Create_Histogram:
    
    def __init__(self, file_name):
        self.file_name= file_name

    def Plot(self):
        with open(self.file_name, 'r') as file:
            n = [float(x) for x in file.read().split()]

        plt.hist(n,  50, density=True, facecolor='r', alpha=0.75, label='Random Numbers')

        # plot formating options
        plt.xlabel('x')
        plt.ylabel('Probability')
        plt.title('Uniform random number')
        plt.grid(True)
        plt.legend()
        ax = plt.gca()
        ax.set_ylim([0.8, 1.2])
        # show figure (program only ends once closed
        plt.show()