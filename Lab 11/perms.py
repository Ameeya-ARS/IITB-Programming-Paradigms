def func(l):
    output = []
    if len(l)==1:
        return l
    else:
        for i,let in enumerate(l):
            for b in func(l[:i]+l[i+1:]):
                output = output + [let + b]
    return output

list1 = ['1','2','3','4']
list2 = func(list1)
print(list2)