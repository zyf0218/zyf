#include <stdio.h>
#include <math.h>

void pardon(int *start,int x,int y);

int main(){
	int n,i,j;
	scanf("%d",&n);
	int m = (int)pow(2,n);
	int a[m][m];
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			a[i][j]=1;
	pardon(&a[0][0],m,m);
	for(i=0;i<m;i++){
		for(j=0;j<m;j++)
			printf("%d ",a[i][j]);
		printf("\n"); 
	}
	return 0;
}

void pardon(int *start,int x,int y){
	int *p,k,row;  //p:每行赦免的第一个位置，k:进行列的右移，row:记录所在行 
	if(x>0){
		for(p=start,row=0;row<x/2;p+=y,row++)  //y：让p换行
			for(k=0;k<x/2;k++)
				*(p+k)=0;
		pardon(start+x/2,x/2,y);   //对右上的方块进行赦免
		pardon(start+y*x/2,x/2,y);  //对左下的方块进行赦免
		pardon(start+(y+1)*x/2,x/2,y);   //对右下的方块进行赦免
	} 
}


