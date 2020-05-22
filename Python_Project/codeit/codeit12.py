# �� ����� ��ġ�� �ٲ��ִ� helper function
def swap_elements(my_list, index1, index2):
    # ���� �������� �ۼ��� �ڵ带 �ٿ� ��������!
    temp = my_list[index1]
    my_list[index1]=my_list[index2]
    my_list[index2]=temp
    
# �� ���Ŀ��� ���Ǵ� partition �Լ�
def partition(my_list, start, end):
    # ���� �������� �ۼ��� �ڵ带 �ٿ� ��������!
    pivot = end
    bigger = start
    i = start

    while i<pivot:
        if my_list[i]<=my_list[pivot]:
            swap_elements(my_list,i,bigger)
            bigger+=1
        i+=1 

    swap_elements(my_list,bigger,pivot)
    pivot=bigger

    return pivot

    
# �� ����
def quicksort(my_list, start=None, end=None):
    # �ڵ带 �ۼ��ϼ���.
    if start == None and end == None:
        start=0
        end - len(my_list)-1

    if end-start<1:
        return 

    pivot = partition(my_list,start,end)
    quicksort(my_list,start,pivot-1)
    quicksort(my_list,pivot+1,end)

# �׽�Ʈ 1
list1 = [1, 3, 5, 7, 9, 11, 13, 11]
quicksort(list1, 0, len(list1) - 1)
print(list1)

# �׽�Ʈ 2
list2 = [28, 13, 9, 30, 1, 48, 5, 7, 15]
quicksort(list2, 0, len(list2) - 1)
print(list2)

# �׽�Ʈ 3
list3 = [2, 5, 6, 7, 1, 2, 4, 7, 10, 11, 4, 15, 13, 1, 6, 4]
quicksort(list3, 0, len(list3) - 1)
print(list3)