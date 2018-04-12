#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

void RRWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];
	int t = 0;
	while (1)
	{
		bool done = true;
		for (int i = 0 ; i < n; i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false;
				if (rem_bt[i] > quantum)
				{   t += quantum;
                    rem_bt[i] -= quantum;
                }
				else
				{   t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}}}
		if (done == true)
		break;
	}
}

  void FCFSWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
    wt[i] =  bt[i-1] + wt[i-1] ;
}

void PRIOWaitingTime(int proc[], int n,int bt[],int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}

void RRTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		{tat[i] = bt[i] + wt[i];}
}

void PRIOTurnAroundTime(int proc[],int n,int bt[],int wt[],int tat[])
{
    int total_wt,total_tat;
    printf("\nProcesses   Burst time   Waiting time   Turn around time\n");

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("  %d \t\t %d \t\t %d \t\t %d \t\t ",proc[i],bt[i],wt[i],tat[i]);
    }

    printf("Average waiting time = %f ",(float)total_wt / (float)n);
	printf("\nAverage turn around time = %f ",(float)total_tat / (float)n);
}

void FCFSTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void RRavgTime(int processes[], int n, int bt[],int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    RRWaitingTime(processes, n, bt, wt, quantum);

    RRTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes  Burst time  Waiting time  Turn around time \n");

    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d  \t\t %d \t\t %d \n",bt[i],wt[i],tat[i]);

    }

    printf("Average waiting time = %f", (float)total_wt/(float)n);
    printf("\nAverage turn around time = %f ",(float)total_tat/(float)n);
}

void FCFSavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

     FCFSWaitingTime(processes, n, bt, wt);
     FCFSTurnAroundTime(processes, n, bt, wt, tat);
	printf("Processes  Burst time  Waiting time  Turn around time \n");
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d  \t\t %d \t\t %d \n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f ",(float)total_tat /  (float)n);
}

void PRIOavgTime(int proc[], int n,int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    PRIOWaitingTime(proc,n,bt,wt);

    PRIOTurnAroundTime(proc,n,bt,wt,tat);

    printf("\nProcesses   Burst time  Waiting time   Turn around time\n");

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("  %d\t\t  %d\t\t  %d\t\t  %d\t\t \n ",proc[i],bt[i],wt[i],tat[i]);
    }

    printf("\nAverage waiting time = %f",(float)total_wt / (float)n);
    printf("\nAverage turn around time = %f",(float)total_tat / (float)n);
}
void RR(int processes[],int nm,int burst_time[],int quantum)
{
    int n = sizeof processes / sizeof processes[0];
    RRavgTime(processes, nm, burst_time, quantum);
}
void FCFS(int processes[],int mn,int burst_time[])
{
    int n = sizeof processes / sizeof processes[0];
    FCFSavgTime(processes, mn, burst_time);
}
void PRIO(int processes[],int mn,int burst_time[])
{
    int n = sizeof processes / sizeof processes[0];
    PRIOavgTime(processes, mn, burst_time);
}

int main()
{   int p[20],bt[20],tempri[20],priority[20],i, k, m, temp,q1bt[20],q2bt[20],q3bt[20],q1pri[20], q1wt[20],q1tat[20],
        q2pri[20], q2wt[20],q2tat[20],q2p[20],q3pri[20], q3wt[20],q3tat[20],q1p[20],q3p[20],nq1=0,nq2=0,nq3=0;
        char a;
        int ch;
    float wtavg, tatavg;
    printf("Enter the number of processes --- ");
    scanf("%d",&m);
    p[m];

for(i=0;i<m;i++)
{
p[i] = i;
printf("Enter the Burst Time of Process %d --- ", i);
scanf("%d",&bt[i]);
printf("Enter the priority of the process between range (1-9) --- ");
scanf("%d",&priority[i]);
if(1<= priority[i]<=3)
{
    printf("\n 1#####  \n");
    nq1++;
}
else if(4<=priority[i]<=6)
{    printf("\n 22####  \n");

    nq2++;
}
else if(7<=priority[i]<=9)
{    printf("\n 3#####  \n");

    nq3++;
}
}
q1p[nq1];
q2p[nq2];
q3p[nq3];

for(i=0;i<m;i++)
{
    if(1<=priority[i]<=3)
    {
        int j;
        for(j=0;j<nq1+1;j++)
        {
            q1p[j]=i;
            q1bt[j]=bt[i];
            q1pri[j]=priority[i];
        }
    }
    else if(4<=priority[i]<=6)
    {
        int j;
        for(j=0;j<nq2+1;j++)
        {
            q2p[j]=i;
            q2bt[j]=bt[i];
            q2pri[j]=priority[i];
        }
    }
    else if(7<=priority[i]<=9)
    {
        int j;
        for(j=0;j<nq3+1;j++)
        {
            q3p[j]=i;
            q3bt[j]=bt[i];
            q3pri[j]=priority[i];
            printf("%d  hello world",q3p[i]);
        }
    }
}


do{
    printf("\nPress 1 for Applying Round Robbin on Highest ranged priority ");
    printf("\nPress 2 for Applying Priority Scheduling on Middle ranged priority ");
    printf("\nPress 3 for Applying First Come First Serve on Lowest ranged priority");
    printf("\nPress 4 for Applying Round Robbing of quant 10 seconds on the whole structure ");
    cin>>ch;
    switch(ch)
    {
        case 1: RR(q1p,nq1,q1bt,4);break;
        case 2: PRIO(q2p,nq2,q2bt);break;
        case 3: FCFS(q3p,nq3,q3bt); break;
        default: printf("\n Enter valid choice");
    }
        printf("\n Press Y/y to continue and any other key to exit");
        scanf("%c",&a);
    }while(a=='y' || a=='Y');
    printf("\n Exiting");
    getch();
    return 0;
}
