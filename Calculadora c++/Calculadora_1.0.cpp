#include <iostream>
#include <cmath>
#include <tchar.h>
#include <iomanip>
#include <locale.h>

using namespace std;

//======================================================
// MENU
//======================================================

void Menu()
{
	std::cout << "============================================ " << endl;
	std::cout << "=====     CALCULADORA DE BATALHA TW    ===== " << endl;
	std::cout << "============================================ " << endl;
	std::cout << endl;
}

//======================================================
// FUNÇÕES DE SAUDE
//======================================================

		/* Formula de saude (exceto soldado)*/
int saudefull(int saude, int LevelPersonagem)
{
	int saudef;
	saudef = (saude * 10) + (LevelPersonagem * 10) + 90;
	return saudef;
};
		/*Formula de saude (soldado sem premium)*/
int saude_Soldado(int saude, int LevelPersonagem)
{
	int saudeS;
	saudeS = (saude * 15) + (LevelPersonagem * 10) + 90;

	return saudeS;
};
		/*Formula de saude (soldado com premium)*/
int saude_SoldadoP(int saude, int LevelPersonagem)
{
	int saudeP;
	saudeP = (saude * 20) + (LevelPersonagem * 10) + 90;

	return saudeP;
}

//======================================================
//FUNCOES DE DANO
//======================================================

		/*FUNÇÃO DE DANO MINIMO*/
float dano_Minimo(int danoMinimo, int lideranca, int saude, int LevelPersonagem, int danobonus)
{
	/*formula dano*/
	/*Dano da Arma + Danos Setor + [(Dano da Arma + Danos Setor) � Lideran�a � MaxHP]*/
	int x;
	float danoarma;
	x = saudefull(saude, LevelPersonagem);
	danoarma = (danoMinimo + danobonus + ((danoMinimo)*lideranca / x));
	return danoarma;
};

		/*FUNÇÃO DE DANO MAXIMO*/
float dano_Maximo(int danoMaximo, int lideranca, int saude, int LevelPersonagem, int danobonus)
{
	/*formula dano*/
	/*Dano da Arma + Danos Setor + [(Dano da Arma + Danos Setor) � Lideran�a � MaxHP]*/
	int x;
	float danoarma;
	x = saudefull(saude, LevelPersonagem);
	danoarma = (danoMaximo + danobonus + ((danoMaximo)*lideranca / x));
	return danoarma;
};

		/*FUNÇÃO DE DANO MEDIO */
float dano_Medio(int danoMinimo, int danoMaximo, int lideranca, int saude, int LevelPersonagem, int danobonus)
{
	/*formula dano*/
	/*Dano da Arma + Danos Setor + [(Dano da Arma + Danos Setor) � Lideran�a � MaxHP]*/
	int x;
	float danomedioarma, danoarma;
	x = saudefull(saude, LevelPersonagem);
	danomedioarma = ((danoMaximo + danoMinimo) / 2);
	danoarma = (danomedioarma + danobonus + ((danomedioarma * lideranca) / x));
	return danoarma;
};

		/*FUNÇÕES DE DANO SOLDADO*/

		//Premium
float dano_Minimo_Soldado_Premium(int danoMinimo, int lideranca, int saude, int levelPersonagem, int danobonus)
{
	int x;
	float danoarma;
	x = saude_SoldadoP(saude, levelPersonagem);
	danoarma = (danoMinimo + danobonus + (((danoMinimo) * (lideranca * 1.5)) / x));

	return danoarma;
}
float dano_Maximo_Soldado_Premium(int danoMaximo, int lideranca, int saude, int levelPersonagem, int danobonus)
{
	int x;
	float danoarma;
	x = saude_SoldadoP(saude, levelPersonagem);
	danoarma = (danoMaximo + danobonus + (((danoMaximo) * (lideranca * 1.5)) / x));

	return danoarma;
}
float dano_Medio_Soldado_Premium(int danoMinimo, int danoMaximo, int lideranca, int saude, int levelPersonagem, int danobonus)
{
	int x;
	float danoarma, danomedioarma;
	x = saude_SoldadoP(saude, levelPersonagem);
	danomedioarma = ((danoMaximo + danoMinimo) / 2);
	danoarma = (danomedioarma + danobonus + (((danomedioarma) * (lideranca * 1.5)) / x));

	return danoarma;
}

		//Sem Premium
