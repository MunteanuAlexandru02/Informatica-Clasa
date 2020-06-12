#include <iostream>
#include <cmath>
using namespace std;
int n,y[101],cnt[101],cnty[101];
int main()
{
    cin >> n;
    int k = 1;
    while(n>0)
    {
        for(int i = 1; i <= k && n > 0; i++)
            {
                cout << k << " ";
                cnt[k]++;
                n--;
            }
        k++;
    }
    cout << endl;
    cin >> n;
    float x1 = (-1+sqrt(1+4*2*n))/2;
    cout << ceil(x1) << endl;
    cin >> n;
    cout << endl;
    for(int i = 1; i <= n; i++)
        {
            cin >> y[i];
            cnty[y[i]] ++;
        }
    for(int i = 1; i <= ceil(x1); i ++)
        if(cnt[i] != cnty[i])
            {
                cout << "NU";
                return 0;
            }
    cout << "DA";


}
