# �� ����� ��ġ�� �ٲ��ִ� helper function
def swap_elements(my_list, index1, index2):
    # �ڵ带 �ۼ��ϼ���.
    temp=my_list[index1]
    my_list[index1]=my_list[index2]
    my_list[index2]=temp


# �� ���Ŀ��� ���Ǵ� partition �Լ�
def partition(my_list, start, end):
    # �ڵ带 �ۼ��ϼ���.
    pivot_index = len(my_list)-1
    bigger = start
    i = start
    for j in range(i,end):
        if my_list[j]>=my_list[pivot_index]:
            i+=1
        else:
            swap_elements(my_list,bigger,i)
            bigger+=1
            i+=1
    swap_elements(my_list,pivot_index,bigger)
    temp = pivot_index
    pivot_index=bigger
    bigger=temp
    return pivot_index


# �׽�Ʈ 1
list1 = [4, 3, 6, 2, 7, 1, 5]
pivot_index1 = partition(list1, 0, len(list1) - 1)
print(list1)
print(pivot_index1)

# �׽�Ʈ 2
list2 = [6, 1, 2, 6, 3, 5, 4]
pivot_index2 = partition(list2, 0, len(list2) - 1)
print(list2)
print(pivot_index2)
