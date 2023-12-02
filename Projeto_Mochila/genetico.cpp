#include <iostream>
using namespace std;
#include "binario.h"


bool funcaoavaliar(unsigned short valoraseravalidado)
{
	// receber numero
   // exibir valor e peso da solução
   // retornar true se estiver dentro do peso certo 

	unsigned short valorprateste;
	valorprateste = valoraseravalidado;
	unsigned short peso;
	unsigned short valor;
	peso = 0;
	valor = 0;

	/*
	   fazendo cada bit para no final somar como no exemplo => 60504 =>  1110110001011000
	   na mochila temos =>
	   Objeto     A B C D E F G H I J K L M N O P
	   Peso (Kg) 12 3 5 4 9 1 2 3 4 1 2 4 5 2 4 1
	   Valor ($) 4 4 8 10 15 3 1 1 2 10 20 15 10 3 4 12

	   como 60504 =>  1110110001011000
	   temos =>       A,B,C,E,F,J,L,M ligados
	   logo, ficamos com A (12Kg+ 4$) + B (3Kg + 4$) + C (5Kg + 8$) + E (9Kg +15$) + F(1Kg +3$) + J (1Kg +10$) + L (4Kg + 15$) + M (5Kg + 10$)

	   somando apenas os Kg => (12 + 3 + 5 +  9 + 1 + 1 + 4 + 5) = 40 Kg
	   somando apenas os $  => (4 + 4 + 8 + 15 + 3 + 10 + 15 + 10) = 69$

	   Dessa forma temos 40 Kg e 69$ apenas com o primeiro número digitado
	   Devemos repetir esse processo para os demais numeros e para as novas soluções geradas
	   Repetimos esse processo por meio da sequência de "ifs" que estão abaixo
	*/

	if (TestarBit(valorprateste, 15) != 0)    //A principio tentei usar o maior ( > ) para avalaiar, mas como a função TestarBit é do tipo bool 
	{                                         //O visual studio acusava erro, por isso, tive que pesquisar um novo operador 
		peso = peso + 12;                     // " != " => NOT-equal-to = não idêntico 
		valor = valor + 4;                    //retorna true se os operandos não têm o mesmo valor, caso contrário, ele retorna false .
	}

	if (TestarBit(valorprateste, 14) != 0)    // avaliando cada bit no numero com base no que foi explicado acima (com os cálculos)
	{
		peso = peso + 3;
		valor = valor + 4;
	}


	if (TestarBit(valorprateste, 13) != 0)
	{
		peso = peso + 5;
		valor = valor + 8;
	}

	if (TestarBit(valorprateste, 12) != 0)
	{
		peso = peso + 4;
		valor = valor + 10;
	}

	if (TestarBit(valorprateste, 11) != 0)
	{
		peso = peso + 9;
		valor = valor + 15;
	}

	if (TestarBit(valorprateste, 10) != 0)
	{
		peso = peso + 1;
		valor = valor + 3;
	}

	if (TestarBit(valorprateste, 9) != 0)
	{
		peso = peso + 2;
		valor = valor + 1;
	}


	if (TestarBit(valorprateste, 8) != 0)
	{
		peso = peso + 3;
		valor = valor + 1;
	}

	if (TestarBit(valorprateste, 7) != 0)
	{
		peso = peso + 4;
		valor = valor + 2;
	}

	if (TestarBit(valorprateste, 6) != 0)
	{
		peso = peso + 1;
		valor = valor + 10;
	}


	if (TestarBit(valorprateste, 5) != 0)
	{
		peso = peso + 2;
		valor = valor + 20;
	}

	if (TestarBit(valorprateste, 4) != 0)
	{
		peso = peso + 4;
		valor = valor + 15;
	}


	if (TestarBit(valorprateste, 3) != 0)
	{
		peso = peso + 5;
		valor = valor + 10;
	}


	if (TestarBit(valorprateste, 2) != 0)
	{
		peso = peso + 2;
		valor = valor + 3;
	}

	if (TestarBit(valorprateste, 1) != 0)
	{
		peso = peso + 4;
		valor = valor + 4;
	}

	if (TestarBit(valorprateste, 0) != 0)

	{
		peso = peso + 1;
		valor = valor + 12;
	}

	cout << right; cout.width(6);        //definindo o espaçamento com o width mostrado em laboratorios
	cout << valoraseravalidado;          // para ficar com a formatação correta 
	cout << " - $";
	cout << valor;
	cout << " -";
	cout << right; cout.width(3);
	cout << peso;
	cout << "Kg - ";

	if (peso <= 20)            // peso máximo da mochila
		return true;           // retornando valor dependendo do que foi calculado acima
	else
		return false;

}

unsigned short cruzamentopontounico(unsigned short numeroum, unsigned short numerodois)
{
	unsigned short pontounicoresultado;
	pontounicoresultado = BitsBaixos(numerodois) + BitsAltos(numeroum);  //chamando a função BitsBaixos e Bitaltos
	//cruzamento ponto unico = metade de bits de um e metade de bits do outro
	return pontounicoresultado;

}

unsigned short cruzamentoaritmetico(unsigned short numerotres, unsigned short numeroquatro)
{
	unsigned short aritmeticoresultado;
	aritmeticoresultado = Andbinario(numerotres, numeroquatro);      // chamando a função Andbinario 
	return aritmeticoresultado;                                      // cruzamento aritmetico = AND entre dois valores 

}

unsigned short mutacaosimples(unsigned short numerocinco)
{
	// inverter bit 9 

	unsigned short mutacaosimplesresultado;
	if (TestarBit(numerocinco, 9) == 1)
		mutacaosimplesresultado = DesligarBit(numerocinco, 9);      // chamando a função TestarBit, DesligarBit e LigarBit
	else                                                            // se estiver ligado => fesliga 
		mutacaosimplesresultado = LigarBit(numerocinco, 9);         // se estiver desligado => Liga

	return mutacaosimplesresultado;
}

unsigned short mutacaodupla(unsigned short numeroseis)
{
	//inverter bit 12 e bit 3      

	unsigned short mutacaoduplaresultado;                          // chamando a função TestarBit, DesligarBit e LigarBit
	if (TestarBit(numeroseis, 3) == 0)                             // se estiver ligado => fesliga 
		mutacaoduplaresultado = LigarBit(numeroseis, 3);           // se estiver desligado => Liga
	else
		mutacaoduplaresultado = DesligarBit(numeroseis, 3);

	if (TestarBit(mutacaoduplaresultado, 12) == 0)                  //usando o resultado(mutacaoduplaresultado) para retornar só um valor no final 
		mutacaoduplaresultado = LigarBit(mutacaoduplaresultado, 12);
	else
		mutacaoduplaresultado = DesligarBit(mutacaoduplaresultado, 12);

	return mutacaoduplaresultado;

}