float dano_Minimo_Soldado(int danoMinimo, int lideranca, int saude, int levelPersonagem, int danobonus)
{
	int x;
	float danoarma;
	x = saude_Soldado(saude, levelPersonagem);
	danoarma = (danoMinimo + danobonus + (((danoMinimo) * (lideranca * 1.25)) / x));

	return danoarma;
}
float dano_Maximo_Soldado(int danoMaximo, int lideranca, int saude, int levelPersonagem, int danobonus)
{
	int x;
	float danoarma;
	x = saude_Soldado(saude, levelPersonagem);
	danoarma = (danoMaximo + danobonus + (((danoMaximo) * (lideranca * 1.25)) / x));

	return danoarma;
}
float dano_Medio_Soldado(int danoMinimo, int danoMaximo, int lideranca, int saude, int levelPersonagem, int danobonus)
{
	int x;
	float danoarma, danomedioarma;
	x = saude_Soldado(saude, levelPersonagem);
	danomedioarma = ((danoMaximo + danoMinimo) / 2);
	danoarma = (danomedioarma + danobonus + (((danomedioarma) * (lideranca * 1.5)) / x));

	return danoarma;
}

//======================================================
// FUNÇÕES DE RESISTENCIA
//======================================================

		// FUNÇAO RESISTENCIA ATAQUE
float resistAtaque(int esconder, int saude, int LevelPersonagem, int resistencia)
{
	/*300 � (habilidade esconder ou habilidade colocar armadilhas) � Hp total + bonus de roupas em resistencia para batalha de forte(n�o a habilidade resistencia)*/
	int x;
	float Resi;
	x = saudefull(saude, LevelPersonagem);
	Resi = (300 * esconder / x + resistencia);
	std::cout << "[RESISTENCIA] o valor da RESISTENCIA é: "
			  << "  " << Resi << endl;
	return Resi;
};

		// FUNÇÃO RESISTENCIA DEFESA
float resistDefesa(int armadilha, int saude, int LevelPersonagem, int resistencia)
{
	/*300 � (habilidade esconder ou habilidade colocar armadilhas) � Hp total + bonus de roupas em resistencia para batalha de forte(n�o a habilidade resistencia)*/
	int x;
	float Resi;
	x = saudefull(saude, LevelPersonagem);
	Resi = (300 * armadilha / x + resistencia);
	std::cout << "[RESISTENCIA] o valor da RESISTENCIA é: "
			  << "  " << Resi << endl;
	return Resi;
};

//======================================================
// FUNÇÕES DE ACERTO
//======================================================

		// ACERTO PADRAO AVENT E PISTOL ATAQUE
float valorAtaqueAA(int lideranca, int mira, int esconder, int acertobonus)
{
	float Avalorataque;

	Avalorataque = pow(lideranca, 0.5) + pow(mira, 0.5) + pow(esconder, 0.6) + acertobonus + 25;
	std::cout << "[ATAQUE] o valor de ACERTO é: "
			  << "  " << Avalorataque << endl;

	return Avalorataque;
};

		// ACERTO PADRAO AVENT E PISTOL DEFESA
float valorAtaqueDD(int lideranca, int mira, int armadilha, int acertobonus)
{

	float Dvalorataque;

	Dvalorataque = pow(lideranca, 0.5) + pow(mira, 0.5) + pow(armadilha, 0.6) + acertobonus + 25;
	std::cout << "[DEFESA] o valor de ACERTO é: "
			  << "  " << Dvalorataque << endl;

	return Dvalorataque;
}

		// ACERTO PADRAO SOLDADO (Sem premium) ATAQUE
float valorAtaqueAASOLS(int lideranca, int mira, int esconder, int acertobonus)
{
	float Avalorataque;

	Avalorataque = pow((lideranca * 1.25), 0.5) + pow(mira, 0.5) + pow(esconder, 0.6) + acertobonus + 25;
	cout << "[ATAQUE] o valor de ataque �: "
		 << "  " << Avalorataque << endl;

	return Avalorataque;
};

		// ACERTO PADRAO SOLDADO (com premium) ATAQUE
float valorAtaqueAASOLP(int lideranca, int mira, int esconder, int acertobonus)
{
	float Avalorataque;

	Avalorataque = pow(((lideranca * 1.5)), 0.5) + pow(mira, 0.5) + pow(esconder, 0.6) + acertobonus + 25;
	cout << "[ATAQUE] o valor de ataque é: "
		 << "  " << Avalorataque << endl;

	return Avalorataque;
};

		// ACERTO PADRAO SOLDADO (SEM PREMIUM) DEFESA
