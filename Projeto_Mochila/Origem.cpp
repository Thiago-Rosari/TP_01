// Problema da mochila

#include <iostream>
#include <windows.h>
#include "binario.h"     // chamando os arquivos ".h" das funções binárias
#include "genetico.h"    // chamando os arquivos ".h" das funçoes genéticas
using namespace std;

// exercico de revisão lab 06  
// definindo as cores 
#define red "\033[31m"
#define green "\033[32m"
#define default "\033[m"


int main()
{
	SetConsoleCP(1252); // acentos
	SetConsoleOutputCP(1252); // acentos

	unsigned short valorum, valordois, valortres, valorquatro, valorcinco, valorseis;

	cout << "Entre com 6 soluções iniciais (números entre 0 e 65535): " << endl;
	cin >> valorum;
	cin >> valordois;
	cin >> valortres;
	cin >> valorquatro;
	cin >> valorcinco;
	cin >> valorseis;

	system("cls");  // limpar tela

	cout << "  Resultado da Avaliação " << endl;
	cout << " ------------------------" << endl;

	/*

	  Levando em consieração que o peso máximo suportado pela mochila é 20 Kg => devemos usar a função avaliar
	  Usando função avaliar => retorna true se o valor for menor ou igual ao máximo permitido dentro da mochila
	  Retorna false se o valor for maior do que a mochila consegue comportar

	*/

	if (funcaoavaliar(valorum) == true)
		cout << green << "OK" << endl << default;   // Se o valor retornardo for true => escreve "OK" com a cor verde
	else
		cout << red << "X" << endl << default;      // Se o valor retornado for false => escreve "X" com a cor vermelha

	if (funcaoavaliar(valordois) == true)
		cout << green << "OK" << endl << default;   // definindo cores com o "green" e voltando para o normal com o "default"
	else
		cout << red << "X" << endl << default;      // definindo cores com o "red" e voltando para o normal como o "default" 


	if (funcaoavaliar(valortres) == true)           // testando para os restantes do valores iniciais (valortres)
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	if (funcaoavaliar(valorquatro) == true)         // testando para os restantes do valores iniciais (valorquatro)
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	if (funcaoavaliar(valorcinco) == true)         // testando para os restantes do valores iniciais (valorcinco)
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	if (funcaoavaliar(valorseis) == true)          // testando para os restantes do valores iniciais (valorseis) 
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	cout << " ------------------------" << endl;          // pulando para a poxima etapa => (usando variações das soluções iniciais)



	// chamando outras funções dentro da função avaliar => avaliar os novos resultados derivados das mutações e cruzamentos 


	if (funcaoavaliar(cruzamentopontounico(valorum, valordois)) == true)     // Avaliando e usando a função cruzamento de ponto único 
		cout << green << "OK" << endl << default;                           // gera uma nova solução a partir de duas soluções existentes, 
	else                                                                    // copiando parte dos bits da primeira solução e o restante da
		cout << red << "X" << endl << default;                              // segunda solução.


	if (funcaoavaliar(cruzamentoaritmetico(valortres, valorquatro)) == true)   // Avaliando e usando a função cruzamneto aritmetico 
		cout << green << "OK" << endl << default;                             // gera uma nova solução a partir de duas existentes,
	else                                                                      // usando o bit 1 nas posições em que ambas soluções iniciais sejam 1 
		cout << red << "X" << endl << default;                               // e 0, caso contrário. Ou seja, aplica um "AND" entre as soluções


	if (funcaoavaliar(mutacaosimples(valorcinco)) == true)               //Avaliando e usando a função mutação simples 
		cout << green << "OK" << endl << default;                        //mutação simples modifica um bit de uma solução existente,
	else                                                                 //obtendo assim uma nova solução
		cout << red << "X" << endl << default;


	if (funcaoavaliar(mutacaodupla(valorseis)) == true)                  //Avaliando e usando a função mutação dupla 
		cout << green << "OK" << endl << default;                        //a mutação dupla tem o mesmo comportamento da simples,
	else                                                                 //solução tem dois bits modificados, no lugar de apenas um.
		cout << red << "X" << endl << default;


	system("pause");
	return 0;

}