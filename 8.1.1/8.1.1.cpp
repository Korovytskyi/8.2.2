#include <iostream>
#include <string>
using namespace std;

bool Not(char* x, size_t i)
{
  if (x[i] == '!' && x[i + 1] == '!' && x[i + 2] == '!')
  return true;
  else
  if (i < strlen(x) - 2)
  return  Not(x, ++i);
  else
  return false;
}

char* change(char* x, char* xNew, size_t l, size_t i)
{
    if (i < strlen(x) - 2)
    {
        if (x[i] == '!' && x[i + 1] == '!' && x[i + 2] == '!')
        {
        xNew[l] = '*';
        xNew[l + 1] = '*';
        l += 2;
        i += 2;
        }
        else
        {
         xNew[l] = x[i];
         ++l;
        }
        return   change(x, xNew, l, ++i);
    }
    else
    {
        xNew[l++] = x[i++];
        xNew[l++] = x[i];
        xNew[l] = '\0';
        strcpy_s(x, strlen(xNew) + 1, xNew);
        return x;
    }
}

int main()
{
    char* x = new char[101];
    char* xNew = new char[101];
    cout << "Enter" << endl;cin.getline(x, 100);
    if (Not(x, 0))
    {cout << change(x, xNew, 0, 0);}
    delete[] xNew;
    delete[] x;
    cout << endl;
    return 0;
}