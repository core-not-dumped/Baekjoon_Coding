#include <stdio.h>
#include <memory.h>

void quickSort(int *arr, int left, int right)
{
    int pivot, left_temp, right_temp;
    left_temp = left;
    right_temp = right;
    pivot = arr[left];

    while (left < right) {
        while (arr[right] >= pivot && (left < right))	right--;
        if (left != right)	arr[left] = arr[right];

        while (arr[left] <= pivot && (left < right))	left++;
        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = pivot;
    pivot = left;
    left = left_temp;
    right = right_temp;

    if (left < pivot) quickSort(arr, left, pivot - 1);
    if (right > pivot) quickSort(arr, pivot + 1, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int land[26][26];
	int i, j, k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%1d", &land[i][j]);
	}

	int dan[26][26];
	int danji = 0;
	int home[2000];
	int qH[1300], qV[1300];
	int r, f, h;
	int a, b;
	int H[4] = {1,-1,0,0};
	int V[4] = {0,0,1,-1};
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(dan[i][j] == 0 && land[i][j] == 1)
			{
				memset(qH,0,sizeof(qH));
				memset(qV,0,sizeof(qV));
				qH[0] = i;
				qV[0] = j;
				dan[i][j] = 1;
				h = 1;
				r = 0;
				f = 0;
				
				while(r<=f)
				{
					for(k=0;k<4;k++)
					{
						a = qH[r]+H[k];
						b = qV[r]+V[k];
						if(a<0 || a>=N || b<0 || b>=N)	continue;
						if(dan[a][b] == 0 && land[a][b] == 1)
						{
							dan[a][b] = 1;
							h++;
							f++;
							qH[f] = a;
							qV[f] = b;
						}
					}
					r++;
				}
				
				home[danji] = h;
				danji++;
			}
		}
	}

	quickSort(home,0,danji-1);

	printf("%d\n", danji);

	for(i=0;i<danji;i++)
		printf("%d\n", home[i]);

	return 0;
}
