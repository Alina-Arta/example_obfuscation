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
void sort(int size, int A[], bool progress) 
{
	// поиск простого числа М
	int M = 1;
	int* S = new int[size + 1];
	S[1] = 0;

	for (int i = 2; i < size + 1; i++) {
		S[i] = 1;
		if (progress) {
			show_progress(kol, size);
			kol++;
		}
	}
	int i = 2; int z = 0;
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

	for (i = size; i > -1; i--) {
		if (S[i] == 1) {
			M = i;
			i = -1;
		}
	}

	// пропускаем весь массив через хеш-функцию
	Node* List[PAR_K];
	for (i = 0; i < size; i++) {
		List[i] = NULL;
		if (progress) {
			show_progress(kol, size);
			kol++;
		}
	}
	kol++;

	for (int j = 0; j < size; j++) {
		z = A[j] % M;
		int f = 0;
		for (i = 0; i < size && f == 0; i++) {
			//если список еще пуст
			if (List[i] == NULL) {
				List[i] = new Node;
				//добавление корня
				List[i]->key = z;
				List[i]->next = NULL;
				//добавление ключа
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

	kol++;
	i = 0;
	cout << "\n";

	//вывод на экран
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

	//ввод поискового числа
	int r;
	cin >> r;
	int kl = r % M;
	double fl = false;

	// поиск
	for (int g = 0; List[g] != NULL && !fl; g++) {
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

	if (progress && kol2 != size + 1) {
		while (kol2 != size + 1)
			if (progress) {
				show_progress2(kol2, size);
				kol2++;
			}
	}
	cout << "\n";

	cout << "\n";
	if (fl == true)cout << "YES";
	else cout << "NO ";
}

int main() {

	unsigned int size;
	flag = false;

	setlocale(LC_ALL, "RUS");

	cout << "----------------===/// hash function \\\\\\===----------------" << endl;
	cout << "Enter the size of the arrayenter the size of the array:\n> ";

	cin >> size;

	int A[PAR_K];
	fill_random(size, A);
	sort(size, A, true);
	int i;
	cin >> i;

}