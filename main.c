#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mCreation();
void Sortir(int*,int);
void merge(int*,int*,int*,int,int);

int na=0, nb=0;
int *mA,*mB,*mC;

int main()
{
	mCreation();
	Sortir(mA,na);
	Sortir(mB,nb);
	merge(mA,mB,mC,na,nb);		
	return 0;
}

void mCreation()
{
	srand(time(NULL));
	int i,j,*m,num;
	num = rand() % 15 +6;
	if(!(m=(int*)malloc(num*sizeof(int)))) printf("Not enough memory techarrray!");
	for(i=0;i<num;i++) m[i]= rand() % 21 -10;
	na=rand() % (num-3)/3 +3;
	nb=num-na;
	if(!(mA=(int*)malloc(na*sizeof(int)))) printf("Not enough memory for Array A!");
	if(!(mB=(int*)malloc(nb*sizeof(int)))) printf("Not enough memory for Array B!");
	for (i=0;i<na;i++) mA[i]=m[i];
	for (i=na,j=0;j<nb;j++,i++) mB[j]=m[i];
}

void Sortir(int *m, int n)
{
	int i=0,j,min=m[0],pos,tmp=0;
	for(i=0;i<n;i++)
	{
		j=i;
		min=m[j];
		while (j<n)
		{
			if(m[j]<min)
			{
				pos=j;
				min=m[j];
				tmp=1;
			}
			j++;
		}
		if(m[pos]<m[i] && tmp==1)
		{
			tmp=m[i];
			m[i]=m[pos];
			m[pos]=tmp;
			tmp=0;
		}
		if(tmp==0) continue;
	}
}

void merge(int *mA, int *mB, int *mC, int na, int nb)
{
	int i,ja=0,jb=0;
	if(!(mC=(int*)malloc((na+nb)*sizeof(int)))) printf("Not enough memory!");
	
	for(i=0;i<(na+nb);i++)
		{
			
			if (ja<na && jb<nb)
			{
				if (mA[ja]==mB[jb])
				{
					mC[i]=mA[ja];
					mC[i+1]=mB[jb];
					ja++;
					jb++;
					i++;
					continue;
				}
				if(mA[ja]<mB[jb]) 
				{
					mC[i]=mA[ja];
					ja++;
					continue;
				}
				if(mB[jb]<mA[ja]) 
				{
					mC[i]=mB[jb];
					jb++;
					continue;
				}
			}
			else 
			{
				if(ja<na)
				{
					for(;ja<na;ja++) 
					{
						mC[i]=mA[ja];
						i++;
					}
				}
				if(jb<nb) 
				{
					for(;jb<nb;jb++) 
					{
						mC[i]=mB[jb];
						i++;
					}
				}	
			}	
		}

	printf("Array A: ");
	for(i=0;i<na && printf("%d ", mA[i]);i++);
	printf("\nArray B: ");
	for(i=0;i<nb && printf("%d ", mB[i]);i++);
	printf("\nArray C: ");
	for(i=0;i<(na+nb) && printf("%d ", mC[i]);i++);
	printf("\nNumber of items in Array C: %d",i);
	FILE *fout=fopen("arrc.txt","w");
	for(i=0;i<(na+nb) && fprintf(fout, "%d ", mC[i]);i++);
	fclose(fout);
}
