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

int b[1048576],inner1[1048576], inner2[1048576];
int Sum1 = 0, Sum2;

int main() {
    int n;
    cin >> n;
   
    for (int i = 0; i < n; i++) {
        b[i] = i;
    }
    TimerCounter tc1, tc2, tc3, tc4;
    //初始化


    tc3.Start();
    for (int i = 0; i < n; i++) {
        Sum1 += b[i];
    }
    tc3.Stop();
    cout << tc3.dbTime << " ";
    //累加求和平凡算法

    tc4.Start();
    for (int m = n; m > 1; m /= 2) {
        for (int i = 0; i < m / 2; i++) {
            b[i] = b[i * 2] + b[i * 2 + 1];
        }
    }
    Sum2 = b[0];
    tc4.Stop();
    cout << tc4.dbTime;
    //二重循环优化累加

    return 0;
}