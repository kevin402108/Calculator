//High Accuracy Calculation (Only support Positive Interger)
#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include"Others.hpp"
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::string;
int factorres[10000000];

void numcpy(int p[], int q[], int times)
{
    for (int i = 1; i <= p[0]; i++) { q[i + times - 1] = p[i]; }
    q[0] = p[0] + times - 1;
}
void minu(int a[], int b[])
{
    for (int i = 1; i <= a[0]; i++)
    {
        if (a[i] < b[i]) { a[i + 1]--; a[i] += (10 - b[i]); }
        else { a[i] -= b[i]; }
    }
    while (a[a[0]] == 0 && a[0] > 0) { a[0]--; }
}
int cmp(int a[], int b[])
{
    if (a[0] > b[0]) { return 1; }
    else if (a[0] < b[0]) { return -1; }
    for (int i = a[0]; i >= 1; i--)
    {
        if (a[i] < b[i]) { return -1; }
        if (a[i] > b[i]) { return 1; }
    }
    return 0;
}
void print(int res[])
{
    if (res[0] == 0) { cout << "0"; }
    else
    {
        for (int i = res[0]; i >= 1; i--) { cout << res[i]; }
    }
}

bool cmpnum(string a, string b)
{
    if (a.length() < b.length()) { return false; }
    else
    {
        if (a.length() == b.length())
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] < b[i]) { return false; break; }
            }
        }
    }
    return true;
}
void HighIntPlus(string Userlabel)
{
    while (true)
    {
        int HighPlusInErr = 0; string E1; char E1op;
        int plusnum1[50000]{ 0 }, plusnum2[50000]{ 0 }, sum[50005]{ 0 };
        string  n1, n2;
        cout << "请输入一个50000位内的正整数:";
        getline(cin, n1);
        for (ull i = 0; i < n1.size(); i++) { if (isdigit(n1[i]) == false) { HighPlusInErr++; break; } }
        cout << "请再输入一个50000位内的正整数:";
        getline(cin, n2);
        for (ull i = 0; i < n2.size(); i++) { if (isdigit(n2[i]) == false) { HighPlusInErr++; break; } }
        if (HighPlusInErr) { cout << "输入数据有误!请重新输入!\n"; }
        if (HighPlusInErr == 0)
        {
            int length = max(n1.size(), n2.size());
            for (int i = n1.size() - 1, j = 1; i >= 0; i--, j++) { plusnum1[j] = n1[i] - '0'; }
            for (int i = n2.size() - 1, j = 1; i >= 0; i--, j++) { plusnum2[j] = n2[i] - '0'; }
            for (int i = 1; i <= length; i++)
            {
                sum[i] += (plusnum1[i] + plusnum2[i]);
                if (sum[i] >= 10) { sum[i + 1] = sum[i] / 10; sum[i] %= 10; }
            }
            if (sum[length + 1]) { length++; }
            cout << "\n计算结果:";
            for (int i = length; i >= 1; i--) { cout << sum[i]; }
        }
        E1op = Exitchoice(E1);
        if (E1op == '1') { break; }
    }
}
void HighIntMinus(string Userlabel)
{
    while (true)
    {
        int HighMinusErr = 0;
        bool flag = 1;//判断结果是否为负
        string subnum1, subnum2, E3; char E3op;
        int num1[50000]{ 0 }, num2[50000]{ 0 }, subres[50000]{ 0 };
        cout << "请输入被减数:";
        getline(cin, subnum1);
        for (int i = 0; i < subnum1.size(); i++) { if (isdigit(subnum1[i]) == false) { HighMinusErr++; break; } }
        cout << "请输入减数:";
        getline(cin, subnum2);
        for (int i = 0; i < subnum2.size(); i++) { if (isdigit(subnum2[i]) == false) { HighMinusErr++; break; } }
        if (HighMinusErr) { cout << "输入错误,请重新输入!"; }
        else
        {
            if (cmpnum(subnum1, subnum2) == 0) { swap(subnum1, subnum2); flag = 0; }
            for (int i = subnum1.size() - 1, j = 1; i >= 0; i--, j++) { num1[j] = int(subnum1[i] - '0'); }
            for (int i = subnum2.size() - 1, j = 1; i >= 0; i--, j++) { num2[j] = int(subnum2[i] - '0'); }
            int length = subnum1.size();
            for (int i = 1; i <= length; i++)
            {
                if (num1[i] < num2[i]) { subres[i] += (num1[i] + 10 - num2[i]); subres[i + 1] = -1; }
                else { subres[i] += (num1[i] - num2[i]); subres[i + 1] = 0; }
            }
            if (flag == 0)
            {
                cout << "计算结果: -";
                for (int i = length; i >= 1; i--)
                {
                    if (i == length) { if (subres[i]) { cout << subres[i]; } }
                    else { cout << subres[i]; }
                }
            }
            else
            {
                cout << "计算结果:";
                for (int i = length; i >= 1; i--)
                {
                    if (i == length) { if (subres[i]) { cout << subres[i]; } }
                    else { cout << subres[i]; }
                }
            }
        }
        E3op = Exitchoice(E3);
        if (E3op == '1') { break; }
    }
}
void HighIntMultiply(string Userlabel)
{
    while (true)
    {
        string mulnum1, mulnum2; string E2; char E2op;
        int num1[25000]{ 0 }, num2[25000]{ 0 }, mulres[50005]{ 0 }, HighMulErr = 0;
        cout << "请输入乘数1:";
        getline(cin, mulnum1);
        for (ull i = 0; i < mulnum1.size(); i++) { if (isdigit(mulnum1[i]) == false) { HighMulErr++; break; } }
        cout << "请输入乘数2:";
        getline(cin, mulnum2);
        for (ull i = 0; i < mulnum2.size(); i++) { if (isdigit(mulnum2[i]) == false) { HighMulErr++; break; } }
        if (HighMulErr) { cout << "输入数据有误!请重新输入!\n"; }
        if (HighMulErr == 0)
        {
            int totallen = mulnum1.size() + mulnum2.size();
            for (int i = mulnum1.size() - 1; i >= 0; i--) { num1[mulnum1.size() - i] = int(mulnum1[i] - '0'); }
            for (int i = mulnum2.size() - 1; i >= 0; i--) { num2[mulnum2.size() - i] = int(mulnum2[i] - '0'); }
            for (int i = 1; i <= mulnum1.size(); i++)
            {
                for (int j = 1; j <= mulnum2.size(); j++)
                {
                    mulres[i + j - 1] += (num1[i] * num2[j]);
                }
            }
            for (int i = 1; i <= totallen; i++)
            {
                if (mulres[i] >= 10) { mulres[i + 1] = mulres[i] / 10; mulres[i] %= 10; }
            }
            for (; !mulres[totallen];) { totallen--; }
            cout << "\n计算结果: ";
            for (int i = max(1, totallen); i >= 1; i--)
            {
                cout << mulres[i];
            }
            E2op = Exitchoice(E2);
            if (E2op == '1') { break; }
        }

    }
}
void HighIntDivide(string Userlabel)
{
    while (true)
    {
        int HighIntErr4 = 0; bool cmpres = true;
        string Divnum1, Divnum2, E4; char E4op;
        int num1[50000]{ 0 }, num2[50000]{ 0 }, divres[50000]{ 0 }, temp[50000]{ 0 };
        cout << "请输入被除数:";
        getline(cin, Divnum1);
        for (int i = 0; i < Divnum1.length(); i++) { if (isdigit(Divnum1[i]) == false) { HighIntErr4++; break; } }
        cout << "请输入除数:";
        getline(cin, Divnum2);
        for (int i = 0; i < Divnum2.length(); i++)
        {
            if (Divnum2[0] == '0') { HighIntErr4++; break; }
            else { if (isdigit(Divnum2[i]) == false) { HighIntErr4++; break; } }
        }
        if (HighIntErr4) { color_print("输入中含有非数字字符或除数为0,请重新输入!\n\n",4); }
        else
        {
            divres[0] = Divnum1.length() - Divnum2.length() + 1;
            if (cmpnum(Divnum1, Divnum2) == 0)
            {
                cmpres = false;
                cout << "商:0\n" << "余数:" << Divnum2;
            }//判断被除数与除数大小关系
            else
            {
                num1[0] = Divnum1.length(); num2[0] = Divnum2.length();
                for (int i = Divnum1.length() - 1; i >= 0; i--) { num1[Divnum1.length() - i] = Divnum1[i] - '0'; }
                for (int i = Divnum2.length() - 1; i >= 0; i--) { num2[Divnum2.length() - i] = Divnum2[i] - '0'; }
                for (int i = divres[0]; i >= 1; i--)
                {
                    memset(temp, 0, sizeof(temp));
                    numcpy(num2, temp, i);
                    while (cmp(num1, temp) >= 0)
                    {
                        divres[i]++;
                        minu(num1, temp);
                    }
                }
                while (divres[divres[0]] == 0 && divres[0] > 0) { divres[0]--; }
                cout << "商:";
                print(divres);
                cout << "\n余数:";
                print(num1);
            }
        }
        E4op = Exitchoice(E4);
        if (E4op == '1') { break; }
    }
}
void HighIntMod(string Userlabel)
{
    while (true)
    {
        int HighIntErr5 = 0; bool cmpres = true;
        string Divnum1, Divnum2, E5; char E5op;
        int num1[50000]{ 0 }, num2[50000]{ 0 }, divres[50000]{ 0 }, temp[50000]{ 0 };
        cout << "请输入被除数:";
        getline(cin, Divnum1);
        for (int i = 0; i < Divnum1.length(); i++) { if (isdigit(Divnum1[i]) == false) { HighIntErr5++; break; } }
        cout << "请输入除数:";
        getline(cin, Divnum2);
        for (int i = 0; i < Divnum2.length(); i++)
        {
            if (Divnum2[0] == '0') { HighIntErr5++; break; }
            else { if (isdigit(Divnum2[i]) == false) { HighIntErr5++; break; } }
        }
        if (HighIntErr5) { cout << "输入中含有非数字字符 或 除数为0 ,请重新输入!\n\n"; }
        else
        {
            divres[0] = Divnum1.length() - Divnum2.length() + 1;
            if (cmpnum(Divnum1, Divnum2) == 0)
            {
                cmpres = false;
                cout << Divnum1 << " mod " << Divnum2 << " = " << Divnum2;
            }//判断被除数与除数大小关系
            else
            {
                num1[0] = Divnum1.length(); num2[0] = Divnum2.length();
                for (int i = Divnum1.length() - 1; i >= 0; i--) { num1[Divnum1.length() - i] = Divnum1[i] - '0'; }
                for (int i = Divnum2.length() - 1; i >= 0; i--) { num2[Divnum2.length() - i] = Divnum2[i] - '0'; }
                for (int i = divres[0]; i >= 1; i--)
                {
                    memset(temp, 0, sizeof(temp));
                    numcpy(num2, temp, i);
                    while (cmp(num1, temp) >= 0)
                    {
                        divres[i]++;
                        minu(num1, temp);
                    }
                }
                while (divres[divres[0]] == 0 && divres[0] > 0) { divres[0]--; }
                cout << Divnum1 << " mod " << Divnum2 << " = ";
                print(num1);
            }
            E5op = Exitchoice(E5);
            if (E5op == '1') { break; }
        }
    }
}

