/**
 * http://github.com/OpenUPI/cspc
 *
 * Longest Common Subsequence - O(mn) dynamic programming solution
 * http://www.spoj.com/problems/TLCS/
 *
 * Untuk setiap kata x = x1x2...xn dan y = y1y2...ym, cari subsekuens serupa terpanjang.
 * Sebagai contoh, z = z1z2...zk dimana setiap dua elemen konsekutif dari z sama dengan 
 * x: xa, xb, dan y: yc, yd dimana a < b dan c < d. Diasumsikan, setiap elemen dalam kata
 * merupakan huruf 'a' - 'z' dan m, n <= 1.000.
 *
 * [Input]
 * N [jumlah seri <= 1000] 
 * n x 
 * m y 
 * ...
 *
 * [Output]
 * case 1 Y [atau N ketika kasus ini tidak memiliki jawaban] 
 * d [panjang subsekuens terpanjang] 
 * zj p q [posisi zj dalam x dan y] 
 * ...
 *
 * Teks dalam kurung [ ] hanya berupa arahan dan tidak termasuk ke dalam masukan/keluaran sebenarnya.
 *
 * [Contoh]
 * Masukan:
 * 3
 * 5 ddacc
 * 3 cac
 * 7 cbbccbc
 * 4 aaca
 * 4 cbeb
 * 5 fdceb
 *
 * Keluaran:
 * case 1 Y
 * 2
 * a 3 2
 * c 4 3
 * case 2 N
 * case 3 Y
 * 3
 * c 1 3
 * e 3 4
 * b 4 5
 */

#include <iostream>
#include <string>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N;
	std::cin >> N;

	for(int i = 0; i < N; ++i) {
		int n, m;
		std::string x, y;
		std::cin >> n >> x >> m >> y;

		int **temp = new int*[n + 1];
		int maxJ = 0, maxK = 0, maxValue = 0;

		for(int j = 0; j <= n; ++j) {
			temp[j] = new int[m + 1];
			for(int k = 0; k <= m; ++k) {
				if(j == 0 || k == 0)
					temp[j][k] = 0;
				else if(x[j - 1] == y[k - 1]) {
					temp[j][k] = temp[j - 1][k - 1] + 1;

					if(temp[j][k] > maxValue) {
						maxValue = temp[j][k];
						maxJ = j;
						maxK = k;
					}
				}
				else temp[j][k] = max(temp[j - 1][k], temp[j][k - 1]);
			}
		}

		std::string *findings = new std::string[maxValue];

		for(int j = n, k = m, fi = 0; j > 0 && k > 0;) {
			if(x[j - 1] == y[k - 1]) {
				char buf[128];
				sprintf(buf, "%c %d %d", x[j - 1], j, k);
				findings[fi] = buf;

				j--;
				k--;
				fi++;
			}
			else if(temp[j - 1][k] > temp[j][k - 1])
				j--;
			else k--;
		}

		std::cout << "case " << (i + 1) << " " << (maxValue > 1 ? "Y" : "N") << std::endl;
		if(maxValue > 1) {
			std::cout << maxValue << std::endl;
			for(int j = maxValue - 1; j >= 0; j--) {
				std::cout << findings[j] << std::endl;
			}
		}

		delete[] findings;
	}

	return 0;
}