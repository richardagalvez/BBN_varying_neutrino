#include "src/include.h"

/*--------------------------------------------------------*/
/* Calculation of the observables in the Standard Model   */
/* Included is the Fierz interference term, which extends */
/* the electroweak sector to include scalar and tensor    */
/* currents that may result from SUSY, leptoquarks, etc   */
/*--------------------------------------------------------*/

int main(int argc,char** argv)
{ 
	//double ratioH[NUCBUF],sigma_ratioH[NUCBUF]; // TODO replace with map
	NuclideMap ratioH, sigma_ratioH;
	double H2_H,He3_H,Yp,Li7_H,Li6_H,Be7_H;
	double sigma_H2_H,sigma_He3_H,sigma_Yp,sigma_Li7_H,sigma_Li6_H,sigma_Be7_H;
	double eta,nbnu,tau;
    double fierz, nbnu_star;

	if(argc<1) 
  	{ 
        	printf(" This program needs 2 parameter:\n");
        	printf(" nbnu number of neutrinos\n");
		printf(" nbnu_star number of neutrinos that goes into energy determination\n");
        	exit(1); 
  	} 
	else 
  	{
  		sscanf(argv[1],"%lf",&nbnu);
		sscanf(argv[2],"%lf",&nbnu_star);
  	}
	
	CosmologyModel relic;      /// The parameters from the big bang relic before bbn.
	relic.Init_cosmomodel();
	relic.Init_cosmomodel_param(6.10e-10, nbnu, nbnu_star, 880.3, 0, 0, 0);


	FILE * fp;
        fp = fopen ("output", "a+");

	double alpha = pow(nbnu_star/nbnu, 1.0/4.0);
        nucl_failsafe(3,relic,ratioH);
	H2_H=ratioH[H2]; Yp=ratioH[He4]; Li7_H=ratioH[Li7]; Be7_H=ratioH[Be7]; He3_H=ratioH[He3]; Li6_H=ratioH[Li6];
	//printf("Yp\t\t H2/H\t\t He3/H\t\t Li7/H\t\t Li6/H\t\t Be7/H\t\t Neff\n");
	printf("%.3e\t %.3e\t %.3e\t %.3e\t %.3e\t %.3e\t %.3e\t %.3e\t %.3e\n",Yp,H2_H,He3_H,Li7_H,Li6_H,Be7_H, nbnu_star, nbnu, alpha);	
		
	return 1;
}
