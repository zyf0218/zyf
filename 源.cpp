#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
typedef struct Node {
	char name[50];
	char sex[20];
	int number;
	int age;
	int score;

	struct Node* next;                         //�����ָ����
}node;

node list;

//�ļ���ȡ
int FILEread(node* L);

//�ļ�����
int FILEsave(node* L);

//��¼����
void welcome();

//����û���Ϣ
void Add(node* L,node s);
void Add_Printf();

//ɾ���û���Ϣ
void Delete_Printf(node* L);    // ����
void Delete(node* y);           // ����

//�޸��û���Ϣ
void Fix(node* L);

//��ѯ�û���Ϣ
void Search(node*L);
node* search_num(node*L,int num);
node* search_Name(node* L,char Name[]);



//����û���Ϣ
void Print(node* L);//����ʵ��
void Print_Printf();//��������


//�����û���Ϣ
void Sort(node* L);

//�˳�����ϵͳ
void Bye();


int main() {
	int i;
	FILEread(&list);
	while (1) {
		welcome();
		scanf("%d", &i);
		switch (i) {
		case 1:
			Add_Printf();     //����û���Ϣ
			break;
		case 2:
			Delete_Printf(&list);           //ɾ���û���Ϣ
			break;
		case 3:
			Fix(&list);                 //�޸��û���Ϣ
			break;
		case 4:
			Search(&list);              //��ѯ�û���Ϣ
			break;
		case 5:
			Print(&list);               //����û���Ϣ
			break;
		case 6:
			Sort(&list);                //�����û���Ϣ
			break;
		case 0:
			Bye();                //�˳�����ϵͳ
			break;
		}
		printf("�Ƿ�������в�����(yes:1 / no:0):");
		scanf("%d", &i);
		if (i == 0) {
			break;
		}
	}
}
//��¼����
void welcome() {
	system("cls");
	printf("******************************************\n");
	printf("****          1.����û���Ϣ          ****\n");
	printf("****          2.ɾ���û���Ϣ          ****\n");
	printf("****          3.�޸��û���Ϣ          ****\n");
	printf("****          4.��ѯ�û���Ϣ          ****\n");
	printf("****          5.����û���Ϣ          ****\n");
	printf("****          6.�����û���Ϣ          ****\n");
	printf("****          0.�˳�����ϵͳ          ****\n");
	printf("******************************************\n");

	printf("��������Ҫ���еĹ��ܣ�");
}

//����û���Ϣ
void Add_Printf() {
	system("cls");
	node st;             
	printf("���������ӵ�ѧ����Ϣ��\n");
	printf("������");
	scanf("%s",st.name);
	printf("�Ա�");
	scanf("%s",st.sex);
	printf("ѧ�ţ�");
	scanf("%d", &st.number);
	printf("���䣺");
	scanf("%d", &st.age);
	printf("������");
	scanf("%d", &st.score);

	Add(&list, st);
}
void Add(node* L, node s) {
	node* p = L;
	node* t = (node*)malloc(sizeof(node));
	*t = s;

	t->next = p->next;
	p->next = t;

	//�ļ�����
	FILEsave(L);

}

//ɾ���û���Ϣ
void Delete_Printf(node* L) {
	system("cls");
	int num;
	printf("��������Ҫɾ����ѧ�ţ�");
	scanf("%d", &num);
	node* d = search_num(L, num);
	node* p;
	p = d;
	if (d == NULL) {
		printf("���û�������\n");
	}
	else {
		d = d->next;
		printf("________________________________________________\n");
		printf("����\t|�Ա�\t|ѧ��\t|����\t|����\t|\n");
		printf("________________________________________________\n");
		printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", d->name, d->sex, d->number, d->age, d->score);
		printf("________________________________________________\n");

		Delete(p);

		FILEsave(L);
	}
}

void Delete(node* y)
{
	node* r=y->next;
	y->next = r->next;
	r->next = NULL;
	free(r);
}
//�޸��û���Ϣ
void Fix(node* L) {
	system("cls");
	int num;
	printf("��������Ҫ�޸ĵ�ѧ�ţ�");
	scanf("%d", &num);
	node* d = search_num(L, num);
	if (d == NULL) {
		printf("���û�������\n");
	}
	else {
		d = d->next;
		int choose;
		while (1)
		{
			system("cls");
			printf("________________________________________________\n");
			printf("����\t|�Ա�\t|ѧ��\t|����\t|����\t|\n");
			printf("________________________________________________\n");
			printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", d->name, d->sex, d->number, d->age, d->score);
			printf("________________________________________________\n");

			printf("****       1.����       ****\n");
			printf("****       2.�Ա�       ****\n");
			printf("****       3.ѧ��       ****\n");
			printf("****       4.����       ****\n");
			printf("****       5.����       ****\n");
			printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
			scanf("%d", &choose);
			switch (choose) {
			case 1:
				printf("������");
				scanf("%s", d->name);
				break;
			case 2:
				printf("�Ա�");
				scanf("%s", d->sex);
				break;
			case 3:
				printf("ѧ�ţ�");
				scanf("%d", &d->number);
				break;
			case 4:
				printf("���䣺");
				scanf("%d", &d->age);
				break;
			case 5:
				printf("������");
				scanf("%d", &d->score);
				break;
			}
			printf("�Ƿ�����޸ģ�(yes:1 / no:0):");
			scanf("%d", &choose);
			if (choose == 0)
			{
				break;
			}
		}
		FILEsave(L);
	}
}

