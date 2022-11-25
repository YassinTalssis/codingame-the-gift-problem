#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();//the number of particpants
    int c;//the price of gift
    cin >> c; cin.ignore();
    vector<int> tab;
    int s=0;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; cin.ignore();
        tab.push_back(b);
    s+=tab[i];
    }
    sort(tab.begin(), tab.end());
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if(s<c)
        cout << "IMPOSSIBLE" << endl;
    else{
        int remain = n;
        int remainCost = c;
        
        while (remain > 0)
        {
            bool averagePossible = true;
            int average = remainCost / remain;
            int remainder = remainCost % remain;//rest of div 
            for (int i = n - remain; i < n; ++i)
            {
                if (tab[i] <= average)
                {
                    cout << tab[i] << endl;
                    remainCost -= tab[i];
                    remain--;
                    averagePossible = false;
                }
                else
                {
                    if (averagePossible)
                    {
                        for (int j = i; j < n - remainder; ++j)
                            cout << average << endl;
                        
                        for (int j = n - remainder; j < n; ++j)
                            cout << average+1 << endl;
                        
                        remain = 0;
                        break;
                    }
                    else 
                        break;
                }
            }
        }
    }
}
