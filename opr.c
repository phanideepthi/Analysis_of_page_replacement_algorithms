#include<stdio.h>
 
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0,prs,pgs,c1,c2,calc,l;
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
             for(i=0;i<l;i++)
            {
            
            pages[i]=(rand()%calc)+1;
            printf("%d",pages[i]);
            printf("\n");
    }
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no_of_frames);
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < l; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            flag3 =0;
            
            for(j = 0; j < no_of_frames; ++j){
                temp[j] = -1;
                
                for(k = i + 1; k < l; ++k){
                    if(frames[j] == pages[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            
            for(j = 0; j < no_of_frames; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            
            if(flag3 ==0){
                max = temp[0];
                pos = 0;
                
                for(j = 1; j < no_of_frames; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }                
            }
            
            frames[pos] = pages[i];
            faults++;
        }
        
       printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
        
        
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}

