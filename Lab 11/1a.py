#           ack(0,n) -->  n+1
#  m>0:     ack(m,0) -->  ack(m-1,1)
#  m,n>0:   ack(m,n) -->  ack(m-1,ack(m,n-1))

def ack(m,n):
    if m==0:
        return n+1
    elif m>0 and n==0:
        return ack(m-1,1)
    elif m>0 and n>0:
        return ack(m-1, ack(m, n-1))

print("value of ack(0,1) is : ", ack(0,1))
print("value of ack(1,1) is : ", ack(1,1))