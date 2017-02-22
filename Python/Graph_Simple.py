from numpy import *
from matplotlib.pyplot import *

tableau = array(@tableau)
x_label = @x_label
y_label = @y_label
graph_name = @graph_name

figure(1,figsize=(16,6))
plot(tableau[:, 0], tableau[:, 1])
xlabel(x_label)
ylabel(y_label)
title(graph_name)

savefig(graph_name + ".eps")
show();
