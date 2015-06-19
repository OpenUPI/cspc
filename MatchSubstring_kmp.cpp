/**
 * http://github.com/OpenUPI/cspc
 *
 * Substring Problem - Knuth-Morris-Pratt algorithm / O(m+n)
 * http://www.spoj.com/problems/SUB_PROB/
 * 
 * Diberikan sebuah string M dan sebuah string N yang memiliki panjang lebih kecil dari M.
 * Anda harus mencari apakah setiap dari string N tersebut merupakan substring dari M.
 * Semua string hanya terdiri dari karakter alfanumerik.
 *
 * [Masukan]
 * Baris pertama berisi string M (panjangnya tidak lebih dari 100.000 karakter).
 * Baris berikutnya berisi sebuah angka N (N < 1000) yang merupakan jumlah string yang akan diuji.
 * N baris berikutnya berisi sebuah string S (panjangnya tidak lebih dari 2.000 karakter).
 *
 * [Keluaran]
 * Output should consist of N lines each with a character 'Y'/'N' indicating whether the string S is a
 * substring of String M or not.
 *
 * [Contoh]
 * Masukan:
 * abghABCDE
 * 2
 * abAB
 * ab
 *
 * Keluaran:
 * N
 * Y
 */

#include <iostream>
#include <string>

int *generatePsArray(const std::string &pattern) {
	int *psa = new int[pattern.length()];
	for(int i = 1, j = 0; i < pattern.length(); ++i) {
		if(pattern[i] == pattern[j]) {
			psa[i] = j + 1;
			++i; ++j;
		}
		else if(j != 0)
			j = psa[j - 1];
		else {
			psa[i] = 0;
			++i;
		}
	}

	return psa;
}

bool search(const std::string &text, const std::string &pattern) {
	int *psa = generatePsArray(pattern);
	int i, j;
	for(i = 0, j = 0; i < text.length() && j < pattern.length();) {
		if(text[i] == pattern[j]) {
			++i; ++j;
		}
		else if(j != 0)
			j = psa[j - 1];
		else ++i;
	}

	delete[] psa;

	return j == pattern.length();
}

int main() {
	int n;
	std::string text;
	std::cin >> text >> n;

	for(int i = 0; i < n; ++i) {
		std::string pattern;
		std::cin >> pattern;
		std::cout << (search(text, pattern) ? "Y" : "N") << std::endl;
	}

	return 0;
}