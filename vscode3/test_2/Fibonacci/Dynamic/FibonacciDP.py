# 쳲��������ж�̬�滮
# ѧ�ţ�20201050470
# ʱ�临�Ӷȣ�O(n)

def DP_f(n):
    f=[]
    for i in range(n):
        if i==0:
            f.append(0)
        elif i==1:
            f.append(1)
        else:
            f.append(f[i-1]+f[i-2])
    return f

if __name__ == '__main__':
    n = (int)(input("쳲��������г��ȣ�"))
    print("\n���Ϊ��",DP_f(n))