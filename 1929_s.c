main(){int M,N,i,j,c[1000001]={1,1};scanf("%d%d",&M,&N);for(i=2;i*i<=N;i++){if(!c[i]){for(j=2*i;j<=N;j+=i)c[j]=1;}}for(i=M;i<=N;i++)c[i]?:printf("%d\n",i);}
