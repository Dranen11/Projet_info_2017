from numpy import *
from matplotlib.pyplot import *

tableau = array(@tableau)
x_label = @x_label
y_label = @y_label
graph_name = @graph_name
x = array(@x)
y = array(@y)
X,Y = meshgrid(x,y)
tableau = tableau/np.max(tableau)


figure(1,figsize=(16,6))
contourf(X, Y, tableau, 8, alpha=.75, cmap='jet')
xlabel(x_label)
ylabel(y_label
title(tableau)

savefig(graph_name + ".eps")
show();