//��ѯ�û���Ϣ
void Search(node* L) {
	system("cls");
	printf("����ѧ�Ų�ѯ --- 1\n");
	printf("����������ѯ --- 2\n");
	printf("�������ѯ��ʽ��");
	int t, num;
	char Name[50];
	scanf("%d", &t);
	node* k;
	if (t == 1) {
		printf("��������Ҫ��ѯ��ѧ�ţ�");
		scanf("%d", &num);
		k = search_num(L, num);
		if (k == NULL) {
			printf("���û�������\n");
		}
		else {
			k = k->next;
			printf("________________________________________________\n");
			printf("����\t|�Ա�\t|ѧ��\t|����\t|����\t|\n");
			printf("________________________________________________\n");
			printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", k->name, k->sex, k->number, k->age, k->score);
			printf("________________________________________________\n");
		}
	}
	else if (t == 2) {
		printf("��������Ҫ��ѯ��������");
		scanf("%s", Name);
		k = search_Name(L, Name);
		if (k == NULL) {
			printf("���û�������\n");
		}
		else {
			k = k->next;
			printf("________________________________________________\n");
			printf("����\t|�Ա�\t|ѧ��\t|����\t|����\t|\n");
			printf("________________________________________________\n");
			printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", k->name, k->sex, k->number, k->age, k->score);
			printf("________________________________________________\n");
		}
	}
}

node* search_num(node * L, int num){
	node* s = L;
	while (s->next != NULL) {
		if (s->next->number == num) {
			return s;
		}
		s = s->next;
	}
	return NULL;
}

node* search_Name(node* L, char Name[]) {
	node* s = L;
	while (s->next != NULL) {
		if (!strcmp(s->next->name,Name)) {
			return s;
		}
		s = s->next;
	}
	return NULL;
}



//����û���Ϣ
void Print(node* L) {
	system("cls");
	node* p = L->next;
	Print_Printf();
	if (p != NULL) {
		while (p != NULL) {
			printf("________________________________________________\n");
			printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", p->name, p->sex, p->number, p->age, p->score);
			printf("________________________________________________\n");
			p = p->next;
		}
	}
}
void Print_Printf() {
	printf("________________________________________________\n");
	printf("����\t|�Ա�\t|ѧ��\t\t|����\t|����\t|\n");
}


//�����û���Ϣ
void Sort(node* L) {
	system("cls");
	int choose;
	printf("****    1.�ɼ�Ϊ����      ****\n");
	printf("****    2.�ɼ�Ϊ����      ****\n");
	printf("��ѡ��˳��");
	scanf("%d", &choose);
	
	int flag = 0;
	for (node* h = L->next; h != NULL; h = h->next) {
		for (node* q = h; q != NULL; q = q->next) {
			switch (choose) {
			case 1:
				if (h->score > q->score)
				{
					flag = 1;
				}
				break;
			case 2:
				if (h->score < q->score)
				{
					flag = 1;
				}
				break;
			}
			if (flag == 1) {
				node temp = *h;
				*h = *q;
				*q = temp;

				temp.next = h->next;
				h->next = q->next;
				q->next = temp.next;

				flag = 0;
			}
		}
	}
	

}
//�˳�����ϵͳ
void Bye() {
	system("cls");
	printf("goodbye!\n");
	exit(0);
}

//�ļ���ȡ
int FILEread(node* L) {
	FILE* fread = fopen("east.text","r");
	if (fread == NULL) {
		return 0;
	}
	node* q=L;
	node* w;
	node h;
	while (fscanf(fread,"%s %s %d %d %d", h.name, h.sex, &h.number, &h.age, &h.score) != EOF) {
		w = (node*)malloc(sizeof(node));
		*w = h;

		q->next = w;
		q=w;
		q->next = NULL;
	}
	return 1;
}

//�ļ�����
int FILEsave(node* L) {
	FILE* fwrite = fopen("east.text", "w");
	if (fwrite == NULL) {
		return 0;
	}
	node* x = L->next;
	while (x!=NULL) {
		fprintf(fwrite,"%s %s %d %d %d ", x->name, x->sex, x->number, x->age, x->score);
		x = x->next;
	}
	return 1;
}