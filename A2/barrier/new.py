import matplotlib.pyplot as plt
import numpy as np
import csv


x = []
y = []

with open('pBarrier.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'r', label = "pthread barrier")
plt.xlabel('Number of threads')
plt.ylabel('Time')

x = []
y = []

with open('conVar.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'g', label = "Condition Variable")
plt.xlabel('Number of threads')
plt.ylabel('Time')

x = []
y = []

with open('sema.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'y', label = "Semaphore")
plt.xlabel('Number of threads')
plt.ylabel('Time')

x = []
y = []

with open('busyWait.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'b', label = "Busy Wait")
plt.xlabel('Number of threads')
plt.ylabel('Time')
plt.legend();


plt.title('Comaprison')
plt.show()