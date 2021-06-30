main(x,y,w,h){scanf("%d%d%d%d",&x,&y,&w,&h);x<w-x?:(x=w-x);y<h-y?:(y=h-y);printf("%d\n",x<y?x:y);}
