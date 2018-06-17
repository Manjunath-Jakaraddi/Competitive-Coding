# a = 1
# b = 2
# res = b
# fib = 0
# tog = 0
# while fib<=4000000:
#     fib = a+b
#     a=b
#     b=fib
#     if tog:
#         res = res + fib
#     tog=1-tog
# print res

a = 1
b = 2
res = b
fib = 0
tog = 0
while fib<=4000000:
    fib = a+b
    a=b
    b=fib
    if fib%2==0:
        print fib
        res = res + fib
print res
