//FCFS
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int pid[10]={0},bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0},rt[10]={0};
    int n,sum=0,temp;
    float totalTAT=0,totalWT=0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("\nEnter  processes: arrival time  and burst time: \n");
    for (int i=0;i<n;i++)
    {
        printf("Enter  processes id :");
        scanf("%d",&pid[i]);
        printf("Enter  processes[%d] arrival time:",pid[i]);
        scanf("%d",&at[i]);
        printf("Enter  processes[%d] burst time:",pid[i]);
        scanf("%d",&bt[i]);
        printf("\n");
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[i] > at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

    temp=0;
    for(int j=0;j<n;j++)
    {
        if(temp >= at[j])
        {
            ct[j]=temp+bt[j];
            temp=temp+bt[j];
        }
        else{
            temp=at[j];
            ct[j]=temp+bt[j];
            temp=temp+bt[j];
        }
    }
    for(int k=0;k<n;k++)
    {
        tat[k]=ct[k]-at[k];
        totalTAT+=tat[k];
    }
    for(int k=0;k<n;k++)
    {
        wt[k]=tat[k]-bt[k];
        totalWT+=wt[k];
    }
    for(int k=0;k<n;k++)
    {
        rt[k]=tat[k]-bt[k];
    }
    printf("---------------TABLE:----------------\n");
    printf("PID\t AT\t Bt\t CT\t TAT\t WT\t RT\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t %d\t %d\t %d\t %d\t     %d\t %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
    printf("Average WT = %f\n\n",totalWT/n);
}


//SJF
#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
   int temp=*x;
  *x=*y;
  *y=temp;
}
void sortat(int p[], int at[], int bt[], int n)
{
  int i, j;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(at[i]>at[j])
      {
        swap(&p[i], &p[j]);
        swap(&at[i], &at[j]);
        swap(&bt[i], &bt[j]);
      }
      else if(at[i]==at[j])
      {
          if(bt[i]>bt[j])
          {
            swap(&p[i], &p[j]);
            swap(&at[i], &at[j]);
            swap(&bt[i], &bt[j]);
          }
      }
    }
  }
}
void tatwt( int ct[], int at[], int bt[], int tat[], int wt[], int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
  }
}

int main()
{
  int p[20], at[20], bt[20], tat[20], wt[20], ct[20], pos, i, j, min=1000, n;
  float awt=0, atat=0;
  printf("Enter the total number of process:- ");
  scanf("%d", &n);
  printf("Enter the each process id:- ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the arrival time of each process:- ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
  }
  printf("Enter the burst time of each process:- ");
  for(i=0;i<n;i++)
  {
     scanf("%d",&bt[i]);
  }
  sortat(p, at, bt, n);
  ct[0]=at[0] + bt[0];
  for(i=1; i<n; i++)
  {
    for(j=i; j<n; j++)
    {
      if(at[j]<=ct[i-1])
      {
        if(bt[j]<min)
        {
          min=bt[j];
          pos=j;
        }
      }
    }
    ct[i]=ct[i-1]+bt[i];
  }
  tatwt(ct, at, bt, tat, wt, n);
  printf("\np\t at\t bt\t ct\t tat\t wt");
  for(i=0;i<n;i++)
  {
    printf("\nP[%d]\t %d\t %d\t %d\t %d\t %d",p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
  }
  for(i=0;i<n;i++)
  {
    atat+=tat[i];
    awt+=wt[i];
  }

  atat=atat/n;
  awt=awt/n;
  printf("\n avg tat=%f and avg wt=%f\n",atat, awt);

  return 0;
}