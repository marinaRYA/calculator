#include <iostream>
using namespace std;
class operand
{
    int mean;
    int sum(int a, int b)
    {
        mean= a + b;
        return mean;
    }
    int dif(int a, int b)
    {
       mean=a - b;
        return mean;
    }
    int multi(int a, int b)
    {
        mean=a * b;
        return mean;
    }
    int div(int a, int b)
    {
        try { mean = a / b; }
        catch (...)
        {
            cout << "делить нельзя";
                
          }
            return mean;
    }
public:
    int choice(int a, int b, char s)
    {
        switch (s)
        {
        case '+': return sum(a, b); break;
        case '-': return dif(a, b); break;
        case '*': return multi(a, b); break;
        case '/': return div(a, b); break;
        }
    }
};
class command
{
    int a, b;
    char sign;
    operand act;
public:
    void set_res(int x) { a = x; }
    void set(int y, char s)
    {
        b = y;
        sign = s;
    }
    int res(int x, int y, char s)
    {
       return act.choice(x, y, s);
    }
};
class cpu1
{
    int res;
    int min;
    int max;
    command result;
    int overflow(int res,int a,int b)
    {
        /*if ((res > max) || (res < min))
        {
            res = a % b;
            cout << "переполнение";
        }*/
            cout<<res;
            return res;
    }
public:
    void set(int min_x, int max_x)
    {
        min = min_x;
        max = max_x;
    }
    int act(int x, int y, char s)
    {
        result.set_res(x);
        result.set(y, s);
        res = result.res(x, y, s);
        result.set_res(overflow(res,x,y));
        return res;
    }
};
/*class cpu2
{
    int res;
    int min;
    int max;
    command result;
    int overflow(int res)
    {
        if ((res > max) || (res < min)) res = -1;
        return res;
    }
public:
    void set(int min_x, int max_x)
    {
        min = min_x;
        max = max_x;
    }
    int act(int x, int y, char s)
    {
        result.set_res(x);
        result.set(y, s);
        res = result.res(x, y, s);
        result.set_res(overflow(res));
        return res;
    }
   
};*/
class vm
{
    int count1{ 0 };
    int count2{ 0 };
    cpu1* c1 = new cpu1[count1];
  //  cpu2* c2 = new cpu2[count1];
public:
    void Add_Cpu1(int count1)
    {
        cout << "Введите min & max для новой первой ЦПУ" << endl;
        while (1)
        {
            int max, min;
            cout << "max ";
            cin >> max;
            cout << "min: ";
            cin >> min;
            if (min > max) cout << "error" << endl;
            else break;
            if (count1 == 0) c1[count1].set(min, max);
            else
            {
                count1++;
                try
                {
                    cpu1* c1 = new cpu1[count1];
                    c1[count1].set(min, max);
                    throw - 1;
                }
                catch (bad_alloc)
                {
                    cout << "Память не выделена" << endl;
                }
                throw - 1;
            }
        }
    }
    /*void Add_Cpu2(int count2)
    {
        cout << "Введите min & max для новой второй ЦПУ" << endl;
        while (1)
        {
            int max, min;
            cout << "max ";
            cin >> max;
            cout << "min: ";
            cin >> min;
            if (min > max) cout << "error" << endl;
            else break;
        }
        if (count2 == 0) c2[count2].set(min,max);
        else
        {
            count2++;
            c2 = new cpu2[count2];
            c2[count1].set(min, max);
        }*/

};
int main()
{
    setlocale(LC_ALL, "RUSSIAN"); // установка локали
    int max, min;
    int a, b;
    char s;
    cpu1 c;
    while (1)
    {
        int max, min;
        cout << "max ";
        cin >> max;
        cout << "min: ";
        cin >> min;
        if (min > max) cout << "error" << endl;
        else break;
    }
    cout << "действие";
    cin >> a >> s >> b;
    c.act(a, s, b);
}