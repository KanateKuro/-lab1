#include<iostream>
#include<Windows.h>
using namespace std;
class TimerCounter
{
public:
    TimerCounter(void);//构造函数
    ~TimerCounter(void);//析构函数
private:
    LARGE_INTEGER startCount;//记录开始时间

    LARGE_INTEGER endCount;//记录结束时间

    LARGE_INTEGER freq;//本机CPU时钟频率
public:
    double dbTime;//程序运行的时间保存在这里

public:
    void Start();//被测程序开始点处开始计时
    void Stop();//被测程序结束点处结束计时
};
TimerCounter::TimerCounter(void)
{
    QueryPerformanceFrequency(&freq);//获取主机CPU时钟频率
}
TimerCounter::~TimerCounter(void)
{
}
void TimerCounter::Start()
{
    QueryPerformanceCounter(&startCount);//开始计时
}
void TimerCounter::Stop()
{
    QueryPerformanceCounter(&endCount);//停止计时

    dbTime = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)freq.QuadPart;//获取时间差

}

#define n 1000
long long a[n][n], b[n], inner[n];
int main() {
    TimerCounter tc;
    for (long long i = 0; i < n; i++) {
        b[i] = i;
        for (long long j = 0; j < n; j++) {
            a[i][j] = i + j;
        }
    }
    tc.Start();
    for (long long i = 0; i < n; i++) {
        inner[i] = 0;
        for (long long j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                inner[i] += a[j][i] * b[j];
            }
        }
    }
    tc.Stop();
    cout << tc.dbTime;
    //cache
}