#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct a {
	int n; //����
	int m; //����
	int angle; //����
}angle;
int main() {
	int arr[101][101] = { 0 };  //��� �迭�� 0(���ٴ� ǥ��), �κ��� ������ ���� �ٲ�
	int A, B,N,M,n,m,num,r,check=0; 
	char op,op2;
	angle a[101]; 

	scanf("%d %d", &A, &B); getchar(); //���� ���� �ް�
	scanf("%d %d", &N, &M); getchar(); 

	for (int i = 0; i < N; i++) {
		scanf("%d %d %c", &n, &m, &op); getchar();
		arr[n][m] = i+1; //�迭�� ��ǥ�� �°� ���° �κ����� ����
		a[i].n = n; a[i].m = m; //����ü���� ��ǥ ����
		if (op == 'N') { a[i].angle = 0; } //���� ���� ����
		else if (op == 'E') { a[i].angle = 90; }
		else if (op == 'S') { a[i].angle = 180; }
		else if (op == 'W') { a[i].angle = 270; }
    }
	for (int i = 0; i < M; i++) {
		scanf("%d %c %d", &num, &op2, &r); getchar();
		for (int j = 0; j < r; j++) {
			if (op2 == 'L') { //���� ȸ��
				a[num-1].angle -= 90; 
				if (a[num - 1].angle < 0) { a[num - 1].angle += 360; }
			}
			else if (op2 == 'R') { //������ ȸ��
				a[num-1].angle += 90; 
				if (a[num - 1].angle == 360) { a[num - 1].angle = 0; }
			}
			else if (op2 == 'F') {//����
				if(a[num-1].angle==0){//N���� ����
					arr[a[num - 1].n][a[num - 1].m] = 0;//�Ű��� ���̹Ƿ� ���� �κ���ġ �����
					a[num - 1].m++; //��ĭ �̵�
					
					if(a[num-1].m>B){ //������ ������ 
						check++; //üũ �÷��ְ�
						printf("Robot %d crashes into the wall",num); //�浹�޽���
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) { //�κ��̶� �浹
						check++;//üũ �������ְ�
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]); //�浹�޽���
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num; //���� �κ���ġ �迭�� ǥ��
				}
				if (a[num - 1].angle == 90) { //E�� ����
					
					arr[a[num - 1].n][a[num - 1].m] = 0;
					a[num - 1].n++;
					
					if (a[num - 1].n > A) {
						check++;
						printf("Robot %d crashes into the wall",num);
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) {
						check++;
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]);
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num;
				}
				if (a[num - 1].angle == 180) { //S�� ����
					arr[a[num - 1].n][a[num - 1].m] = 0;
					a[num - 1].m--;
					if (a[num - 1].m < 1) {
						check++;
						printf("Robot %d crashes into the wall",num);
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) {
						check++;
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]);
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num;
				}
				if (a[num - 1].angle == 270) {//W�� ����
					arr[a[num - 1].n][a[num - 1].m] = 0;
					a[num - 1].n--;
					if (a[num - 1].n < 1) {
						check++;
						printf("Robot %d crashes into the wall",num);
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) {
						check++;
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]);
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num;
				}
			}
		}
		if (check == 0) { continue; } //üũ �״�θ� ��� �ݺ��� ������
		else { break; } //�浹�� ���� ����
	}
	if (check == 0) { printf("OK\n"); } //�̻� ������ ok���
	return 0;
}