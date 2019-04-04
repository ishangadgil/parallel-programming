import matplotlib.pyplot as plt
import csv


x = []
y = []

with open('bw5.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'r')
plt.xlabel('Input Size')
plt.ylabel('Time')
#plt.title('Busy Wait Implementation')
plt.legend()

x = []
y = []

with open('mutex5.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'b')
plt.xlabel('Input Size')
plt.ylabel('Time')
#plt.title('Busy Wait Implementation')
plt.legend()

x = []
y = []

with open('sem5.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y,'g')
plt.xlabel('Input Size')
plt.ylabel('Time')
#plt.title('Busy Wait Implementation')
plt.legend()

x = []
y = []

with open('serial.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))


plt.plot(x,y,'y')
plt.xlabel('Input Size')
plt.ylabel('Time')
#plt.title('Busy Wait Implementation')
plt.legend()


plt.show()