import numpy as np
from matplotlib.pyplot import *

tableau = np.array(@tableau)
x_label = @x_label
y_label = @y_label
graph_name = @graph_name
x = np.array(@x)
y = np.array(@y)
X,Y = np.meshgrid(x,y)
print(np.max(tableau))
print((1/np.max(tableau)))
tableau = (1/np.max(tableau))*tableau
print(np.max(tableau))
print(np.std(tableau))
print(np.mean(tableau))
print(np.median(tableau))

figure(1,figsize=(16,6))
contourf(X, Y, tableau, cmap='jet')
#imshow(tableau, cmap='jet')
xlabel(x_label)
ylabel(y_label)
title(graph_name)
savefig(graph_name + ".eps")

show();
