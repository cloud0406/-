#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct grade {
	int s; //���� ���
	int m; //���� ���
}grade;
grade g[100001];
int main() {
	int t, n,tmp=0,cnt=1,max=0;
	
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) { //�Է� ����
			scanf("%d %d", &g[j].s, &g[j].m);
		}

		for (int j = 0; j < n; j++) { //���� (���� ��� ��)
			for (int q = j; q < n; q++) {
				if (g[j].s > g[q].s) {
					tmp = g[j].s;
					g[j].s = g[q].s;
					g[q].s = tmp;

					tmp = g[j].m;
					g[j].m = g[q].m;
					g[q].m = tmp;
				}
			}
		} //���� ��
		//���� ������ ���� ����� ���캸�� �ռ����� ���� ���� ���� ����� ��� �������ְ�
		//�װͺ��� ��������� ������ ����,���� ���� �Ѵ� ���� ���̹Ƿ� �н�
		//���� ���� ���� �����ϹǷ� cnt �÷��ְ�, ���� ���� ���� ��� ���� ��������
		max = g[0].m; //max-���� ��� �ִ� ����

		for (int j = 1; j < n; j++) {//���� ��� 2����� ��
			if (max > g[j].m) { max = g[j].m; cnt++; }
		}

		printf("%d\n", cnt);
		cnt = 1; //���� ��� 1���� ������ ���ԵǹǷ� 1���� ����
	}

	return 0;
}