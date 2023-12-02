unsigned short OrBinario(unsigned short numeroum, unsigned short numerodois)
{
	unsigned short ResultadoOr;		          //atribuindo resultado a uma varialvel para retornar 
	ResultadoOr = (numeroum | numerodois);    //Calculo da or
	return ResultadoOr;
}

unsigned short Andbinario(unsigned short numeroum, unsigned short numerodois)
{
	unsigned short resultadoand;            //atribuindo resultado a uma varialvel para retornar
	resultadoand = (numeroum & numerodois); // Calculo do AND
	return resultadoand;

}
unsigned short LigarBit(unsigned short numeroum, unsigned short posicaoligar)
{
	unsigned short resultadoLigarBit;	                         //atribuindo resultado a uma varialvel para retornar
	unsigned short mascara = posicaoligar;                      //atribuindo posição = mascara
	resultadoLigarBit = OrBinario(numeroum, 1 << mascara);     // Deslocando e aplicando um or, como visto na aula 

	return resultadoLigarBit;
}

unsigned short DesligarBit(unsigned short numeroum, unsigned short posicaodesligar)
{
	unsigned short mascara;
	mascara = posicaodesligar;                                        //atribuindo posição = mascara
	unsigned short resultadoDesligarBit;                             //atribuindo resultado a uma varialvel para retornar

	resultadoDesligarBit = Andbinario(numeroum, ~(1 << mascara));   // Deslocando, Negando e aplicando um AND entre o numero e a mascara negada,
	//como visto na aula
	return resultadoDesligarBit;
}

bool TestarBit(unsigned short valor, unsigned short posição)
{
	// muito parecido com a questão 5 do lab07

	if (valor > DesligarBit(valor, posição))
		return true;                     //retorna 1 (true)
	else
		return false;                    //retorna 0 (false)

}

unsigned short BitsBaixos(unsigned short numerodois)
{
	unsigned short calculobaixos = 0;

	// pega os 8 menores bits
	// deslocando (numeros dos bits) e fazendo um and com o numero digitado pelo usuário
	// achando somente os menores
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 0));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 1));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 2));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 3));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 4));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 5));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 6));
	calculobaixos = calculobaixos + Andbinario(numerodois, (1 << 7));

	return calculobaixos;
}

unsigned short BitsAltos(unsigned short numeroum)
{
	unsigned short calculoaltos = 0;
	// usando exercicio de fixação 05 do lab 07 como base
	// pega os 8 maiores bits
	// deslocando (numeros dos bits) e fazendo um and com o numero digitado pelo usuário,
	// da mesma forma que o anterior, apenas deslocando posições diferentes
	// achando somente os maiores

	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 8));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 9));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 10));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 11));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 12));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 13));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 14));
	calculoaltos = calculoaltos + Andbinario(numeroum, (1 << 15));

	return calculoaltos;      // usando exercicio lab 07 para converter para binario
}