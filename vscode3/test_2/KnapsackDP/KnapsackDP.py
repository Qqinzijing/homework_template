# 0-1������̬�滮Pythonʵ��
# ѧ�ţ�20201050470
# ʱ�临�Ӷ�;O(n*c)
import random
import time
# ��ⱳ��
def bag(n, c, w, v):
    # ���㣬��ʾ��ʼ״̬
    value = [[0 for j in range(c + 1)] for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, c + 1):
            value[i][j] = value[i - 1][j]
            # �������������ŵ�ǰ���壬����ǰһ��״̬�����Ƿ��û�
            if j >= w[i - 1] and value[i][j] < value[i - 1][j - w[i - 1]] + v[i - 1]:
                value[i][j] = value[i - 1][j - w[i - 1]] + v[i - 1]
    for x in value:
        print(x)
    return value
# ���ֵ�����Ž�
def PackageMax(n, c, w, value):
    print('����ֵΪ:', value[n][c])
    x = [False for i in range(n)]
    j = c
    for i in range(n, 0, -1):
        if value[i][j] > value[i - 1][j]:
            x[i - 1] = True
            j -= w[i - 1]
    print("��������װ��ƷΪ:")
    for i in range(n):
        if x[i]:
            print('��', i+1, '��,', end='')

# ���n����Ʒ������
def RandomWeight(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(1, 100))
    return arr

# ���n����Ʒ�ļ�ֵ
def RandomValue(n):
    list = []
    for i in range(n):
        list.append(random.randint(1, 100))
    return list

if __name__ == '__main__':
    n= (int)(input("��Ʒ������"))
    c = (int)(input("�������������"))
    
    w=RandomWeight(n)
    v=RandomValue(n)
    print("��Ʒ������:")
    print(w)
    print("��Ʒ�ļ�ֵ��")
    print(v)
    start_time=time.time()
    value = bag(n, c, w, v)
    PackageMax(n, c, w, value)
    end_time=time.time()
    print("\n����ʱ�䣺",float(end_time-start_time)*1000.0,"ms")




















# # 0-1������̬�滮Pythonʵ��
# # ѧ�ţ�20201050470
# import random
# import time
# def bag(n, c, w, v):
#     # ���㣬��ʾ��ʼ״̬
#     value = [[0 for j in range(c + 1)] for i in range(n + 1)]
#     for i in range(1, n + 1):
#         for j in range(1, c + 1):
#             value[i][j] = value[i - 1][j]
#             # �������������ŵ�ǰ���壬����ǰһ��״̬�����Ƿ��û�
#             if j >= w[i - 1] and value[i][j] < value[i - 1][j - w[i - 1]] + v[i - 1]:
#                  value[i][j] = value[i - 1][j - w[i - 1]] + v[i - 1]#�û�
#     for x in value:
#         print(x)
#     return value

# def show(n, c, w, value):
#     print('����ֵΪ:', value[n][c])
#     x = [False for i in range(n)]
#     j = c
#     for i in range(n, 0, -1):
#         if value[i][j] > value[i - 1][j]:
#             x[i - 1] = True
#             j -= w[i - 1]
#     print('��������װ��ƷΪ:')
#     for i in range(n):
#         if x[i]:
#             print('��', i+1, '��,', end='')

# # def bag1(n, c, w, v):
# #     values = [0 for i in range(c+1)]
# #     for i in range(1, n + 1):
# #         for j in range(c, 0, -1):
# #             # �������������ŵ�ǰ���壬����ǰһ��״̬�����Ƿ��û�
# #             if j >= w[i-1]:
# #                 values[j] = max(values[j-w[i-1]]+v[i-1], values[j])
# #     return values
# def RandomWeight(n):
#     arr = []
#     for i in range(n):
#         arr.append(random.randint(1, 100))
#     return arr

# def RandomValue(n):
#     list = []
#     for i in range(n):
#         list.append(random.randint(1, 100))
#     return list

# if __name__ == '__main__':
#     n= (int)(input("��Ʒ������"))
#     c = (int)(input("�������������"))
#     start_time=time.time()
#     w=RandomWeight(n)
#     v=RandomValue(n)
#     print("��Ʒ������:")
#     print(w)
#     print("��Ʒ�ļ�ֵ��")
#     print(v)
#     # ��ʱ
#     start_time=time.time()
#     value = bag(n, c, w, v)
#     show(n, c, w, value)
#     # ��ʱ����
#     end_time=time.time()
#     print("�㷨����ʱ�䣺",float(end_time-start_time)*1000.0,"ms")