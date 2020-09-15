#include <iostream>
#include<iomanip>
#define MAX 100

using namespace std;

class SJF
{
  public:
    string unit;
    float wt[MAX];
    float tt[MAX];
    float bt[MAX];
    float at[MAX];
    int process[MAX];
    
    SJF();

    void sort(int);

    void waitingTime(int);
    void avgWaitingTime(int);
    void turnAroundTime(int);
    void avgTurnAroundTime(int);
};

SJF::SJF()
{
  cout << "\nEnter the unit: ";
  cin >> unit;
}

void SJF::sort(int n)
{
  float temp, temp1, temp2;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n-i-1; j++)
    {
      if(at[j] > at[j+1])
      {
        temp = bt[j];
        bt[j] = bt[j+1];
        bt[j+1] = temp;

        temp1 = process[j];
        process[j] = process[j+1];
        process[j+1] = temp1;

        temp2 = at[j];
        at[j] = at[j+1];
        at[j+1] = temp2;
      }
    }
  }
}

void  SJF::waitingTime(int n)
{
  float b=0.0;
  wt[0] = at[0];
  for(int i=0; i<n; i++)
  {
    b = b + bt[i];
    wt[i+1] = b - at[i+1];
  }
}

void  SJF::avgWaitingTime(int n)
{
  float twt = 0, awt;
  for(int i=0; i<n; i++)
  {
    twt = twt + wt[i];
  }
  awt = twt/n;
  cout << awt << unit;
}

void  SJF::turnAroundTime(int n)
{
  for(int i=0; i<n; i++)
  {
    tt[i] = wt[i] + bt[i];
  }
  for(int j=0; j<n; j++)
  {
    cout << fixed << setprecision(2);
    cout << setw(5) << process[j]
        << setw(15) << at[j] << unit
        << setw(15) << bt[j] << unit
        << setw(15) << wt[j] << unit
        << setw(15) << tt[j] << unit << "\n";
  }
}

void  SJF::avgTurnAroundTime(int n)
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
    ob.process[i] = i+1;
    cout << "Enter the arrival time of process " << i+1 << " : ";
    cin >> ob.at[i];
    cout << "Enter the burst time of process " << i+1 << " : ";
    cin >> ob.bt[i];
    cout << endl;
  }

  ob.sort(n);
  cout << "\nProcess Id\t\tArrival Time\tBurst Time\t\tWaiting        Time\tTurn Around Time\n";
  ob.waitingTime(n);
  ob.turnAroundTime(n);
  cout << "\nAverage Waiting Time: ";
  ob.avgWaitingTime(n);
  cout << "\nAverage Turn Around Time: ";
  ob.avgTurnAroundTime(n);
  cout << endl;
}