# �鲢����Pythonʵ��
# ѧ�ţ�20201050470
# ʱ�临�Ӷȣ�O(nlog(n))

import random

# �鲢�㷨
def merge(left, right):
    result = []
    while len(left) > 0 and len(right) > 0:
        if left[0] <= right[0]:
            result.append(left[0])
            left = left[1:]
        else:
            result.append(right[0])
            right = right[1:]
    result = result + left + right
    return result


# �鲢����
def mergesort(lst):
    if len(lst) <= 1:
        return lst
    mid = len(lst) // 2
    left = mergesort(lst[:mid])
    right = mergesort(lst[mid:])
    return merge(left, right)
# random()���������������
def RandomArray(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(0, 100000))
    return arr


# ����
if __name__ == '__main__':
    n = (int)(input("������鳤�ȣ�"))
    arr=RandomArray(n)
    print("��������\n",arr)
    arr = mergesort(arr)
    print("�ǽ�������\n", arr)











# # ��������ͬ������
# def randlist(m, a, c, x0, n):
#     rlist = [x0]
#     i: int
#     for i in range(n - 1):
#         rlist.append((a * rlist[i] + c) % m)
#     return rlist


# # �鲢�㷨
# def merge(left, right):
#     result = []
#     while len(left) > 0 and len(right) > 0:
#         if left[0] <= right[0]:
#             result.append(left[0])
#             left = left[1:]
#         else:
#             result.append(right[0])
#             right = right[1:]
#     result = result + left + right
#     return result


# # �鲢����
# def mergesort(lst):
#     if len(lst) <= 1:
#         return lst
#     mid = len(lst) // 2
#     left = mergesort(lst[:mid])
#     right = mergesort(lst[mid:])
#     return merge(left, right)


# # ����
# if __name__ == '__main__':
#     tlist = randlist(100, 31, 1, 1, 30)
#     print("��������\n", tlist)
#     tlist = mergesort(tlist)
#     print("�ǽ�������\n", tlist)