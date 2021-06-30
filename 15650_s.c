int N,M,n[9];p(int w, int s){int i;if(w==M){for(i=0;i<M;i++)printf("%d ", n[i]);printf("\n");return;}for(i=s+1;i<N+1;i++){n[w]=i;p(w+1,i);}}main(){scanf("%d %d",&N,&M);p(0,0);}