float valorAtaqueDDSOLS(int lideranca, int mira, int armadilha, int acertobonus)
{
	float Dvalorataque;

	Dvalorataque = pow((lideranca * 1.25), 0.5) + pow(mira, 0.5) + pow(armadilha, 0.6) + acertobonus + 25;
	cout << "[DEFESA] o valor de ACERTO é: "
		 << "  " << Dvalorataque << endl;

	return Dvalorataque;
}

		// ACERTO PADRAO SOLDADO (COM PREMIUM) DEFESA
float valorAtaqueDDSOLP(int lideranca, int mira, int armadilha, int acertobonus)
{
	float Dvalorataque;

	Dvalorataque = pow((lideranca * 1.5), 0.5) + pow(mira, 0.5) + pow(armadilha, 0.6) + acertobonus + 25;
	cout << "[DEFESA] o valor de ACERTO é: "
		 << "  " << Dvalorataque << endl;

	return Dvalorataque;
}

		// ACERTO PADRAO WORK (SEM PREMIUM) ATAQUE
float valorAtaqueAAWS(int lideranca, int mira, int esconder, int acertobonus)
{
	float Avalorataque;
	Avalorataque = ((pow(lideranca, 0.4) + pow(mira, 0.4) + pow(esconder, 0.4) + acertobonus + 25) * 1.2);
	std::cout << "[ATAQUE] o valor de Acerto é: "
			  << "  " << Avalorataque << endl;

	return Avalorataque;
}

		// ACERTO PADRAO WORK (COM PREMIUM) ATAQUE
float valorAtaqueAAWP(int lideranca, int mira, int esconder, int acertobonus)
{
	float Avalorataque;
	Avalorataque = ((pow(lideranca, 0.4) + pow(mira, 0.4) + pow(esconder, 0.4) + acertobonus + 25) * 1.4);
	std::cout << "[ATAQUE] o valor de Acerto é: "
			  << "  " << Avalorataque << endl;

	return Avalorataque;
}

		// ACERTO PADRAO WORK (SEM PREMIUM) DEFESA
float valorAtaqueDDWS(int lideranca, int mira, int armadilha, int acertobonus)
{
	float Dvalorataque;
	Dvalorataque = ((pow(lideranca, 0.4) + pow(mira, 0.4) + pow(armadilha, 0.4) + acertobonus + 25) * 1.2);
	std::cout << "[ATAQUE] o valor de Acerto é: "
			  << "  " << Dvalorataque << endl;

	return Dvalorataque;
}

		// ACERTO PADRAO WORK (COM PREMIUM) DEFESA
float valorAtaqueDDWP(int lideranca, int mira, int armadilha, int acertobonus)
{
	float Dvalorataque;
	Dvalorataque = ((pow(lideranca, 0.4) + pow(mira, 0.4) + pow(armadilha, 0.4) + acertobonus + 25) * 1.4);
	std::cout << "[ATAQUE] o valor de Acerto é: "
			  << "  " << Dvalorataque << endl;

	return Dvalorataque;
}

//======================================================
// FUNCOES DE DESVIO
//======================================================

		// DESVIO PADRAO AVENT E PISTOL ATAQUE
float valorDefesaAA(int lideranca, int esconder, int evasao, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = pow(lideranca, 0.5) + pow(evasao, 0.5) + pow(esconder, 0.6) + desviobonus + 10;
	cout << "[ATAQUE] o valor do DESVIO é: "
		 << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
};

		// DESVIO PADRAO AVENT E PISTOL Defesa
float valorDefesaDD(int lideranca, int armadilha, int evasao, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = pow(lideranca, 0.5) + pow(evasao, 0.5) + pow(armadilha, 0.6) + desviobonus + 10;
	cout << "[DEFESA] o valor do DESVIO é: "
		 << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
};

		// DESVIO PADRAO SOLDADO (Sem premium) ATAQUE
float valorDefesaAASOLS(int lideranca, int esconder, int evasao, int desviobonus)
{
	float DvalorDefesa;

	DvalorDefesa = pow((lideranca * 1.25), 0.5) + pow(evasao, 0.5) + pow(esconder, 0.6) + desviobonus + 10;
	cout << "[ATAQUE] o valor do DESVIO é: "
		 << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
};

		// DESVIO PADRAO SOLDADO (com premium) ATAQUE
