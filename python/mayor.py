def mayor(num):
      if num<100:
            return num
      return max(num%100,mayor(num/100))
print mayor(9942636980)
