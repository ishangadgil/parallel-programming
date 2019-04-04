import matplotlib.pyplot as plt
import csv


x = []
y = []

with open('bw5.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.subplot(2, 2, 1)
plt.plot(x,y,label="5 Threads!")
plt.xlabel('Input Size')
plt.ylabel('Time')
plt.title('Busy Wait Implementation')
plt.legend()

x = []
y = []

with open('bw10.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.subplot(2, 2, 2)
plt.plot(x,y,label="10 Threads!")
plt.xlabel('Input Size')
plt.ylabel('Time')
plt.title('Busy Wait Implementation')
plt.legend()

x = []
y = []

with open('bw15.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.subplot(2, 2, 3)
plt.plot(x,y,label="15 Threads!")
plt.xlabel('Input Size')
plt.ylabel('Time')
plt.title('Busy Wait Implementation')
plt.legend()

x = []
y = []

with open('bw20.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.subplot(2, 2, 4)
plt.plot(x,y,label="20 Threads!")
plt.xlabel('Input Size')
plt.ylabel('Time')
plt.title('Busy Wait Implementation')
plt.legend()


plt.show()