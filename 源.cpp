#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
typedef struct Node {
	char name[50];
	char sex[20];
	int number;
	int age;
	int score;

	struct Node* next;                         //链表的指针域
}node;

node list;

//文件读取
int FILEread(node* L);

//文件保存
int FILEsave(node* L);

//登录界面
void welcome();

//添加用户信息
void Add(node* L,node s);
void Add_Printf();

//删除用户信息
void Delete_Printf(node* L);    // 界面
void Delete(node* y);           // 功能

//修改用户信息
void Fix(node* L);

//查询用户信息
void Search(node*L);
node* search_num(node*L,int num);
node* search_Name(node* L,char Name[]);



//输出用户信息
void Print(node* L);//功能实现
void Print_Printf();//操作界面


//排序用户信息
void Sort(node* L);

//退出管理系统
void Bye();


int main() {
	int i;
	FILEread(&list);
	while (1) {
		welcome();
		scanf("%d", &i);
		switch (i) {
		case 1:
			Add_Printf();     //添加用户信息
			break;
		case 2:
			Delete_Printf(&list);           //删除用户信息
			break;
		case 3:
			Fix(&list);                 //修改用户信息
			break;
		case 4:
			Search(&list);              //查询用户信息
			break;
		case 5:
			Print(&list);               //输出用户信息
			break;
		case 6:
			Sort(&list);                //排序用户信息
			break;
		case 0:
			Bye();                //退出管理系统
			break;
		}
		printf("是否继续进行操作？(yes:1 / no:0):");
		scanf("%d", &i);
		if (i == 0) {
			break;
		}
	}
}
//登录界面
void welcome() {
	system("cls");
	printf("******************************************\n");
	printf("****          1.添加用户信息          ****\n");
	printf("****          2.删除用户信息          ****\n");
	printf("****          3.修改用户信息          ****\n");
	printf("****          4.查询用户信息          ****\n");
	printf("****          5.输出用户信息          ****\n");
	printf("****          6.排序用户信息          ****\n");
	printf("****          0.退出管理系统          ****\n");
	printf("******************************************\n");

	printf("请输入您要进行的功能：");
}

//添加用户信息
void Add_Printf() {
	system("cls");
	node st;             
	printf("请输入增加的学生信息：\n");
	printf("姓名：");
	scanf("%s",st.name);
	printf("性别：");
	scanf("%s",st.sex);
	printf("学号：");
	scanf("%d", &st.number);
	printf("年龄：");
	scanf("%d", &st.age);
	printf("分数：");
	scanf("%d", &st.score);

	Add(&list, st);
}
void Add(node* L, node s) {
	node* p = L;
	node* t = (node*)malloc(sizeof(node));
	*t = s;

	t->next = p->next;
	p->next = t;

	//文件保存
	FILEsave(L);

}

//删除用户信息
void Delete_Printf(node* L) {
	system("cls");
	int num;
	printf("请输入你要删除的学号：");
	scanf("%d", &num);
	node* d = search_num(L, num);
	node* p;
	p = d;
	if (d == NULL) {
		printf("该用户不存在\n");
	}
	else {
		d = d->next;
		printf("________________________________________________\n");
		printf("姓名\t|性别\t|学号\t|年龄\t|分数\t|\n");
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
//修改用户信息
void Fix(node* L) {
	system("cls");
	int num;
	printf("请输入你要修改的学号：");
	scanf("%d", &num);
	node* d = search_num(L, num);
	if (d == NULL) {
		printf("该用户不存在\n");
	}
	else {
		d = d->next;
		int choose;
		while (1)
		{
			system("cls");
			printf("________________________________________________\n");
			printf("姓名\t|性别\t|学号\t|年龄\t|分数\t|\n");
			printf("________________________________________________\n");
			printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", d->name, d->sex, d->number, d->age, d->score);
			printf("________________________________________________\n");

			printf("****       1.姓名       ****\n");
			printf("****       2.性别       ****\n");
			printf("****       3.学号       ****\n");
			printf("****       4.年龄       ****\n");
			printf("****       5.分数       ****\n");
			printf("请选择你要修改的信息：");
			scanf("%d", &choose);
			switch (choose) {
			case 1:
				printf("姓名：");
				scanf("%s", d->name);
				break;
			case 2:
				printf("性别：");
				scanf("%s", d->sex);
				break;
			case 3:
				printf("学号：");
				scanf("%d", &d->number);
				break;
			case 4:
				printf("年龄：");
				scanf("%d", &d->age);
				break;
			case 5:
				printf("分数：");
				scanf("%d", &d->score);
				break;
			}
			printf("是否继续修改？(yes:1 / no:0):");
			scanf("%d", &choose);
			if (choose == 0)
			{
				break;
			}
		}
		FILEsave(L);
	}
}

//查询用户信息
void Search(node* L) {
	system("cls");
	printf("按照学号查询 --- 1\n");
	printf("按照姓名查询 --- 2\n");
	printf("请输入查询方式：");
	int t, num;
	char Name[50];
	scanf("%d", &t);
	node* k;
	if (t == 1) {
		printf("请输入您要查询的学号：");
		scanf("%d", &num);
		k = search_num(L, num);
		if (k == NULL) {
			printf("该用户不存在\n");
		}
		else {
			k = k->next;
			printf("________________________________________________\n");
			printf("姓名\t|性别\t|学号\t|年龄\t|分数\t|\n");
			printf("________________________________________________\n");
			printf("%s\t|%s\t|%d\t|%d\t|%d\t|\n ", k->name, k->sex, k->number, k->age, k->score);
			printf("________________________________________________\n");
		}
	}
	else if (t == 2) {
		printf("请输入您要查询的姓名：");
		scanf("%s", Name);
		k = search_Name(L, Name);
		if (k == NULL) {
			printf("该用户不存在\n");
		}
		else {
			k = k->next;
			printf("________________________________________________\n");
			printf("姓名\t|性别\t|学号\t|年龄\t|分数\t|\n");
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



//输出用户信息
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
	printf("姓名\t|性别\t|学号\t\t|年龄\t|分数\t|\n");
}


//排序用户信息
void Sort(node* L) {
	system("cls");
	int choose;
	printf("****    1.成绩为升序      ****\n");
	printf("****    2.成绩为降序      ****\n");
	printf("请选择顺序：");
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
//退出管理系统
void Bye() {
	system("cls");
	printf("goodbye!\n");
	exit(0);
}

//文件读取
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

//文件保存
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