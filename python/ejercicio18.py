T=[["gabriela",62,45],["jose",48,52],["rosa",56,35],["matias",49,48]]
for i in range(len(T)):
      suma=0
      for j in range(1,len(T[i])):
            suma+=T[i][j]
      print "Prom ",T[i][0]," ",suma/(len(T[i])-1.0)
arr=[1,2]
for j in range(1,len(T[0])):
      suma=0
      for i in range(len(T)):
            suma+=T[i][j]
      print "prom preg",j,suma/(len(T)-1.0)

