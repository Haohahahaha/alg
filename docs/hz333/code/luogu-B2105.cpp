#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int A[110][110];
	int B[110][110];
	int C[110][110];

	int n,m,k = 0;
	int i,j;

	// 输入部分

	cin >> n >> m >> k; // 输入A和B的行列值
	
	// 输入A
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			cin >> A[i][j];
		} 
	}	  

	// 输入B
	for(i = 1; i <= m; i++){
		for(j = 1; j <= k; j++){
			cin >> B[i][j];
		} 
	}

	// 计算C
	for(i = 1; i <= n; i++){
		for(j = 1; j <= k; j++){
			for(int x = 1; x <= m; x++){
				C[i][j] += A[i][x] * B[x][j];
			}
		} 
	}

	// 输出C
	for(i = 1; i <= n; i++){
		for(j = 1; j <= k; j++){
			cout << C[i][j] << " ";
		} 
		cout << endl;
	}

	return 0;
}
