#include <iostream>
#include <fstream>

int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	int trfr = 1; // transfer
	int N, M;
	if (fin.is_open() && fout.is_open()) {
		fin >> N;
		int* arr1 = new int[N];
		int* arr1new = new int[N];
		for (int i = 0; i < N; i++) {
			fin >> arr1[i];
		}
		for (int i = 0; i < N; i++) {
			if (i + trfr < N) {
				arr1new[i] = arr1[i + trfr];
			}
			else {
				arr1new[i] = arr1[i + trfr - N];
			}
		}
		fin >> M;
		int* arr2 = new int[M];
		int* arr2new = new int[M];
		for (int i = 0; i < M; i++) {
			fin >> arr2[i];
		}
		for (int i = 0; i < M; i++) {
			if (i + trfr < M) {
				arr2new[i + trfr] = arr2[i];
			}
			else {
				arr2new[i + trfr - M] = arr2[i];
			}
		}
		fout << M << '\n';
		for (int i = 0; i < M; i++) {
			fout << arr2new[i] << " ";
		}
		fout << '\n';
		fout << N << '\n';
		for (int i = 0; i < N; i++) {
			fout << arr1new[i] << " ";
		}
	}

	else {
		std::cout << "Файлы in.txt или out.txt не открыты" << std::endl;
	}
}