float valorDefesaAASOLP(int lideranca, int esconder, int evasao, int desviobonus)
{
	float DvalorDefesa;

	DvalorDefesa = pow((lideranca * 1.5), 0.5) + pow(evasao, 0.5) + pow(esconder, 0.6) + desviobonus + 10;
	cout << "[ATAQUE] o valor do DESVIO é: "
		 << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
};

		// DESVIO PADRAO SOLDADO (SEM PREMIUM) DEFESA
float valorDefesaDDSOLS(int lideranca, int armadilha, int evasao, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = pow((lideranca * 1.25), 0.5) + pow(evasao, 0.5) + pow(armadilha, 0.6) + desviobonus + 10;
	std::cout << "[DEFESA] o valor do DESVIO é: "
			  << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
}

		// DESVIO PADRAO SOLDADO (COM PREMIUM) DEFESA
float valorDefesaDDSOLP(int lideranca, int armadilha, int evasao, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = pow((lideranca * 1.5), 0.5) + pow(evasao, 0.5) + pow(armadilha, 0.6) + desviobonus + 10;
	std::cout << "[DEFESA] o valor do DESVIO é: "
			  << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
}

		// DESVIO PADRAO WORK (SEM PREMIUM) ATAQUE
float valorDefesaAAWS(int lideranca, int evasao, int esconder, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = ((pow(lideranca, 0.4) + pow(evasao, 0.4) + pow(esconder, 0.4) + desviobonus + 10) * 1.2);
	std::cout << "[ATAQUE] o valor do DESVIO é: "
			  << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
}

		// DESVIO PADRAO WORK (COM PREMIUM) ATAQUE
float valorDefesaAAWP(int lideranca, int evasao, int esconder, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = ((pow(lideranca, 0.4) + pow(evasao, 0.4) + pow(esconder, 0.4) + desviobonus + 10) * 1.4);
	std::cout << "[ATAQUE] o valor do DESVIO é: "
			  << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
}

		// DESVIO PADRAO WORK (SEM PREMIUM) DEFESA
float valorDefesaDDWS(int lideranca, int evasao, int armadilha, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = ((pow(lideranca, 0.4) + pow(evasao, 0.4) + pow(armadilha, 0.4) + desviobonus + 10) * 1.2);
	std::cout << "[DEFESA] o valor do DESVIO é: "
			  << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
}

		// DESVIO PADRAO WORK (COM PREMIUM) DEFESA
float valorDefesaDDWP(int lideranca, int evasao, int armadilha, int desviobonus)
{
	float DvalorDefesa;
	DvalorDefesa = ((pow(lideranca, 0.4) + pow(evasao, 0.4) + pow(armadilha, 0.4) + desviobonus + 10) * 1.4);
	std::cout << "[DEFESA] o valor do DESVIO é: "
			  << "  " << DvalorDefesa << endl;

	return DvalorDefesa;
}

//======================================================
// FUNÇÃO PERGUNTA BONUS
//======================================================

void bonus(int danobonus, int acertobonus, int desviobonus, string resposta)
{
	if ((resposta == "SIM") || (resposta == "sim") || (resposta == "Sim"))
	{
		cout << "Insira o valor do bonus de dano: " << endl;
		cin >> danobonus;
		cout << "Insira o valor do bonus de acerto: " << endl;
		cin >> acertobonus;
		cout << "Insira o valor do bonus de desvio: " << endl;
		cin >> desviobonus;
	}
}

//======================================================
// FUNÇÃO DE CLASSE
//======================================================

