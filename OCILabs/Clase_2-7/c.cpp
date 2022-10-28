#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> grafo;
vector<bool> visitados;

void crear_grafo(int n) {
  for (int i = 0; i < n; i++) {
    vector<int> nodo;
    grafo.push_back(nodo);
    visitados.push_back(false);
  }
}

void crear_conexion(int a, int b) {
  grafo[a].push_back(b);
  grafo[b].push_back(a);
}

int dfs(int nodo) {
  visitados[nodo] = true;
  int last = nodo;

  for (int i = 0; i < grafo[nodo].size(); i++) {
    int vecino = grafo[nodo][i];
    if (visitados[vecino] == false) {
      last = dfs(vecino);
    }
  }
  return last;
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  crear_grafo(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    crear_conexion(a - 1, b - 1);
  }
  vector<pair<int, int>> lista;
  pair<int, int> ultimos;

  ultimos.first = dfs(0);
  ultimos.second = -1;

  for (int i = 0; i < visitados.size(); i++) {
    if (!visitados[i]) {
      if (ultimos.first != -1) {
        ultimos.second = i;
        lista.push_back(ultimos);
        ultimos.first = dfs(i);
        ultimos.second = -1;
      } else
        ultimos.first = dfs(i);
    }
  }
  cout << lista.size() << '\n';
  for (int i = 0; i < lista.size(); i++) {
    cout << lista[i].first + 1 << ' ' << lista[i].second + 1 << '\n';
  }

  return 0;
}