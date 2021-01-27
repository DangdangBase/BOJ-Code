    #include <bits/stdc++.h>
    using namespace std;

    int T, Q, n;
    char c;
    map<int, int> m;


    int main()
    {
        cin.tie(0);
        ios_base::sync_with_stdio(0);

        cin >> T;
        while(T--){
            m.clear();
            cin >> Q;

            for(int i=0; i<Q; i++){
                cin >> c >> n;

                if(c == 'I'){
                    m[n]++;
                } else if(c == 'D'){
                    if(m.empty()) continue;
                    else if(n == -1){
                        m.begin()->second--;
                        if(m.begin()->second == 0){
                            m.erase(m.begin());
                        }
                    } else {
                        prev(m.end())->second--;
                        if(prev(m.end())->second == 0){
                            m.erase(prev(m.end()));
                        }
                    }
                }
            }

            if(m.empty()){
                cout << "EMPTY" << "\n";
            } else {
                cout << prev(m.end())->first << ' ' << m.begin()->first << "\n";
            }
        }


        return 0;
    }