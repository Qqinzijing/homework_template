# ���η����쳲�������������Python
# ѧ�ţ�20201050470

def DAC_f(n):
    if n==1 or n==2:
        return 1
    else:
        return DAC_f(n-1)+DAC_f(n-2)

if __name__ == '__main__':
    n = (int)(input("쳲��������г��ȣ�"))
    print("\n���Ϊ:",DAC_f(n))