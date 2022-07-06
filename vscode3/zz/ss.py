import random

def bubble_sort(array):
    for i in range(1, len(array)):
        for j in range(0, len(array)-i):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array


def random_array(n):
    array = []
    for i in range(n):
        array.append(random.randint(0, 100))
    return array


if __name__ == '__main__':
    n = (int)(input("请输入数组长度："))
    array = random_array(n)
    print(bubble_sort(array))