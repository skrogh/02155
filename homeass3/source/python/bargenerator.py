## Written by tex.stackexchange user anton

import csv

def make3dhistogram(x, y, z, zmin, output):
    writer = csv.writer(open(output, 'wb'), delimiter=' ')
    i = 0
    for j in range(len(y)):
        writer.writerow((x[i], y[j], zmin))
        writer.writerow((x[i], y[j], zmin))
    for i in range(len(x)-1):        
        writer.writerow((x[i], y[0], zmin))
        for j in range(len(y)-1):
            writer.writerow((x[i], y[j], z[i][j]))
            writer.writerow((x[i], y[j+1], z[i][j]))            
        writer.writerow((x[i], y[len(y)-1], zmin))
        writer.writerow([])
        writer.writerow((x[i+1], y[0], zmin))
        for j in range(len(y)-1):
            writer.writerow((x[i+1], y[j], z[i][j]))
            writer.writerow((x[i+1], y[j+1], z[i][j]))          
        writer.writerow((x[i+1], y[len(y)-1], zmin))
        writer.writerow([])

    i = len(x)-1
    for j in range(len(y)):
        writer.writerow((x[i], y[j], zmin))
        writer.writerow((x[i], y[j], zmin))
