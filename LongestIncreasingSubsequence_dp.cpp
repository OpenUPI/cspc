/**
 * http://github.com/OpenUPI/cspc
 *
 * Longest Increasing Subsequence - O(n^2) dynamic programming solution
 * http://www.spoj.com/problems/ELIS/
 * 
 * Diberikan sebuah daftar angka A, cari panjang dari subsekuens menaik terpanjang.
 * Subsekuens menaik didefinisikan sebagai sebuah kumpulan {i0, i1, i2, i3, ..., ik}
 * dimana subsekuens menaik terpanjang dari A adalah subsekuens dengan nilai k terbesar.
 * Sebagai contoh, dalam daftar angka {33, 11, 22, 44}, subsekuens {33, 44} dan {11} adalah
 * subsekuens menaik dan {11, 22, 44} adalah subsekuens menaik terpanjang.
 *
 * [Masukan]
 * Baris pertama berisi angka N (1 <= N <= 10) yang merupakan panjang dari daftar angka A.
 * Baris kedua berisi N buah angka (1 <= angka <= 20) yang masing-masing dipisah oleh spasi.
 * 
 * [Keluaran]
 * Satu baris berisi panjang dari subsekuens menaik terpanjang dalam A.
 *
 * [Contoh]
 * Masukan:
 * 5
 * 1 4 2 4 3
 *
 * Keluaran:
 * 3
 */

#include <iostream>

int main() {
	int n, *arr, *temp, *indices;
	std::cin >> n;
	arr = new int[n];
	temp = new int[n];
	indices = new int[n];

	int maxIndex = 0, maxValue = 1;

	for(int i = 0; i < n; ++i)
		std::cin >> arr[i];
	
	temp[0] = 1;
	for(int i = 1; i < n; ++i) {
		temp[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(arr[j] < arr[i] && temp[i] < temp[j] + 1) {
				temp[i] = temp[j] + 1;
				indices[i] = j;

				if(temp[i] > maxValue) {
					maxIndex = i;
					maxValue = temp[i];
				}
			}
		}
	}

	std::cout << maxValue << std::endl;

	/*
	 * BONUS! Print the sequence
	 */
	/*
	int *sequence = new int[maxValue];
	for(int i = maxValue - 1, current = maxIndex, next = maxIndex; i >= 0; i--) {
		current = next;
		sequence[i] = arr[current];
		next = indices[current];
	}

	for(int i = 0; i < maxValue; ++i)
		std::cout << sequence[i] << (i < maxValue - 1 ? " " : "");

	std::cout << std::endl;

	delete[] sequence;
	*/

	delete[] indices;
	delete[] temp;
	delete[] arr;

	return 0;
}