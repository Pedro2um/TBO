#include <bits/stdc++.h>
using namespace std;

vector<int> a(10000000);
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.begin()+n);
	for(int i = 0; i < n; i++)
		cout << " " << a[i];
	cout << "\n";
	
return 0;
}
