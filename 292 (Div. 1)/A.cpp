#include <bits/stdc++.h>

using namespace std;
vector <int> num;


int main(){
	int n;
	cin >> n;
	string a;
	cin >> a;
	for(int i = 0; i < n; i++){
		if(a[i] == '2'){
			num.push_back(2);
		}else if(a[i] == '3'){
			num.push_back(3);
		}else if(a[i] == '4'){
			num.push_back(3);
			num.push_back(2);
			num.push_back(2);
		}else if(a[i] == '5'){
			num.push_back(5);
		}else if(a[i] == '6'){
			num.push_back(5);
			num.push_back(3);
		}else if(a[i] == '7'){
			num.push_back(7);
		}else if(a[i]== '8'){
			num.push_back(7);
			num.push_back(2);
			num.push_back(2);
			num.push_back(2);
		}else if(a[i] == '9'){
			
			num.push_back(7);
			num.push_back(3);
			num.push_back(3);
			num.push_back(2);
		}
	}
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	for(int i = 0; i < num.size(); i++)
		cout << num[i];
	cout << endl;
	return 0;
}