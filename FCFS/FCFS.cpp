#include <iostream>
#include<iomanip>
#define MAX 100

using namespace std;

class FCFS
{
  public:
    string unit;
    float wt[MAX];
    float tt[MAX];
    
    FCFS();

    void waitingTime(int, float *, float *);
    void avgWaitingTime(int);
    void turnAroundTime(int, float *, float *);
    void avgTurnAroundTime(int);
};

FCFS::FCFS()
{
  cout << "\nEnter the unit: ";
  cin >> unit;
}

void FCFS::waitingTime(int n, float *bt, float *at)
{
  float b=0.0;
  wt[0] = at[0];
  for(int i=0; i<n; i++)
  {
    b = b + bt[i];
    wt[i+1] = b - at[i+1];
  }
}

void FCFS::avgWaitingTime(int n)
{
  float twt = 0, awt;
  for(int i=0; i<n; i++)
  {
    twt = twt + wt[i];
  }
  awt = twt/n;
  cout << awt << unit;
}

void FCFS::turnAroundTime(int n, float *bt, float *at)
{
  for(int i=0; i<n; i++)
  {
    tt[i] = wt[i] + bt[i];
  }
  for(int j=0; j<n; j++)
  {
    cout << fixed << setprecision(2);
    cout << setw(5) << j+1 
        << setw(15) << at[j] << unit
        << setw(15) << bt[j] << unit
        << setw(15) << wt[j] << unit
        << setw(15) << tt[j] << unit << "\n";
  }
}

void FCFS::avgTurnAroundTime(int n)
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
  FCFS ob;

  int n;
  cout << "\nEnter the no. of processes : ";
  cin >> n;
  cout << endl;

  float bt[n], at[n];
  for(int i=0; i<n; i++)
  {
    cout << "Enter the arrival time of process " << i+1 << " : ";
    cin >> at[i];
    cout << "Enter the burst time of process " << i+1 << " : ";
    cin >> bt[i];
    cout << endl;
  }

  cout << "\nProcess Id\t\tArrival Time\tBurst Time\t\tWaiting Time\tTurn Around Time\n";
  ob.waitingTime(n, bt, at);
  ob.turnAroundTime(n, bt, at);

  cout << "\nAverage Waiting Time: ";
  ob.avgWaitingTime(n);

  cout << "\nAverage Turn Around Time: ";
  ob.avgTurnAroundTime(n);
  cout << endl;
}