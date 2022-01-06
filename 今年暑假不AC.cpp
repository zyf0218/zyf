#include <stdio.h>
int main(){
	int n,a[100],b[100],t,count;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++)
			scanf("%d %d",&a[i],&b[i]);
		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-1-i;j++){
				if(b[j]>b[j+1]){
					t=a[j],a[j]=a[j+1],a[j+1]=t;
					t=b[j],b[j]=b[j+1],b[j+1]=t;
					}
			}
	t=b[0];
	count=1;
	for(int i=1;i<n;i++){
		if(t<=a[i]){
			count++;
			t=b[i];
		}
    }
    printf("%d\n",count);
	}
	return 0;
}