void HighFactorialCalc(string Userlabel)
{
    while (true)
    {
        int HighIntErr6 = 0, length = 1, Originnum = 0, End0 = 0;
        string num, factnum, E6; char E6op;
        memset(factorres, 0, sizeof(factorres));
        factorres[0] = 1;
        cout << "请输入一个不超过 100,0000 的正整数:";
        getline(cin, num);
        if (num.length() == 0 || num.length() > 6 && num != "1000000") { HighIntErr6++; }
        for (int i = 0; i < num.length(); i++) { if (!isdigit(num[i])) { HighIntErr6++; break; } }
        if (HighIntErr6) { cout << "数据输入有误!\n"; }
        else
        {
            for (int i = 0; i <= num.size(); i++) { Originnum += (num[i] - '0') * int(pow(10, num.size() - 1 - i)); }
            for (int i = 1; i <= Originnum; i++)
            {
                int position = 0, move = 0;
                while (true)
                {
                    int mid_num = factorres[position] * i + move;
                    factorres[position] = mid_num % 10;
                    move = mid_num / 10;
                    position++;
                    if (factorres[position] == 0 && move == 0 && position >= length) { break; }
                }
                length = position;
            }
            printf("\n阶乘结果 : \n");
            for (int i = length - 1; i >= 0; i--) { cout << factorres[i]; }
            color_print("\n阶乘结果位数 : ", 2);
            color_print<int>(length);
            for (int i = 0; i <= length - 2; i++)
            {
                if (factorres[i] == 0 && factorres[i + 1] == 0) { End0++; }
                if (factorres[i] == 0 && factorres[i + 1]) { End0++;  break; }
            }
            color_print("\n计算结果末尾0的个数: ", 2);
            color_print<int>(End0);
            E6op = Exitchoice(E6);
            if (E6op == '1') { break; }
        }
    }
}

