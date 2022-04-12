#include<bits/stdc++.h>
using namespace std;

void FCFS(){

    cout<<"\nYOU ARE RUNNING FIRST COME FIRST SERVE ALGORITHM\n";
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
 
    cout<<"\nEnter Process Burst Time aka DURATION \n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    wt[0]=0;   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
    cout<<endl;
//ADDING PROCESS DYNAMICALLY
cout<<"ENTER NO. OF PROCESSES U WANT TO ADD OR -1 TO EXIT\n";
int temp;
cin>>temp;
if(temp==-1) return;
while(temp--){
    avwt=0,avtat=0;
    i=0;j=0;
  cout<<"ENTER BURST TIME FOR THE PROCESS\n";
  int x=1;
  cin>>bt[n+x-1];
  wt[0]=0;    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n+x;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    //calculating turnaround time
    for(i=0;i<n+x;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    float a,b;
    a=(float)avwt/i;
    b=(float)avtat/i;
    cout<<"\n\nAverage Waiting Time:"<<a;
    cout<<"\nAverage Turnaround Time:"<<b;
    cout<<endl<<endl;
    x++;
}
}

void SJF(){
        cout<<"\nYOU ARE RUNNING SHORTEST JOB FIRST ALGORITHM\n";
           int n,temp,tt=0,min,d,i,j;
      float atat=0,awt=0,stat=0,swt=0;

      cout<<"enter no of process"<<endl;
      cin>>n;
      int a[20],b[20],e[20],tat[20],wt[20];
  
      for(i=0;i<n;i++){
          cout<<"\nEnter arrival time of process "<<" : ";
            cin>>a[i];
      }
      for(i=0;i<n;i++)
      {
          cout<<"\nEnter burst time of process " <<" : ";
            cin>>b[i];
      }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
      min=a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }
      tt=min;
      e[d]=tt+b[d];
      tt=e[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
      }
      atat=stat/n;
      awt=swt/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<i+1<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time

    cout<<endl;
    cout<<"ENTER NO. OF PROCESSES U WANT TO ADD OR -1 TO EXIT\n";
int temp2;
cin>>temp2;
if(temp2==-1) return;
while(temp2--){
    stat=0,swt=0;
    awt=0,atat=0;
int x=1;
n+=x;
cout<<"ENTER ARRIVAL TIME OF PROCESS "<<n<<endl;
cin>>a[n-1];
cout<<"ENTER BURST TIME OF PROCESS "<<n<<endl;
cin>>b[n-1];
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
      min=a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }
      tt=min;
      e[d]=tt+b[d];
      tt=e[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
      }
      atat=stat/n;
      awt=swt/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<i+1<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time

   cout<<endl;
   x++;
}
}

void SRTF(){
    cout<<"\nYOU ARE RUNNING SHORTEST REMAINING TIME FIRST ALGORITHM\n";
    int a[20],b[20],x[20];
    int waiting[20],turnaround[20],completion[20];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"\nEnter the number of Processes: ";  //input
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process " <<i+1<<" : ";  //input
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter brust time of process " <<i+1<<" : ";
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    b[19]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=19;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time = "<<avg/n;
    cout<<"  Average Turnaround time = "<<tt/n<<endl;

    cout<<endl;
cout<<"ENTER NO. OF PROCESSES U WANT TO ADD OR -1 TO EXIT\n";
int temp2;
cin>>temp2;
if(temp2==-1) return;
while(temp2--){
    avg=0,tt=0;
int x1=1;
n+=x1;
cout<<"ENTER ARRIVAL TIME OF PROCESS "<<n<<endl;
cin>>a[n-1];
cout<<"ENTER BURST TIME OF PROCESS "<<n<<endl;
cin>>b[n-1];
    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time = "<<avg/n;
    cout<<"  Average Turnaround time = "<<tt/n<<endl;
x1++;
 
}

}

