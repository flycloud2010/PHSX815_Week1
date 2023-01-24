#! /usr/bin/env python


import sys
import matplotlib.pyplot as plt

class Create_Histogram:
    
    def __init__(self, file_name):
        self.file_name= file_name

    def Plot(self):
        with open(self.file_name, 'r') as file:
            n = [float(x) for x in file.read().split()]

        plt.hist(n,  50, density=True, facecolor='g', alpha=0.75)

        # plot formating options
        plt.xlabel('x')
        plt.ylabel('Probability')
        plt.title('Uniform random number')
        plt.grid(True)

        # show figure (program only ends once closed
        plt.show()