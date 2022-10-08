/*  vì code cũ của anh hoàng chạy 4.2 giây bị quá time .
    Nên giờ tui (thongtl123 - http://vinhdinhcoder.net/Coder/Details/thongtl123) sẽ thay bằng code của tui. 
    Anh em tham khảo nha 😘
*/

/*
                   Nguyễn Như Thông - 11A2 - THPT ĐỒNG LỘC
*/
#pragma GCC optimize("unroll-loops,02,no-stack-protector")
#include "bits/stdc++.h"
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define ull unsigned long long
#define str string
#define db double
#define fl float
#define all(x) x.begin(),x.end()
#define st first
#define nd second
#define task ""
#define user "thongtl123"
using namespace std;

const int N = 45;
int n,m,ans;
pair <int, int> a[N];
vector <pair<int, int>> T[2];

void solve(int i, int v, int w, int base, int maxn){
    if (i==maxn+1){
        T[base].push_back({w,v});
        return;
    }
    if (w+a[i].st<=m) solve(i+1,v,w,base,maxn), solve(i+1,v+a[i].nd,w+a[i].st,base,maxn);
    else solve(i+1,v,w,base,maxn);
}

signed main(){
    IOS
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i].st >> a[i].nd;
    solve(1,0,0,0,n/2);
    solve(n/2+1,0,0,1,n);
    sort(T[0].begin(),T[0].end());
    sort(T[1].begin(),T[1].end());
    for (int i=1;i<T[1].size();i++) T[1][i].nd = max(T[1][i].nd, T[1][i-1].nd);
    int itr = T[1].size()-1;
    for (int i=0;i<T[0].size();i++){
        while(T[0][i].st + T[1][itr].st>m && itr>=0) itr--;
        if (itr<0) break;
        ans = max(ans, T[0][i].nd + T[1][itr].nd);
    }
    cout << ans;
}
    
