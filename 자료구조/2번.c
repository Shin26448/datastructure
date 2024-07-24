#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* initNode(char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* findNode(Node* s, char data) {
	if (s == NULL)
		return NULL;
	if (s->data == data)
		return s;

	Node* leftNode = findNode(s->left, data);
	if (leftNode != NULL)
		return leftNode;
	else {
		Node* rightNode = findNode(s->right, data);
		return rightNode;
	}
}

void linkNode(Node* s, char data, char left, char right) {
	Node* currentNode = findNode(s, data);
	if (left != '.')
		currentNode->left = initNode(left);
	if (left != '.')
		currentNode->right = initNode(right);
}

void preorder(Node* s) {
	if (s == NULL)
		return;
	printf("%c", s->data);
	preorder(s->left);
	preorder(s->right);
}

void inorder(Node* s) {
	if (s == NULL)
		return;
	inorder(s->left);
	printf("%c", s->data);
	inorder(s->right);
}

void postorder(Node* s) {
	if (s == NULL)
		return;
	postorder(s->left);
	postorder(s->right);
	printf("%c", s->data);

}


int main() {
	int n;
	char data, left, right;
	scanf("%d", &n);
	getchar();

	Node* root = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%c %c %c", &data, &left, &right);
		getchar();

		if (root == NULL) {
			root = initNode(data);
		}
		linkNode(root, data, left, right);
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");

	postorder(root);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include<string.h>

int top = -1;
char pop(char N[]) {

	char ele = N[top];
	N[top] = '\0';
	top--;

	return ele;

}
void push(char N[], char k) {

	N[++top] = k;

}
int P(char k) {
	if (k == '!') {
		return 6;
	}
	else if (k == '*' || k == '/') {
		return 5;
	}
	else if (k == '+' || k == '-') {
		return 4;
	}
	else if (k == '<' || k == '>') {
		return 3;
	}
	else if (k == '&') {
		return 2;
	}
	else if (k == '|') {
		return 1;
	}
	else { return -1; }
}
void getSymbol(char N[]) {
	top = -1;
	N[0] = '\0';
}
int main() {
	char S[101];// 수식 입력받는 배열
	char N[101];//연산자 담는 배열

	int n, j = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", S);
		j = 0;
		getSymbol(N);
		while (S[j] != '\0') {
			char k = S[j];
			j++;
			if (k >= 'A' && k <= 'Z') {   //k가 영대문자일 때 출력
				printf("%c", k);
			}
			else if (k == '(') { //k가 (일 때 스택에 저장
				push(N, k);

			}
			else if (k == ')') { // k가 )일 때 (나올 때까지 출력하면서 삭제
				while (top != -1 && N[top] != '(') {
					printf("%c", pop(N));
				}
				if (top != -1 && N[top] == '(') { pop(N); }//(가 나오면 pop으로 삭제
			}
			else {
				while (N[0] != '\0' && P(k) <= P(N[top])) {//연산자일 때 우선순위 비교하기
					char temp = N[top];
					if ((N[top] == '&') || (N[top] == '|')) {//top이 &이거나 |일 때 처음부터 출력하면 안됨
						if ((temp == N[top - 1]) && cnt > 0) {//한턴 쉬고 들어가야하므로 cnt로 한턴 쉬기
							printf("%c%c", temp, temp);//N[top]==N[top-1]일 때 출력
							pop(N);
							pop(N);
							cnt = 0;

						}
						else {
							cnt++;
							break;
						}

					}
					else {
						printf("%c", pop(N));
					}
				}
				push(N, k);
			}
		}
		while (top != -1) {
			printf("%c", pop(N));
		}

		printf("\n");
	}



	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int num;
	int idx;
	struct node* next;
} Node;

typedef struct priority {
	Node* head;
} Priority;

void initPriority(Priority* p) {
	p->head = NULL;
}

void enQue(Priority* p, Node* newNode) {
	newNode->next = NULL;

	if (p->head == NULL || p->head->num < newNode->num) {
		newNode->next = p->head;
		p->head = newNode;
	}
	else {
		Node* current = p->head;
		while (current->next != NULL && current->next->num >= newNode->num) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

Node* deQue(Priority* p) {
	if (p->head == NULL) {
		return NULL;
	}

	Node* tmp = p->head;
	p->head = p->head->next;
	tmp->next = NULL;
	return tmp;
}

int findQue(int n, int m, int queue[]) {
	int result;

	Priority p;
	initPriority(&p);

	for (int i = 0; i < n; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->num = queue[i];
		newNode->idx = i + 1;

		enQue(&p, newNode);
	}

	Node* target = NULL;

	for (int i = 0; i <= m; i++) {
		target = deQue(&p);
		if (i != m && target != NULL)
			free(target);
	}

	if (target != NULL) {
		result = target->idx;
		free(target);
	}

	return result;
}

int main() {
	int Qnum;
	scanf("%d", &Qnum);

	for (int i = 0; i < Qnum; i++) {
		int n, m;
		scanf("%d %d", &n, &m);

		int queue[100];
		for (int j = 0; j < n; j++) {
			scanf("%d", &queue[j]);
		}

		int result = findQue(n, m, queue);
		printf("%d\n", result);
	}

	return 0;
}

