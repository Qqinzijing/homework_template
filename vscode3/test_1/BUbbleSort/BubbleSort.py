# ð������Pythonʵ��
# ѧ�ţ�20201050470
# ʱ�临�Ӷȣ�O(n^2)
import random
# ð������
def BubbleSort(arr):
    for i in range(len(arr) - 1, 0, -1):  # �������
        for j in range(0, i):  # �������Ҳ��ֵ�Ѿ����򣬲��ٱȽϣ�ÿ�ζ����ٱ�������
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

# def BubbleSort(arr):
#     for i in range(1, len(arr)):
#         for j in range(0, len(arr)-i):
#             if arr[j] > arr[j+1]:
#                 arr[j], arr[j + 1] = arr[j + 1], arr[j]
#     return arr

# �������һ������
def RandomArray(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(0, 100))
    return arr


if __name__ == '__main__':
    n = (int)(input("������鳤�ȣ�"))
    arr = RandomArray(n)
    print(arr)
    print("ð�������\n")
    print(BubbleSort(arr))
