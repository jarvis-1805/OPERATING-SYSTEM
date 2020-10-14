#include<iostream>
#include<iomanip>
#include<stdio.h>
#define MAX 100

using namespace std;

class RR
{
  public:
    string unit;
    int pid[MAX];
    float bt[MAX];
    float at[MAX];
    float ct[MAX];
    float wt[MAX];
    float tt[MAX];
    float rem_bt[MAX];
    int quantum, start;
    
    RR();

    void calculate(int);

    void avg_waiting_time(int);
    void avg_turn_around_time(int);
};

RR::RR()
{
  start = 0;
  cout << "\nEnter the unit: ";
  cin >> unit;
}

void RR::calculate(int n)
{
  int t=0;
  bool done = false;
  while(!done)
  {
    done = true;
    for(int i=0; i<n; i++)
    {
      if(rem_bt[i] > 0)
      {
        done = false;
        if(at[i] <= start && rem_bt[i] > quantum)
        {
          t += quantum;
          rem_bt[i] -= quantum;
          start++;
        }
        else if(at[i] <= start)
        {
          start++;
          t += rem_bt[i];
          rem_bt[i] = 0;
          ct[i] = t;
        }
      }
    }
  }
  for(int i=0; i<n; i++)
  {
    tt[i] = ct[i] - at[i];
    wt[i] = tt[i] - bt[i];
  }
}

void  RR::avg_waiting_time(int n)
{
  float twt = 0, awt;
  for(int i=0; i<n; i++)
  {
    twt = twt + wt[i];
  }
  awt = twt/n;
  cout << awt << unit;
}

void  RR::avg_turn_around_time(int n)
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
  cout << "========== RR scheduling algorithm ==========";
  RR ob;
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
    ob.rem_bt[i] = ob.bt[i];
    cout << endl;
  }
  
  cout << "Enter the Time quantum : ";
  cin >> ob.quantum;
  cout << endl;

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
  getchar();
}
