#include <iostream>
using namespace std;
void nome() 
{
	string nome;
	cout << "Digite seu nome: \n";
	cin >> nome;
	cout << "Oi " << nome << ", como vai voce ?\n\n";
}
int main() {
	nome();
	return 0;
}
