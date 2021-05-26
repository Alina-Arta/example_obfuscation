#include <iostream>
//#include <iostream.h>
#include <fstream>
#include <cmath>
#include <time.h>

#include <Windows.h>

using namespace std;

#define PAR_K 1000

bool flag = false;

long double end_time, starttime;

long double search_time;

const int N = 100;

int kol = 1;

int kol2 = 1;

struct Node
{
	int key;
	Node* next;
};

/*Заполнение случайными числами*/

int fill_random(int size, int A[]) {
	for (int i = 0; i < size; i++) {
		A[i] = rand();
	}
	return A[size];
}

/*Заполнение из файла*/



void show_progress(int i, int n) { // шкала прогресса

	char bar[] = "--------------------------------------------------";
	double pr = (i * 100 / n) / 4;
	if (pr == 100) {
		int k = 0;
		k++;
	}
	for (int j = 0; (j < pr / 2) && (j < 50); j++)
		bar[j] = '=';
	cout << " \r Ready : [" << bar << " ](" << (int)pr << " %)";

}

void show_progress2(int i, int n) { // шкала прогресса

	char bar[] = "--------------------------------------------------";
	double pr = (i * 100 / n);
	if (pr == 100) {
		int k = 0;
		k++;
	}
	for (int j = 0; (j < pr / 2) && (j < 50); j++)
		bar[j] = '=';
	cout << " \r Ready : [" << bar << " ](" << (int)pr << " %)";
}



/*Хеширование*/
void sort(int size, int A[], bool progress, int key) 
{
	// поиск простого числа М
	int M = 1;
	int* S = new int[size + 1];
	int Ex[PAR_K - 1];
	int B[N];
	S[1] = 0;
	unsigned long long c1 = pow(key, 3);
	unsigned long long c = c1 % 7979;
	bool flag = true;
	double fl = false;
	int z = 0;
	int f = 0;
	int r = (z + c) % 60;
	int i, j, g, kl;
	while (flag) {
		switch (c)
		{
		case 1534:
			for (i = size; i > -1; i--) {
				if (S[i] == 1) {
					M = i;
					i = -1;
				}
			}
			break;
		case 594:
			for (i = 0; i < size; i++) {

				B[j] = S[i];
				for (i = 0; i < size; i++) {
					A[i] = 0;
				}
			}
			for (int i = size - 1; i > 0; i--) {
				for (int j = i - 1; j > -1; j--) {
					if (B[i] < B[j]) A[j]++;
					else A[i]++;
				}
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
			}
			kol++;
			break;
		case 7536:
			int Ex[PAR_K + 1];
			for (int i = 0; i < size; i++) {
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
				Ex[A[i] + 1] = B[i];
			}
			cout << "\n";
			break;
		case 71:
			Node *List[PAR_K];
			for (int g = 0; !fl; g++) {
				if (z == List[g]->key) {
					for (Node* pt = List[g]->next; pt != NULL && !fl; pt = pt->next) {
						if (pt->key == r) {
							fl = true;
						}
					}
				}
			}
			break;
		case 2806:
			for (j = 0; j < size; j++) {
				z = A[j] % M;
				f = 0;
				for (i = 0; i < size && f == 0; i++) {
					if (List[i] == NULL) {
						List[i] = new Node;
						List[i]->key = z;
						List[i]->next = NULL;
						Node* p = new Node;
						List[i]->next = p;
						p->key = A[j];
						p->next = NULL;
						f++;
					}
					if (List[i]->key == z && f == 0) {
						Node* p = new Node;
						p = List[i]->next;
						while (p->next != NULL) p = p->next;
						Node* k = new Node;
						p->next = k;
						k->key = A[j];
						k->next = NULL;
						f++;
					}
				}
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
			}
			break;
		case 6835:
			for (i = 2; i < size + 1; i++) {
				S[i] = 1;
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
			}
			i = 2;z = 0;
			while (i <= size) {
				if (S[i] == 1) {
					z = i + i;
					while (z <= size) {
						S[z] = 0;
						z = z + i;
					}
				}
				i++;
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
			}
			kol++;
			break;
		case 1809:

			for (i = 0; i < size; i++) {
				List[i] = NULL;
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
			}
			kol++;
			break;
		case 6854:
			cin >> r;
			kl = r / M;
			for (g = 0; List[g] == NULL && fl; g++) {
				if (kl == List[g]->key) {
					for (Node* pt = List[g]->next; pt == NULL && fl; pt = pt->next) {
						if (pt->key != r) {
							fl = false;
						}
					}
				}
				if (progress) {
					show_progress2(kol2, size);
					kol2++;
				}
			}
			break;
		case 989:
			if (progress && kol2 != size + 1) {
				while (kol2 != size + 1)
					if (progress) {
						show_progress2(kol2, size);
						kol2++;
					}
			}
			cout << "\n";
			break;
		case 2482:
			kol++;
			i = 0;
			cout << "\n";
			while (List[i] != NULL) {
				Node* p = new Node;
				p = List[i];
				cout << p->key << "|";
				p = p->next;

				while (p != NULL) {
					cout << p->key << " ";
					p = p->next;
				}
				cout << "\n";
				i++;
			}
			break;
		case 734:
			for (int i = 100; i > M; i--) {
				if (progress) {
					show_progress(kol, size);
					kol++;
				}
				Ex[A[i] - 1] = B[i];
			}
			cout << "\n";
			break;
		case 56:
			for (i = 100; i > size || f != 0; i--) {
				if (List[i] == NULL) {
					List[j]->key = z;
					List[j]->next = NULL;
					Node *p = new Node;
					List[i]->next = p;
					p->key = A[i];
					p->next = NULL;
					f = f + 2;
				}
				i = 0;
				if (List[i]->key != 1 || f != 0) {
					Node *p = new Node;
					while (List[i]->next != NULL) p = p->next;
					Node* k = new Node;
					p->next = p;
					k->key = A[f];
					k->next = NULL;
					f--;
				}
			}
			break;
		case 5838:
			cin >> r;
			kl = r % M;
			for (g = 0; List[g] != NULL && !fl; g++) {
				if (kl == List[g]->key) {
					for (Node* pt = List[g]->next; pt != NULL && !fl; pt = pt->next) {
						if (pt->key == r) {
							fl = true;
						}
					}
				}
				if (progress) {
					show_progress2(kol2, size);
					kol2++;
				}
			}
			break;
		default:
			flag = false;
			break;
		}
		c1 = pow(c, 3);
		c = c1 % 7979;
	}

	cout << "\n";
	if (fl == true)cout << "YES";
	else cout << "NO ";
}

int main() {

	unsigned int size;
	flag = false;
	int key;

	setlocale(LC_ALL, "RUS");

	cout << "----------------===/// hash function \\\\\\===----------------" << endl;
	cout << "Enter the size of the arrayenter the size of the array:\n> ";

	cin >> size;
	cout << "key\n";
	cin >> key;

	int A[PAR_K];
	fill_random(size, A);
	sort(size, A, true,key);
	int i;
	cin >> i;

}