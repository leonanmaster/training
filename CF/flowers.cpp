#include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t, k ;
        cin >> t;
        cin >> k;
     
        vector<int> dp; // guardará as combinações para cad a i
       
        //prefix sum
        vector<int> ps; // guardará as somas para n precisar ter um for q calcula as somas dos intervalos
       
        ps.push_back(0);
     
        // nesse passo é fundamental estabelecer a RR de dp (dp[i] = dp[i-1] + dp[i-k])
        for (int i = 0; i < 100001; i++){
            if (i == k){
                dp.push_back(2);
            }else if (i < k){
                dp.push_back(1);
            }else {
                dp.push_back((dp[i-1] + dp[i-k]) % 1000000007);
            }
        }
       
        for (int i = 1; i < 100001; i++){
            //ignoro o dp[0] pq ele representa o numero de maeiras de organizar uma sequencia de tamanho 0...
            ps.push_back((ps[i-1] + dp[i]) % 1000000007);
        }
     
        int a, b;
        int soma;
        for (int i = 0; i < t; i++){
            cin >> a;
            cin >> b;
           
            // ps entra em ação aqui
            soma = ((ps[b] - ps[a-1]) + 1000000007) % 1000000007;
     
            cout << soma << endl;
        }
        return 0;
    }