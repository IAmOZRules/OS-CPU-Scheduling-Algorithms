#include <iostream>
#include <algorithm>
using namespace std;

int ab;

typedef struct schedule
{
	string pro_id;
	int at,bt,ct,ta,wt;

	/*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}schedule;

bool compare(schedule a,schedule b)
{
	return a.at < b.at;
}

bool compare2(schedule a,schedule b)
{
	return a.bt < b.bt && a.at <= ab;
}

int main()
{
	schedule pro[10];
	int n,i,j, avg_wt=0, avg_ta=0;

	cout<<"Enter number of programs: "; cin>>n;
	cout<<"Enter Schedule ID, Arrival Time, Burst Time:\n";

	for(i=0;i<n;i++)
		cin >> pro[i].pro_id >> pro[i].at >> pro[i].bt;

	sort(pro,pro+n,compare);

	pro[0].ct = pro[0].bt + pro[0].at;
	pro[0].ta = pro[0].ct - pro[0].at;
	pro[0].wt = pro[0].ta - pro[0].bt;

	for(i=1; i<n; i++)
	{
		ab = pro[i-1].ct;
		sort(pro+i, pro+n, compare2);

		if(pro[i-1].ct<pro[i].at)
			pro[i].ct = pro[i-1].ct + pro[i].bt + (pro[i].at - pro[i-1].ct);

		else
			pro[i].ct = pro[i-1].ct + pro[i].bt;

		pro[i].ta = pro[i].ct - pro[i].at;
		pro[i].wt = pro[i].ta - pro[i].bt;
	}

    cout << "\n" << "ID" << "\t" << "AT" << "\t" << "BT" << "\t"
    << "CT" << "\t" << "TA" << "\t" << "WT" << endl;
		
	for(i=0; i<n; i++)
	{
		cout << pro[i].pro_id << "\t" << pro[i].at << "\t" << pro[i].bt
		<< "\t" << pro[i].ct << "\t" << pro[i].ta << "\t" << pro[i].wt;
		
		cout << endl;
	}
	
	for(i=0; i<n; i++)
	{
	    avg_wt += pro[i].wt;
	    avg_ta += pro[i].ta;
	}
	
	cout << "\nAverage Waiting Time: " << (double(avg_wt))/n << endl;
	cout << "Average Turnaround Time: " << (double(avg_ta))/n;
	return 0;
}
