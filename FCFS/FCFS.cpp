#include <iostream>
#define MAX 100
using namespace std;

class FCFS
{
  public:
    double wt[MAX];
    
    void waitingTime(int, double *, double *);
    void avgWaitingTime(int);
    void turnAroundTime(int, double *, double *);
    void avgTurnAroundTime(int);
};

void FCFS::waitingTime(int n, double *bt, double *at)
{
  double b=0.0;
  //b = bt[0];
  wt[0] = at[0];
  for(int i=0; i<n; i++)
  {
    b = b + bt[i];
    wt[i+1] = b - at[i+1];
  }
  for(int j=0; j<n; j++)
  {
    cout << "P" << j+1 << " =     " << at[j] << "\t\t" << bt[j] << "\t\t" << wt[j] << "\n";
  }
}

void FCFS::avgWaitingTime(int n)
{
  double twt = 0, awt;
  for(int i=0; i<n; i++)
  {
    twt = twt + wt[i];
  }
  awt = twt/n;
  cout << awt;
}

int main()
{
  FCFS ob;
  int n;
  cout << "\nEnter the no. of processes : ";
  cin >> n;
  cout << endl;
  double bt[n], at[n];
  for(int i=0; i<n; i++)
  {
    cout << "Enter the arrival time of process " << i+1 << " : ";
    cin >> at[i];
    cout << "Enter the burst time of process " << i+1 << " : ";
    cin >> bt[i];
    cout << endl;
  }  
  cout << "\n\tArrival Time\tBurst Time\tWaiting Time\n";
  ob.waitingTime(n, bt, at);
  cout << "\nAverage Waiting TIme: ";
  ob.avgWaitingTime(n);
  cout << endl;
}