#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))


int partition(int* list, int left, int right)
{
    int pivot = list[left], tmp, low = left, high = right + 1;

    do {
        do
            low++;
        while (low <= right && list[low] < pivot);

        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], tmp);
    } while (low < high);

    SWAP(list[left], list[high], tmp);
    return high;
}
void quick_sort(int* list, int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}//�������� ������

//���� ū���� �����ġ, �� ���� ū���� ������, �������� �ϳ��� ��ġ�س���
//�ᱹ ����������� 0,n,1,n-1,2,n-2...�ε����� ��ġ��
int arr[10001],tmp[10001];
int main() {
	int t, n,cnt=0,idx=0,max=0,fi,ri;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {//�׽�Ʈ ���̽���ŭ �ݺ�
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {//�迭�� �Է¹��� ������� ����
			scanf("%d", &arr[j]);
		}
        quick_sort(arr, 0, n - 1); //�迭 �������� ����
        
        fi = 0; ri = n - 1;//fi-ù��° �ε��� ri-������ �ε���
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) { tmp[fi] = arr[j]; fi++; } //¦�� �ε����� �տ�������
            else { tmp[ri] = arr[j]; ri--; } //Ȧ�� �ε����� �ڿ������� ��ġ
        }
    
        for (int j = 0; j < n-1; j++) {//�տ��� ���� ������� ���̰���
            if (tmp[j] > tmp[j + 1]) {
                if (tmp[j] - tmp[j + 1] > max) max = tmp[j] - tmp[j + 1];
            }
            else { if (tmp[j + 1] - tmp[j] > max) max = tmp[j + 1] - tmp[j]; }
        }

        //�������� ó���� ������ �ε��� ���̺�
        if (tmp[0] > tmp[n - 1]) { if (tmp[0] - tmp[n - 1] > max) max = tmp[0] - tmp[n - 1]; }
        else { if (tmp[n - 1] - tmp[0] > max) max = tmp[n - 1] - tmp[0]; }

        printf("%d\n", max);
        max = 0;
	}
    return 0;
}