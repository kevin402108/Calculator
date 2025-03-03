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

bool CheckInput(string input_string)//����ʽ�Ƿ���ȷ
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
void ShowSystemTime()//��ʾʱ��
{
    SYSTEMTIME time0;
    GetLocalTime(&time0);
    int Dayofweek = time0.wDayOfWeek;
    string dayofweek;
    switch (Dayofweek)
    {
        case 1:dayofweek = "һ"; break;
        case 2:dayofweek = "��"; break;
        case 3:dayofweek = "��"; break;
        case 4:dayofweek = "��"; break;
        case 5:dayofweek = "��"; break;
        case 6:dayofweek = "��"; break;
        case 7:dayofweek = "��"; break;
        default:break;
    }
    for (int i = 0; i < 40; i++) { cout << "*"; } 
    cout << "\n*              ʱ      ��              *\n";
    printf("*  ������ %4d �� %2d �� %2d �� (����", time0.wYear, time0.wMonth, time0.wDay);
    cout << dayofweek << ") *\n";
    printf("* ������      %2d ʱ %02d �� %02d ��        *\n", time0.wHour, time0.wMinute, time0.wSecond);
    for (int i = 0; i < 40; i++) { cout << "*"; } cout << '\n';
}
char Exitchoice(string ChoiceInput)
{
    char choice;
    while (true)
    {
        int exit000 = 0;
        cout << "\n�Ƿ��˳���ǰ���ܣ�����ѡ��(1.��/2.��)����";
        getline(cin, ChoiceInput);
        choice = ChoiceInput[0];
        if (!('1' <= choice && choice <= '2' && ChoiceInput.length() == 1)) { exit000++; cout << "�����������������\n\n"; }
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
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);//������̨�������ذ�ɫ
}