void fclasse(int danoMinimo, int danoMaximo, int danobonus, int acertobonus, int desviobonus, string classe, string premium, int saude, int LevelPersonagem, int lideranca, int mira, int esconder, int armadilha, int evasao, int resistencia)
{

	//ENTRADA NOME DA CLASSE
	cout << "Insira a Classe do seu Personagem (AVENT // SOLDADO // WORK // PISTOL): ";
	cin >> classe;
	cout << '\n'
		 << '\n';

	// caso for aventureiro
	if ((classe == "AVENT") || (classe == "avent") || (classe == "Avent"))
	{
		//Saida de hp
		cout << "A quantidade de HP maxímo é : " << saudefull(saude, LevelPersonagem) << endl;

		//Saida de % (acerto e desvio) Ataque
		valorAtaqueAA(lideranca, mira, esconder, acertobonus);
		valorDefesaAA(lideranca, esconder, evasao, desviobonus);
		resistAtaque(esconder, saude, LevelPersonagem, resistencia);

		cout << '\n'
			 << '\n';

		//Saida de % (acerto e desvio) Defesa
		valorAtaqueDD(lideranca, mira, armadilha, acertobonus);
		valorDefesaDD(lideranca, armadilha, evasao, desviobonus);
		resistDefesa(armadilha, saude, LevelPersonagem, resistencia);
		cout << '\n'
			 << '\n';

		//Saida de Dano
		cout << "=================|[DANO]|================" << endl;
		cout << "[DANO]"
			 << "||   " << dano_Minimo(danoMinimo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MINIMO" << fixed << setprecision(0) << endl;
		cout << "[DANO]"
			 << "||   " << dano_Medio(danoMinimo, danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MEDIO" << fixed << setprecision(0) << endl;
		cout << "[DANO]"
			 << "||   " << dano_Maximo(danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MAXIMO" << fixed << setprecision(0) << endl;
		cout << "=========================================" << endl;

		system("PAUSE");
	}
	// caso for soldado
	if ((classe == "SOLDADO") || (classe == "Soldado") || (classe == "soldado"))
	{
		// Uso de Premium
		cout << "Personagem Possui Premium? (SIM / NAO): ";
		cin >> premium;

		//Informações Soldado com Premium
		if ((premium == "SIM") || (premium == "Sim") || (premium == "sim"))
		{
			cout << '\n'
				 << '\n';

			//Saida do hp (soldado)
			cout << "A quantidade de HP Maxímo é: " << saude_SoldadoP(saude, LevelPersonagem) << endl;

			//Saida de % (acerto e desvio) Ataque
			valorAtaqueAASOLP(lideranca, mira, esconder, acertobonus);
			valorDefesaAASOLP(lideranca, esconder, evasao, desviobonus);

			cout << '\n'
				 << '\n';

			//Saida de % (acerto e desvio) Defesa
			valorAtaqueDDSOLP(lideranca, mira, armadilha, acertobonus);
			valorDefesaDDSOLP(lideranca, armadilha, evasao, desviobonus);

			cout << '\n'
				 << '\n';

			//Saida de Dano
			cout << "=================|[DANO]|================" << endl;
			cout << "[DANO]"
				 << "||   " << dano_Minimo_Soldado_Premium(danoMinimo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
				 << "MINIMO" << fixed << setprecision(0) << endl;
			cout << "[DANO]"
				 << "||   " << dano_Medio_Soldado_Premium(danoMinimo, danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
				 << "MEDIO" << fixed << setprecision(0) << endl;
			cout << "[DANO]"
				 << "||   " << dano_Maximo_Soldado_Premium(danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
				 << "MAXIMO" << fixed << setprecision(0) << endl;
			cout << "=========================================" << endl;
		}

		//Informações Soldado sem premium
		else if ((premium == "NAO") || (premium == "Nao") || (premium == "nao"))
		{
			cout << "saude soldado: " << saude_Soldado(saude, LevelPersonagem) << endl;
			valorAtaqueAASOLS(lideranca, mira, esconder, acertobonus);
		}
	}
	// caso for work
	if ((classe == "WORK") || (classe == "Work") || (classe == "work"))
	{
		cout << "Personagem Possui Premium? (SIM / NAO): ";
		cin >> premium;

		saudefull(saude, LevelPersonagem);

		if((premium == "SIM") || (premium == "Sim") || (premium == "sim"))
		{

			//Saida de hp
		cout << "A quantidade de HP maxímo é : " << saudefull(saude, LevelPersonagem) << endl;

		//Saida de % (acerto e desvio) Ataque
		valorAtaqueAA(lideranca, mira, esconder, acertobonus);
		valorDefesaAA(lideranca, esconder, evasao, desviobonus);
		resistAtaque(esconder, saude, LevelPersonagem, resistencia);

		cout << '\n'
			 << '\n';

		//Saida de % (acerto e desvio) Defesa
		valorAtaqueDD(lideranca, mira, armadilha, acertobonus);
		valorDefesaDD(lideranca, armadilha, evasao, desviobonus);
		resistDefesa(armadilha, saude, LevelPersonagem, resistencia);

		cout << '\n'
			 << '\n';

		//Saida de Dano
		cout << "=================|[DANO]|================" << endl;
		cout << "[DANO]"
			 << "||   " << dano_Minimo(danoMinimo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MINIMO" << fixed << setprecision(0) << endl;
		cout << "[DANO]"
			 << "||   " << dano_Medio(danoMinimo, danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MEDIO" << fixed << setprecision(0) << endl;
		cout << "[DANO]"
			 << "||   " << dano_Maximo(danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MAXIMO" << fixed << setprecision(0) << endl;
		cout << "=========================================" << endl;

		}
	
		else if((premium == "NAO") || (premium == "Nao") || (premium == "nao"))
		{

		}
	
	}
	// caso for pistol
	if ((classe == "PISTOL") || (classe == "Pistol") || (classe == "pistol"))
	{

		//Saida de hp
		cout << "A quantidade de HP maxímo é : " << saudefull(saude, LevelPersonagem) << endl;

		//Saida de % (acerto e desvio) Ataque
		valorAtaqueAA(lideranca, mira, esconder, acertobonus);
		valorDefesaAA(lideranca, esconder, evasao, desviobonus);
		resistAtaque(esconder, saude, LevelPersonagem, resistencia);

		cout << '\n'
			 << '\n';

		//Saida de % (acerto e desvio) Defesa
		valorAtaqueDD(lideranca, mira, armadilha, acertobonus);
		valorDefesaDD(lideranca, armadilha, evasao, desviobonus);
		resistDefesa(armadilha, saude, LevelPersonagem, resistencia);

		cout << '\n'
			 << '\n';

		//Saida de Dano
		cout << "=================|[DANO]|================" << endl;
		cout << "[DANO]"
			 << "||   " << dano_Minimo(danoMinimo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MINIMO" << fixed << setprecision(0) << endl;
		cout << "[DANO]"
			 << "||   " << dano_Medio(danoMinimo, danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MEDIO" << fixed << setprecision(0) << endl;
		cout << "[DANO]"
			 << "||   " << dano_Maximo(danoMaximo, lideranca, saude, LevelPersonagem, danobonus) << "   ||"
			 << "MAXIMO" << fixed << setprecision(0) << endl;
		cout << "=========================================" << endl;
	}
}

//======================================================
// FUNÇÃO PRINCIPAL
//======================================================

int main()
{
	// colocar ABNT
	setlocale(LC_ALL, "Portuguese");

	// inserir menu
	Menu();

	//declaração de variaveis
	string NomePersonagem, // Nome personagem
		premium,		   // Se possui premium ou nao
		classe,			   // classe do personagem
		resposta;		   // resposta se vai querer inserir bonus ou nao

	int LevelPersonagem = 1, //level do personagem
		danoMinimo = 0,		 // dano minimo da arma
		danoMaximo = 0,		 // dano maximo da arma
		armadilha = 0,		 // pontos de colocar armadilha
		saude = 0,			 // pontos em saude
		evasao = 0,			 // pontos em evasao
		esconder = 0,		 // pontos em esconder
		mira = 0,			 // pontos em mira
		lideranca = 0,		 // pontos em liderança
		danobonus = 0,		 // bonus de dano
		acertobonus = 0,	 // bonus de acerto
		desviobonus = 0;	 // bonus de desvio

	float resistencia; // valor da resistencia

	// ENTRADA DE VARIAVEIS
	//Entrada_Variaveis(NomePersonagem, LevelPersonagem, danoMinimo, danoMaximo, armadilha, saude, evasao, esconder, mira, lideranca, resistencia, resposta);

	cout << "Insira o Nome do Personagem:	";
	cin >> NomePersonagem;
	cout << "Insira o Level do Personagem:	";
	cin >> LevelPersonagem;
	cout << "Insira o Dano Minimo da Arma:	";
	cin >> danoMinimo;
	cout << "Insira o Dano Maximo da Arma:	";
	cin >> danoMaximo;
	cout << "Insira a Habilidade Colocar Armadilha:	";
	cin >> armadilha;
	cout << "Insira a Habilidade Pontos de Saude:	";
	cin >> saude;
	cout << "Insira a Habilidade Evasao:	";
	cin >> evasao;
	cout << "Insira a Habilidade Esconder:	";
	cin >> esconder;
	cout << "Insira a Habilidade Mira:	";
	cin >> mira;
	cout << "Insira a Habilidade Liderança:	";
	cin >> lideranca;
	cout << "Insira o Bonus de resistência: ";
	cin >> resistencia;
	cout << '\n';
	cout << "Deseja Inserir Algum Bonus Para o Personagem ? " << endl;
	cin >> resposta;
	cout << '\n';

	//entrada dos bonus
	bonus(danobonus, acertobonus, desviobonus, resposta);

	// funcao das classes
	fclasse(danoMinimo, danoMaximo, danobonus, acertobonus, desviobonus, classe, premium, saude, LevelPersonagem, lideranca, mira, esconder, armadilha, evasao, resistencia);

	return 0;
}