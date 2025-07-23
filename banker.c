#include<stdio.h>
#include<stdlib.h>

int  max[10][10],alloc[10][10],need[10][10],np,nr,avail[10];
void calculate_need() {
    int i, j;
    for(i = 0; i < np; i++)
    for(j = 0; j < nr; j++)
    need[i][j] = max[i][j] - alloc[i][j];
    }

void banker(){
    int i,j,finish[10]={0},safe[10],flag,k=0;

    for(i=0;i<np;i++){
        if(finish[i]==0){
            flag=0;

            for(j=0;j<nr;j++){
                if(need[i][j]>avail[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                finish[i]=1;
                safe[k]=i+1;
                k++;

                for(j=0;j<nr;j++)
                avail[j]+=alloc[i][j];
            i=-1;
            }

        }
    }

    flag=0;
    for(i=0;i<np;i++){
        if(finish[i]==0){
            printf("deadlock\n");
            flag=1;
            break;
        }
    }

    

    if(flag==0){
        printf("safesequence : \n");
        for(i=0;i<np;i++)
        printf("p%d ",safe[i]);
    }
}

void readmatrix(int mat[10][10]) {
    int i, j;
    for(i = 0; i < np; i++)
    for(j = 0; j < nr; j++)
    scanf("%d", &mat[i][j]);
    }
    void display_matrix(int mat[10][10]) {
    int i, j;
    for(i = 0; i < np; i++) {
    for(j = 0; j < nr; j++)
    printf("%d ", mat[i][j]);
    printf("\n");
    }
    }


    int main() {
        int i;
        printf("\nEnter number of processes: ");
        scanf("%d", &np);
        printf("Enter number of resources: ");
        scanf("%d", &nr);
        printf("\nEnter initial allocation matrix:\n");
        readmatrix(alloc);
        printf("\nEnter Max requirement matrix:\n");
        readmatrix(max);
        printf("\nEnter available resources:\n");
        for(i = 0; i < nr; i++)
        scanf("%d", &avail[i]);
        printf("\n****** Entered Data ******\n");
        printf("\nInitial Allocation:\n");
        display_matrix(alloc);
        printf("\nMaximum Requirement:\n");
        display_matrix(max);
        printf("\nAvailable Resources:\n");
        for(i = 0; i < nr; i++)
        printf("%d ", avail[i]);
        printf("\n");
        calculate_need();
        printf("\nNeed Matrix:\n");
        display_matrix(need);
        banker();
        return 0;
        }