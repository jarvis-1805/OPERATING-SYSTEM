#include <iostream>
#define MAX 100

using namespace std;

class FCFS
{
  public:
    int wt[MAX];
    
    void waitingTime(int, int *);
    void avgWaitingTime(int);
};

void FCFS::waitingTime(int n, int *bt)
{
  int temp;
  wt[0] = 0;
  for(int i=0; i<n; i++)
  {
    wt[i+1] = bt[i] + wt[i];
  }
  for(int j=0; j<n; j++)
  {
    cout << "P" << j+1 << " = " << wt[j] << "\n              ";
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
  int bt[n];
  for(int i=0; i<n; i++)
  {
    cout << "Enter the burst time of process " << i+1 << " : ";
    cin >> bt[i];
  }
  cout << "\nWaiting Time: ";
  ob.waitingTime(n, bt);
  cout << "\nAverage Waiting TIme: ";
  ob.avgWaitingTime(n);
  cout << endl;
}