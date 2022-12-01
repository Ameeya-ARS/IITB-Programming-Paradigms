#           ack(0,n) -->  n+1
#  m>0:     ack(m,0) -->  ack(m-1,1)
#  m,n>0:   ack(m,n) -->  ack(m-1,ack(m,n-1))

count = dict()
value = dict()

def ack(m, n):
    while(m>=0 and n>=0):
        if m==0:
            a = "(0,%s)" %n
            if a in count:
                count[a] = count[a]+1
            else:
                count[a] = 1
            return n+1
        elif (m>0 and n==0):
            b = "(%s,1)" %(m-1)
            if b in value:
                return value[b]
            else:
                value[b] = ack(m-1,1)
                return value[b]
        elif (m>0 and n>0):
            a = "(%s,%s)" %(m,n)
            if a in count:
                count[a] = count[a]+1
            else:
                count[a]=1
            c = ack(m,n-1)
            b = "(%s,%s)" %(m-1,c)
            if b in value:
                return value[b]
            else:
                value[b] = ack(m-1, c)
                return value[b]

print(ack(3,4))

total = 0
for key in list(count.keys()):
    print("ack", key ,": called ", count[key]," times")
    total = total + count[key]

print("Total calls made : ", total)