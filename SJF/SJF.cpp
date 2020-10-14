#include <iostream>
#include<iomanip>
#define MAX 100

using namespace std;

class SJF
{
  public:
    string unit;
    int pid[MAX];
    float bt[MAX];
    float at[MAX];
    float ct[MAX];
    float wt[MAX];
    float tt[MAX];
    float completed[MAX];
    int start, total;
    
    SJF();

    void calculate(int);

    void avg_waiting_time(int);
    void avg_turn_around_time(int);
};

SJF::SJF()
{
  start = 0;
  total = 0;
  cout << "\nEnter the unit: ";
  cin >> unit;
}

void SJF::calculate(int n)
{
  while(total != n)
  {
    int c=n, minim=999;
    for(int i=0; i<n; i++)
    {
      if(at[i] <= start && completed[i] != 1 && bt[i] < minim)
      {
        minim = bt[i];
        c = i;
      }
    }
    if(c == n)
      start++;
    else
    {
      ct[c] = start + bt[c];
      start += bt[c];
      tt[c] = ct[c] - at[c];
      wt[c] = tt[c] - bt[c];
      completed[c] = 1;
      pid[total] = c + 1;
      total++;
    }
  }
}

void  SJF::avg_waiting_time(int n)
{
  float twt = 0, awt;
  for(int i=0; i<n; i++)
  {
    twt = twt + wt[i];
  }
  awt = twt/n;
  cout << awt << unit;
}

void  SJF::avg_turn_around_time(int n)
{
  float ttt = 0, att;
  for(int i=0; i<n; i++)
  {
    ttt = ttt + tt[i];
  }
  att = ttt/n;
  cout << att << unit;
}

int main()
{
  cout << "========== SJF scheduling algorithm ==========";
  SJF ob;
  int n;
  cout << "\nEnter the no. of processes : ";
  cin >> n;
  cout << endl;
  
  for(int i=0; i<n; i++)
  {
    cout << "Process " << i+1 << endl;
    cout << "Enter the arrival time : ";
    cin >> ob.at[i];
    cout << "Enter the burst time : ";
    cin >> ob.bt[i];
    ob.pid[i] = i+1;
    ob.completed[i] = 0;
    cout << endl;
  }

  ob.calculate(n);
  cout << "\nProcess Id\tArrival Time\tBurst Time\tCompletetion Time\tWaiting Time\tTurn Around Time\n";
  cout << "=============================================================================================================\n";
  for(int j=0; j<n; j++)
  {
    int x = ob.pid[j];
    cout << fixed << setprecision(2);
    cout << setw(5) << ob.pid[j]
        << setw(16) << ob.at[x-1] << ob.unit
        << setw(15) << ob.bt[x-1] << ob.unit
        << setw(15) << ob.ct[x-1] << ob.unit
        << setw(20) << ob.wt[x-1] << ob.unit
        << setw(20) << ob.tt[x-1] << ob.unit << "\n";
  }
  cout << "\nAverage Waiting Time: ";
  ob.avg_waiting_time(n);
  cout << "\nAverage Turn Around Time: ";
  ob.avg_turn_around_time(n);
  cout << endl;
}
