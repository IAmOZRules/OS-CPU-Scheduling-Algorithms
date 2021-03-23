#include<iostream>
 
using namespace std;
 
int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    cout<<"Enter number of Processes: "; cin>>n;
 
    cout<<"\nEnter Process Burst Time in order: ";
    for(i=0;i<n;i++)
        cin>>bt[i];
 
    wt[0]=0;
    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    cout<<"\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
 
    avwt = (double(avwt))/n;
    avtat = (double(avtat))/n;
    
    cout << "\n\nAverage Waiting Time: "<< avwt;
    cout << "\nAverage Turnaround Time: "<< avtat;
 
    return 0;
}