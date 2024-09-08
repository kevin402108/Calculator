#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<Windows.h>
#include<sstream>
#include<cctype>
#include<cstdlib>
#include<utility>

typedef unsigned long long ull;
using std::string;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::stringstream;

bool CheckInput(string input_string)//检查格式是否正确
{
    bool flag2 = true;
    if (0<=input_string.length()&&input_string.length() < 6) { flag2 = false; return flag2; }
    else
    {
        for (int i = 0; i < input_string.length(); i++)
        {
            char x = input_string[i]; 
            if (isalnum(x) || x == '_') { continue; }
            else { flag2 = false; return flag2; }
        }
        return flag2;
    }
}
void ShowSystemTime()//显示时间
{
    SYSTEMTIME time0;
    GetLocalTime(&time0);
    int Dayofweek = time0.wDayOfWeek;
    string dayofweek;
    switch (Dayofweek)
    {
        case 1:dayofweek = "一"; break;
        case 2:dayofweek = "二"; break;
        case 3:dayofweek = "三"; break;
        case 4:dayofweek = "四"; break;
        case 5:dayofweek = "五"; break;
        case 6:dayofweek = "六"; break;
        case 7:dayofweek = "日"; break;
        default:break;
    }
    for (int i = 0; i < 40; i++) { cout << "*"; } 
    cout << "\n*              时      间              *\n";
    printf("*  今天是 %4d 年 %2d 月 %2d 日 (星期", time0.wYear, time0.wMonth, time0.wDay);
    cout << dayofweek << ") *\n";
    printf("* 现在是      %2d 时 %02d 分 %02d 秒        *\n", time0.wHour, time0.wMinute, time0.wSecond);
    for (int i = 0; i < 40; i++) { cout << "*"; } cout << '\n';
}
char Exitchoice(string ChoiceInput)
{
    char choice;
    while (true)
    {
        int exit000 = 0;
        cout << "\n是否退出当前功能？【请选择(1.是/2.否)】：";
        getline(cin, ChoiceInput);
        choice = ChoiceInput[0];
        if (!('1' <= choice && choice <= '2' && ChoiceInput.length() == 1)) { exit000++; cout << "输入错误！请重新输入\n\n"; }
        if (exit000 == 0) { break; }
    }
    return choice;
}

bool prime(ull num)
{
    bool flag = true;
    if (num == 1 || num == 0) { flag = false; }
    else if (num == 2 || num == 3) { flag = true; }
    else
    {
        if (num % 6 != 1 && num % 6 != 5) { flag = false; }
        else
        {
            for (ull i = 5; i <= sqrt(num); i+=6)
            {
                if (num % i == 0 || num % (i + 2) == 0) { flag = false; break; }
            }
        }
    }
    return flag;
}

pair<bool, double> VerifyDemicalValid(string demical, double l, double r)
{
    stringstream ss;
    double demicalnum = 0;
    bool anly = true;
    if ( count(demical.begin(), demical.end(), '.') >=2||count(demical.begin(),demical.end(),'-')>=2||demical.length()==0)
    { anly = false; demicalnum = -1; }
    if (anly == true)
    {
        for (int i = 0; i < demical.size(); i++)
        {
            if (!(isdigit(demical[i]) || demical[i] == '.' || demical[i] == '-')) { anly = false;  demicalnum = -1; break; }
        }
    }
    if (anly == true)
    {
        ss << demical;
        ss >> demicalnum;
    }
    if (!(l <= demicalnum && demicalnum <= r)) { anly = false; demicalnum = -1; }
    ss.str("");
    return make_pair(anly, demicalnum);
}

template <typename T>
void color_print(T content, int color=7)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    cout << content;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);//将控制台字体跳回白色
}


