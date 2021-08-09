#include <bits/stdc++.h>
using namespace std;

int C, N, adj[26][26], in[26], out[26];
string words[100];
vector<string> edges[26][26];
vector<int> chain;

enum Euler {
	NONE,
	CIRCUIT,
	TRAIL
};

int alphaNum(char c) {
	return c - 'a';
}

void setAdj() {
	for (int i = 0; i < N; i++) {
		int front = alphaNum(words[i].front());
		int back = alphaNum(words[i].back());

		in[back]++;
		out[front]++;
		adj[front][back]++;
		edges[front][back].push_back(words[i]);
	}
}

void getEulerCircuit(int v, vector<int>& circuit) {
	for (int i = 0; i < 26; i++) {
		while (adj[v][i] > 0) {
			adj[v][i]--;
			getEulerCircuit(i, circuit);
		}
	}

	circuit.push_back(v);
}

Euler checkEuler() {
	int inV = 0;
	int outV = 0;

	for (int i = 0; i < 26; i++) {
		int delta = out[i] - in[i];

		if (delta < -1 || delta > 1) return NONE;
		if (delta == 1) outV++;
		if (delta == -1) inV++;
	}

	if (inV == 0 && outV == 0) return CIRCUIT;
	if (inV == 1 && outV == 1) return TRAIL;
	return NONE;
}

void print() {
	for (int i = 0; i < N; i++) {
		int front = chain[i];
		int back = chain[i + 1];

		string edge = edges[front][back].back();
		edges[front][back].pop_back();

		cout << edge << " ";
	}
	cout << endl;	
}

int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> words[j];
		}

		memset(adj, 0, sizeof(adj));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		chain.clear();
		for (int r = 0; r < 26; r++)
			for (int c = 0; c < 26; c++)
				edges[r][c].clear();

		setAdj();
		
		switch (checkEuler()) {
			case NONE:
				cout << "IMPOSSIBLE" << endl;
				break;
			case CIRCUIT:
				for (int j = 0; j < 26; j++) {
					if (out[j] > 0) {
						getEulerCircuit(j, chain);
						reverse(chain.begin(), chain.end());
						print();
						break; 
					}
				}
				break;
			
			case TRAIL:
				for (int j = 0; j < 26; j++) {
					if (out[j] == in[j] + 1) {
						getEulerCircuit(j, chain);
						reverse(chain.begin(), chain.end());
						print();
						break;
					}
				}
				break;
		}
	}
}