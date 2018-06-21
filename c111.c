#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,available,l,count=0,prs,pgs,calc,c1,c2;
printf("\n ENTER THE PROCESS SIZE\n ");
            scanf("%d",&prs);
printf("CHOICE=1 FOR GB TO BYTES");
printf("\n");
printf("CHOICE=2 FOR MB TO BYTE");
printf("\n");
printf("CHOICE=3 FOR KB TO BYTES");
 printf("\n"); 
scanf("%d",&c1);
switch(c1)
 {
 	case 1:
 		prs=(prs*1*10^9);
 	break;
 	case 2:
 		prs=prs*(1*10^6);
 	break;
 	case 3:
 		prs=prs*1000;
 }  

 printf("\n ENTER THE PAGE SIZE\n");
            scanf("%d",&pgs);        
printf("CHOICE=1 FOR GB TO BYTES");
printf("\n");
printf("CHOICE=2 FOR MB TO BYTE");
printf("\n");
printf("CHOICE=3 FOR KB TO BYTES");
printf("\n");
scanf("%d",&c2);

switch(c2)
 {
 	case 1:
 		pgs=pgs*(1*10^9);
 	break;
 	case 2:
 		pgs=pgs*(1*10^6);
 	break;
 	case 3:
 		prs=pgs*(1000);
 }            
            calc=prs/pgs;
            
            printf("ENTER THE TOTAL NUMBER\n");
            scanf("%d",&l);
             for(i=1;i<=l;i++)
            {
            
            a[i]=(rand()%calc)+1;
            printf("%d",a[i]);
            printf("\n");
    }
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no);
for(i=0;i<no;i++)
            frame[i]= -1;
                        j=0;
                        printf("\tref string\t page frames\n");
for(i=1;i<=l;i++)
                        {
                                    printf("%d\t\t",a[i]);
                                    

available=0;
                                    for(k=0;k<no;k++)
if(frame[k]==a[i])
                                                available=1;
                                    if (available==0)
                                    {
                                                frame[j]=a[i];
                                                j=(j+1)%no;
                                                count++;
                                                for(k=0;k<no;k++)
                                                printf("%d\t",frame[k]);
}
                                    printf("\n");
}
                        printf("Page Fault Is %d",count);
                        return 0;
}


