    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        long long t, k ;
        cin >> t;
        cin >> k;
     
        vector<long long> dp; // guardará as combinações para cad a i
        
        //prefix sum
        vector<long long> ps; // guardará as somas para n precisar ter um for q calcula as somas dos intervalos 
        
        ps.push_back(0);
     
        // nesse passo é fundamental estabelecer a RR de dp (dp[i] = dp[i-1] + dp[i-k])
        for (long long i = 0; i < 100001; i++){
            if (i == k){
                dp.push_back(2);
            }else if (i < k){
                dp.push_back(1);
            }else {
                dp.push_back((dp[i-1] + dp[i-k]) % 1000000007);
            }
        }
        
        for (long long i = 1; i < 100001; i++){
            ps.push_back((ps[i-1] + dp[i-1]) % 1000000007);
        }
     
        long long a, b;
        long long soma;
        for (long long i = 0; i < t; i++){
            cin >> a;
            cin >> b;
            
            // ps entra em ação aqui
            soma = ((ps[b+1] - ps[a]) + 1000000007) % 1000000007;
     
            cout << soma << endl; 
        }
        return 0;
    }
