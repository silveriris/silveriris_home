#include<iostream>
#include<string>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* result = new int[n+1]();
    int** matrix = new int* [n+1];
    int** presum = new int*[n+1];
    for (int i = 0; i <= n; i++)
    {
        matrix[i] = new int[n + 1]();
        presum[i] = new int[n + 1]();
    }
    
    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= n; j++) 
        {
            char ch = line[j-1];
            matrix[i][j] = (ch - '0');
            presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + matrix[i][j];
        }
    }

    int sum=0;
    for (int r = 2; r <= n; r+=2)
    {
        for (int offseti = 1; offseti <= n - r+1 ; offseti++)
        {
            for (int offsetj = 1; offsetj <= n - r +1; offsetj++)
            {
                sum = presum[r + offseti-1][r + offsetj-1] - presum[offseti - 1][r + offsetj-1] - presum[r + offseti-1][offsetj - 1] + presum[offseti - 1][offsetj - 1];
                //cout << sum<<' '<<r*r<<endl;
                result[r] += (sum * 2 == (r * r));
                sum = 0;
                
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
           cout << presum[i][j];
        }
        cout << endl;
    }
 */
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << endl;
    }
  
    return 0;
}