result = []
def cross(l1,l2):
    if len(l2)==0:
        print(result)
    else:
       for i in l1:
           result.append("(%s*%s)" %(i,l2[0]))
       cross(l1,l2[1:])

list1 = [1,2,3]
list2 = [4,5,6]
cross(list1,list2)