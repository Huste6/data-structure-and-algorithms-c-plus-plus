#include <stdio.h>
int n;
void dem(int a[])
{
	int b[n];
	for(int i=0;i<n;i++) b[i]=0;
	int index;int max=0;
	for(int i=0;i<n;i++){
		if(b[i]!=-1){
			int cnt=1;
			b[i]=-1;
			for(int j=i+1;j<n;j++){
				if(a[j]==a[i] && b[j]!=-1){
					cnt++;
					b[j]=-1;
				}
			}
			printf("so %d lap lai %d lan\n",a[i],cnt);
			if(max<cnt){
				max=cnt;
				index=a[i];
			}
		}
	}
	printf("so %d lap lai nhieu lan nhat voi so lan %d",index,max);
}
int main(void) {
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dem(a);
	return 0;
}