void PBS(){

    cout<<"\nYOU ARE RUNNING PRIORITY BASED SHEDULING(NON-PREMTIVE) ALGORITHM\n";
    int a[10],b[10],x[10],pr[10]={0};
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;
   cout<<"\nEnter the number of Processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter arrival time of process " <<i+1<<" : ";
      cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter brust time of process " <<i+1<<" : ";
      cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter priority of process "<<i+1<<" : ";
      cin>>pr[i];
    }
    for(i=0;i<n;i++)
        x[i]=b[i];

    pr[9]=-1;
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && pr[i]>pr[smallest] && b[i]>0 )
                smallest=i;
        }
        time+=b[smallest]-1;
        b[smallest]=-1;
        count++;
        end=time+1;
        completion[smallest] = end;
        waiting[smallest] = end - a[smallest] - x[smallest];
        turnaround[smallest] = end - a[smallest];
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<"\t"<<"Priority"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<"\t\t"<<pr[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;

    cout<<endl;
cout<<"ENTER NO. OF PROCESSES U WANT TO ADD OR -1 TO EXIT\n";
int temp2;
cin>>temp2;
if(temp2==-1) return;
while(temp2--){
    avg=0,tt=0;
int x1=1;
n+=x1;
cout<<"ENTER ARRIVAL TIME OF PROCESS"<<n<<endl;
cin>>a[n-1];
cout<<"ENTER BURST TIME OF PROCESS"<<n<<endl;
cin>>b[n-1];
cout<<"ENTER PRIORITY OF PROCESS"<<n<<endl;
cin>>pr[n-1];
for(i=0;i<n;i++)
        x[i]=b[i];

    pr[9]=-1;
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && pr[i]>pr[smallest] && b[i]>0 )
                smallest=i;
        }
        time+=b[smallest]-1;
        b[smallest]=-1;
        count++;
        end=time+1;
        completion[smallest] = end;
        waiting[smallest] = end - a[smallest] - x[smallest];
        turnaround[smallest] = end - a[smallest];
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<"\t"<<"Priority"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<"\t\t"<<pr[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n<<endl;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
x1++;
}
}
void PBS2(){

    cout<<"\nYOU ARE RUNNING PRIORITY BASED SHEDULING(PREMPTIVE) ALGORITHM\n";
    int a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10],p[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

   cout<<"\nEnter the number of Processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
       cout<<"\nEnter arrival time of process " <<i+1<<" : ";
      cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
       cout<<"\nEnter brust time of process " <<i+1<<" : ";
      cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter priority of process "<<i+1<<" : ";
      cin>>p[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    p[9]=-1;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && p[i]>p[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
     cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<"\t"<<"Priority"<<endl;
    for(i=0; i<n; i++)
    {
         cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<"\t\t"<<p[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
   cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
cout<<endl;
cout<<"ENTER NO. OF PROCESSES U WANT TO ADD OR -1 TO EXIT\n";
int temp2;
cin>>temp2;
if(temp2==-1) return;
while(temp2--){
    avg=0,tt=0;
int x1=1;
n+=x1;
cout<<"ENTER ARRIVAL TIME OF PROCESS"<<n<<endl;
cin>>a[n-1];
cout<<"ENTER BURST TIME OF PROCESS"<<n<<endl;
cin>>b[n-1];
cout<<"ENTER PRIORITY OF PROCESS"<<n<<endl;
cin>>p[n-1];
for(i=0; i<n; i++)
        x[i]=b[i];

    p[9]=-1;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && p[i]>p[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
     cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<"\t"<<"Priority"<<endl;
    for(i=0; i<n; i++)
    {
         cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaro und[i]<<"\t\t"<<completion[i]<<"\t\t"<<p[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
   cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;

x1++;
}

}

void RR(){

    cout<<"\nYOU ARE RUNNING ROUND-ROBIN ALGORITHM\n";
    int i,n,time,remain,temps=0,time_quantum;

	int wt=0,tat=0;

	cout<<"Enter the total number of process: "<<endl;
	cin>>n;
	remain=n;
	int at[10];
	int bt[10];
	int rt[10];
	cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;
	for(i=0;i<n;i++)
	{
        cout<<"\nEnter arrival time of process " <<i+1<<" : ";
		cin>>at[i];
        cout<<"\nEnter brust time of process " <<i+1<<" : ";
		cin>>bt[i];
		rt[i]=bt[i];
	}

	cout<<"Enter the value of time QUANTUM: "<<endl;
	cin>>time_quantum;

	cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
		
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
		
			time += time_quantum;
		
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			//Desplaying the result of wating, turn around time:
			printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
			cout<<endl;

			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time: "<<wt*1.0/n<<endl;
	cout<<"Average turn around time: "<<tat*1.0/n<<endl;;

    cout<<endl;
cout<<"ENTER NO. OF PROCESSES U WANT TO ADD OR -1 TO EXIT\n";
int temp2;
cin>>temp2;
if(temp2==-1) return;
while(temp2--){
int x1=1;
n+=x1;

cout<<"\nEnter arrival time of process " <<n<<" : ";
		cin>>at[n-1];
        cout<<"\nEnter burst time of process " <<n<<" : ";
		cin>>bt[n-1];
		rt[i]=bt[n-1];

cout<<"\n\nProcess\t:Turnaround Time:    Waiting Time\n\n";

	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
		
			rt[i]=0;
			temps=1;
		}
		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
		
			time += time_quantum;
		
		}
		if(rt[i]==0 && temps==1)
		{
			remain--;
		printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);

			//cout<<endl;

			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time: "<<wt*1.0/n<<endl;
	cout<<"Average turn around time: "<<tat*1.0/n<<endl;

x1++;
}
}

int main(){

while(1){ 
    cout<<endl;
    cout<<"1.FIRST COME FIRST SERVE:\n";
    cout<<"2.SHORTEST JOB FIRST:\n";
    cout<<"3.SHORTEST REMAINING TIME FIRST\n";
    cout<<"4.PRIORITY BASED SHEDULING(NON-PREMTIVE)\n";
    cout<<"5.PRIORITY BASED SHEDULING (PREMPTIVE)\n";
    cout<<"6.ROUND-ROBIN\n";
    
    cout<<"SELECT ANY SCHEDULING ALGORITHM OR PRESS -1 TO EXIT: \n";
    cout<<endl;

    int n;
    cin>>n;
    if(n==-1) exit(1);
    else{

   switch(n){
       case 1:
               FCFS();
               break;
        case 2:
                SJF();
                break;
        case 3:
                SRTF();
                break;
        case 4:
               PBS();
               break;
        case 5:
               PBS2();
               break;
        case 6:
               RR();
               break;
        
   }
    }
}
}