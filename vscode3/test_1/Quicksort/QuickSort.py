# # ��������ͬ������
# def randlist(m, a, c, x0, n):
#     arr = [x0]
#     i: int
#     for i in range(n - 1):
#         arr.append((a * arr[i] + c) % m)
#     return arr


# ��������pythonʵ��
# ѧ�ţ�20201050470
# ʱ�临�Ӷȣ�O(nlog(n))
import random

def RandomArray(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(-100000, 100000))
    return arr

# ��������ͬ������
# def randlist(m, a, c, x0, n):
#     arr = [x0]
#     i: int
#     for i in range(n - 1):
#         arr.append((a * arr[i] + c) % m)
#     return arr


# ��������
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = [i for i in arr[1:] if i <= pivot]
    right = [i for i in arr[1:] if i > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)


# �����㷨
if __name__ == '__main__':
    n = (int)(input("������鳤�ȣ�"))
    # arr=randlist(100000, n, 0, 0, n)
    arr = RandomArray(n)
    print(arr)
    print(quick_sort(arr))