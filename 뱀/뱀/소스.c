#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct tail { //���� ���� ��ġ Ȯ�� ���ؼ�
	int r; //��
	int c; //��
}tail;
typedef struct operation {//���� ��ȯ
	int n;
	char op;
}operation;
int arr[102][102] = { 0 }; //��� �迭 0 - ��� ,�⺻ n*n�迭 �ٲ��� �� 0�� ���� ����Ŵ
tail T[10000];
operation o[100];
int main() {
	int n, k, angle = 90,r,c,l,x,s=0,oidx=0,tidx=0;
	int cnt = 0;
	char op;
	
	scanf("%d", &n); getchar();
	scanf("%d", &k); getchar();

	for (int i = 1; i <= n; i++) { //n x n �迭 �⺻ -2�� �ٲ�
		for (int j = 1; j <= n; j++) {
			arr[i][j] = -2;
		}
	}

	for (int i = 1; i <= k; i++) {//����� 1�� ����
		scanf("%d %d", &r, &c); getchar();
		arr[r][c] = 1;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {// ������ȯ �Է¹ޱ� (����ü�� ���ʴ�� ����)
		scanf("%d %c", &x, &op); getchar();
		o[i].n = x; o[i].op = op;
	}
	//�Է� ��
	r = 1; c = 1; T[s].r = 1;  T[s].c = 1; arr[r][c] = 2; //���� �ִ� ���� 2������
	//r,c�� ���� �Ӹ� �κ��� ����ִ��� ����� ��Ÿ��, T[s]�� ���ʸ��� ���� ������ ����
	while (1) {
		s++; //�� ����
		//�������� ��ĭ �̵� �� ���� üũ
		if (angle == 0) {
			r--;
			T[s].r = r; T[s].c = c; //���� �̵���� ����
			if (arr[r][c] == 0 || arr[r][c] == 2) { break; } //�� �Ǵ� ���뿡 �ε����� ����
			else if (arr[r][c] == 1) { //��� ������
				arr[r][c] = 2;
			}
			else {//��� �ƴҰ��
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //���� �ٿ���
				//���� ������ġ ����Ű�� T[tidx]�̿�, tidx�� �ϳ� �÷��༭ ���ο� ������ġ�� �ٲ�
			}
		}
		else if (angle == 90) {
			c++;
			T[s].r = r; T[s].c = c;
			if (arr[r][c] == 0 || arr[r][c] == 2) { break; }
			else if (arr[r][c] == 1) { //��� ������
				arr[r][c] = 2;
			}
			else {//��� �ƴҰ��
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //���� �ٿ���
			}
		}
		else if (angle == 180) {
			r++;
			T[s].r = r; T[s].c = c;
			if ((arr[r][c] == 0)|| (arr[r][c] == 2)) { break; }
			else if (arr[r][c] == 1) { //��� ������
				arr[r][c] = 2; 
			}
			else {//��� �ƴҰ��
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //���� �ٿ���
			}
		}
		else if (angle == 270) {
			c--;
			T[s].r = r; T[s].c = c;
			if (arr[r][c] == 0 || arr[r][c] == 2) { break; }
			else if (arr[r][c] == 1) { //��� ������
				arr[r][c] = 2;
			}
			else {//��� �ƴҰ��
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //���� �ٿ���
			}
		}

		if (s == o[oidx].n) {// ������ȯ �ؾ��ϴ� �ð��� �Ǹ� ������ȯ����
			if (o[oidx].op == 'D') {// 90������
				angle += 90;
				if (angle == 360) { angle = 0; }
			}
			else {//90�� ����
				angle -= 90;  if (angle < 0) { angle += 360; }
			}
			oidx++;//���� ������ȯ�� ���� oidx �ϳ� �÷���
		}
	}
	printf("%d", s); 
	return 0;
}