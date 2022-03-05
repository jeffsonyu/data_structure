#include <iostream>
#include "PermutationGroup.h"
using namespace std;

int main(int argn, char* argc[])
{
	int n, dn;
	if (argn<2){ n = 3; dn = 3; }
	else if (argn<3){ n = std::stoi(argc[1]); dn = 3; }
	else{ n = std::stoi(argc[1]); dn = std::stoi(argc[2]); }

	PermutationGroup g(n);
	printf("Permutation group G[%d] : totally %d permutations\n", g.pN, g.gN);
	g.PrintPG();
	cout << endl;
	

	Permutation p; p.n = 4; 
	p.p[0] = 2; 
	p.p[1] = 3; 
	p.p[2] = 4; 
	p.p[3] = 1;

	cout << "Check if the Inv and Mul functions work:" << endl;
	g.PrintPermutation(p);
	g.PrintPermutation(g.Mul(p,p));
	g.PrintPermutation(g.Inv(p));
	g.PrintPermutation(g.Mul(p,g.Inv(p)));
	cout << endl;

	for (n = 3; n < 6; n++){
		PermutationGroup g(n);
		if (n == 5){
			g.PrintDerivedPG(20);
		}
		else{
			g.PrintDerivedPG(dn);
		}
		cout << endl;
	}
	
	/*
	We have computed the derived permutation group sequence of G[3], G[4] and G[5]
	The sequence of G[3] and G[4] will finally only include identity, [1 2 3] and [1 2 3 4]
	But the derived group sequence of G[5] seems to stay the same as G'[5], which contains 60 permutations
	We compute 20-th derived group of G[5], it is still equal to G'[5]
	So we conclude that it doesn't change
	*/

	Permutation p_3; p_3.n = 3; 
	p_3.p[0] = 1; 
	p_3.p[1] = 2; 
	p_3.p[2] = 3; 

	Permutation p_4; p_4.n = 4; 
	p_4.p[0] = 1; 
	p_4.p[1] = 2; 
	p_4.p[2] = 3; 
	p_4.p[3] = 4;

	cout << "The final derived permutation group of G[3] is: ";
	g.PrintPermutation(p_3);
	cout << endl;

	cout << "The final derived permutation group of G[4] is: ";
	g.PrintPermutation(p_4);
	cout << endl;


	PermutationGroup g_5(5);
	cout << "The final derived permutation group of G[5] is the ";
	g_5.PrintDerivedPG(1);
	cout << endl;

	return 0;
}
