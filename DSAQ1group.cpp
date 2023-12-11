#include<bits/stdc++.h>
using namespace std;
vector<int> freq(26, 0);
string sol_2(string& input, int x) {
	string output = "";
	vector<int> index;
	vector<bool> visit(26, false);

	for (int i = 0; i < input.size(); i++) {
		if (freq[input[i] - 'a'] == x) {
			while (!visit[input[i] - 'a']) {
				output = output + input[i];
				visit[input[i] - 'a'] = true;
			}
			index.push_back(i);
		}
	}
	vector<bool> left(26, false);
	for (int i = index[0] - 1; i >= 0; i--) {
		while (left[input[i] - 'a']) {
			continue;
		}
		output = input[i] + output;
		left[input[i] - 'a'] = true;

	}
	vector<bool> right(26, false);
	for (int i = index[(int)index.size() - 1] + 1; i < input.size(); i++) {
		while (right[input[i] - 'a']) {
			continue;
		}
		output = output + input[i];
		right[input[i] - 'a'] = true;

	}

	vector<bool> visit2(26, false);
	int y = 0;
	int z = 1;

	while (z < index.size()) {
		for (int i = index[y] + 1; i < index[z]; i++) {
			while (visit2[input[i] - 'a']) {
				continue;
			}
			if (freq[input[i] - 'a'] > x) {
				output = output + input[i];
			}
			else if (freq[input[i] - 'a'] < x) {
				output = input[i] + output;
			}
			visit2[input[i] - 'a'] = true;
		}
		y++;
		z++;
	}
	vector<bool> visit3(26, false);
	for (int i = 0; i < output.size(); i++) {
		if (!visit3[output[i] - 'a']) {
			cout << output[i] << " " << freq[output[i] - 'a'] << " ";
			visit3[output[i] - 'a'] = true;
		}
	}
	cout << endl;
	return output;
}

string sol_1(string& input) {

	vector<bool> visit(26, false);
	string output = "";
	for (int i = 0; i < input.size(); i++) {
		freq[input[i] - 'a']++;
	}
	for (int i = 0; i < input.size(); i++) {
		if (!visit[input[i] - 'a']) {
			cout << input[i] << " " << freq[input[i] - 'a'] << " ";
			visit[input[i] - 'a'] = true;
			output = output + input[i];
		}
	}
	cout << endl;
	return output;
}


int main() {

	string st;
	cin >> st;
	int v;
	cin>>v;
	int a[v];
	for(int i=0;i<v;i++)
		cin>>a[i];
	st = sol_1(st);
	for(int i=0;i<v;i++){
		string output = sol_2(st, a[i]);
		st = output;
	}
	return 0;
}
