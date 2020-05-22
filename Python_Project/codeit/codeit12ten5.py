# �� ����� ��ġ�� �ٲ��ִ� helper function
def swap_elements(my_list, index1, index2):
    temp = my_list[index1]
    my_list[index1] = my_list[index2]
    my_list[index2] = temp

# �� ���Ŀ��� ���Ǵ� partition �Լ�
def partition(my_list, start, end):
    # ����Ʈ �� Ȯ�ΰ� ������ ���� ������ ��ġ Ȯ���� ���� ���� ����
    i = start
    b = start
    p = end

    # �������� ��� ������ �� ������ �ݺ����� ������
    while i < p:
        # i �ε����� ���� ���������� ������ i�� b �ε����� �ִ� ������ ��ȯ�ϰ� b�� 1 ���� ��Ų��
        if my_list[i] <= my_list[p]:
            swap_elements(my_list, i, b)
            b += 1
        i += 1

    # b�� �������� p �ε����� �ִ� ������ �ٲ��ش�
    swap_elements(my_list, b, p)
    p = b

    # pivot�� ���� �ε����� ������ �ش�
    return p

# �� ����
def quicksort(my_list, start, end):
    # base case
    if end - start < 1:
        return

    # my_list�� �� �κ����� �������ְ�,
    # partition ���� pivot�� �ε����� ���Ϲ޴´�
    pivot = partition(my_list, start, end)

    # pivot�� ���� �κ� ����
    quicksort(my_list, start, pivot - 1)

    # pivot�� ������ �κ� ����
    quicksort(my_list, pivot + 1, end)


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