#include<stdio.h>
 
int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}
 
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0,c1,c2,calc,prs,pgs;
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
            
           printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
             for(i=0;i<no_of_pages;i++)
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
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}
