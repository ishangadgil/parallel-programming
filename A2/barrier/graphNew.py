import matplotlib.pyplot as plt
import csv


x = []
y = []

with open('sema.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'r')
plt.xlabel('Number of threads')
plt.ylabel('Time')
plt.title('Semaphore Implementation')
plt.legend()



plt.show()