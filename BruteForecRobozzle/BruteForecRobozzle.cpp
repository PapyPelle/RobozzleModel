// BruteForecRobozzle.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

#include "Common.h"
#include "Field.h"
#include "Player.h"
#include "Executor.h"
#include "Generator.h"

void test1()
{
	const std::string data = "W  W  W  W  W  W  \n  W EB  B  B SB W  \n W  W  W  W  W  W  \n ";

	Field field = Field();
	field.parseField(data);

	int ret = 0;
	Executor exec = Executor(Orientation::E, field);

	// straight to the point
	exec.setExecution("BF BF BF");
	ret = exec.execute();
	std::cout << "returned : " << ret << std::endl;

	// useless steps to win
	exec.setExecution("BF BF GF GR BF");
	ret = exec.execute();
	std::cout << "returned : " << ret << std::endl;

	// wrong steps
	exec.setExecution("BF GF UR GC UF UF UF UF UF UF");
	ret = exec.execute();
	std::cout << "returned : " << ret << std::endl;

	// infinite
	exec.setExecution("BC");
	ret = exec.execute();
	std::cout << "returned : " << ret << std::endl;

}

void test11()
{
	const std::string data = "W  W  W  W  W  W  \n  W EB  B  B SB W  \n W  W  W  W  W  W  \n ";

	Field field = Field();
	field.parseField(data);

	int ret = 0;
	Executor exec = Executor(Orientation::E, field);

}

void test2()
{
	Generator g = Generator();
	int ret = 0;
	int i = 0;
	while (ret == 0 )//&& i < 500)
	{
		//std::cout << i << " : \t";
		//std::cout << g.getExecution() << std::endl;
		// g.printCounter();
		ret = g.generateNextExecution();
		i++;
	}
	std::cout << i << " : \t";
}

void ultimeTest()
{
	const std::string data = "\
		SR W W W SR W SR G B B SR B B B G SR \n\
		B W W W B W W B N N N N N N B N \n\
		G B G B G N N G B B B B G B G N \n\
		B N B N SR N SR G B SR N N B N SR N \n\
		B N B N N N N N N N N N B N N N \n\
		B N G B B B B G B B B B G N SR N \n\
		B N B N N N N B N N N N B N B N \n\
		B N B SR B G SR B N N SR N B N B N \n\
		SR N B N N B N B N N G B G B G N \n\
		N N B N N B N B N N B N N N B N \n\
		N SR G B B G N B N SR G B B B B SR \n\
		N N N N N SR N EB N N N N N N SR N \n\
		";
	Field field = Field();
	field.parseField(data);

	Executor executor = Executor(Orientation::N, field);

	Generator generator = Generator();

	int gene_return_value = 0;
	int exec_return_value = 0;
	int counter = 0;
	string execution = "";
	while (gene_return_value == 0 && exec_return_value != 2)
	{
		execution = generator.getExecution();
		std::cout << counter << "\t" << execution << "   " ;
		executor.setExecution(execution);
		exec_return_value = executor.execute();
		if (exec_return_value == 2)
			std::cout << std::endl << " -----> " << execution << " <----- " << std::endl;
		counter++;
		gene_return_value = generator.generateNextExecution();
	}

}

void test4()
{
	const std::string data = "\
		SR W W W SR W SR G B B SR B B B G SR \n\
		B W W W B W W B N N N N N N B N \n\
		G B G B G N N G B B B B G B G N \n\
		B N B N SR N SR G B SR N N B N SR N \n\
		B N B N N N N N N N N N B N N N \n\
		B N G B B B B G B B B B G N SR N \n\
		B N B N N N N B N N N N B N B N \n\
		B N B SR B G SR B N N SR N B N B N \n\
		SR N B N N B N B N N G B G B G N \n\
		N N B N N B N B N N B N N N B N \n\
		N SR G B B G N B N SR G B B B B SR \n\
		N N N N N SR N EB N N N N N N SR N \n\
		";
	Field field = Field();
	field.parseField(data);

	Executor executor = Executor(Orientation::N, field);

	string execution = "UF GL BC GC GC RL RL GL UF";
	execution = "UF RL RL GL GC BC GC GL GF UF";
	
	field.printStars();

	executor.setExecution(execution);
	int ret = executor.execute();

	std::cout << "return : " << ret << std::endl;

}

int main()
{
	// test4();
	ultimeTest();
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
