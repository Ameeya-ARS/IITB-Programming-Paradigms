# If it is not a sublist, it prints false
# if it is a sublist , it returns start point and end point in main list
# (a,b) a is index of start point and b is index of end point

list1 = [1,2,3,4,2,6]
list2 = [2,6]
list3 = [2,5]

def check(l2, l1):
    for i in range(len(l1)-len(l2)+1):
        for j in range(len(l2)):
            if l1[i+j] != l2[j]:
                break
        else:
            return i, i+len(l2)-1
    return False

print(check(list2,list1))
print(check(list3,list1))