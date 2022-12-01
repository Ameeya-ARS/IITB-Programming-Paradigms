list1 = [1,2,3,"f","g",6,3,"s"]

def reverse(l):
    if len(l)==0:
        return []
    else:
        return [l.pop()]+reverse(l)

print (reverse(list1))