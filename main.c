#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ci=0; //card index
//player
int p; //number of players
void player(){
	printf("input the number of players(MAX: 5) : ");
	scanf("%d", &p);
	
	while(p<=0||p>5){
		printf("invalid input players (%d)\n", p);
		printf("input the number of players(MAX: 5) : ");
	    scanf("%d", &p);
	}
	printf("--> card is mixed and put into the tray\n");
	printf("%d\n", p);
}

//betting
int A[6][3];
int i;
int ybm; //your betting money
void betting(){
	for(i=0; i<6; i++){
		A[i][0]=50;
	}
	printf("----- BETTING STEP -----\n");
	printf(" -> your betting (total:$%d) : ", A[0][0]);
	scanf("%d", &ybm);
	while(ybm<=0||ybm>A[0][0]){
		printf(" -> invalid input for betting $%d", ybm);
		printf(" -> your betting (total:$%d) : ", A[0][0]);
		scanf("%d", &ybm);
		ybm=A[0][1];
	}
	srand(time(NULL));
	for(i=1; i<p; i++){
		
		A[i][1]= rand()%5+1;
		printf(" -> player%d bets $%d (out of $%d)\n", i, A[i][1], A[i][0]);
	}
	printf("-----------------------------------\n\n");	
}
int c[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//card
int a, b, d, f, s;
void card(){
	srand(time(NULL));
	printf("----- CARD OFFERING ------------\n");
	s=c[0+rand()%10];
	printf("--- server    : X %d\n", s);
	A[6][2]=s;
    a=c[0+rand()%10], b=c[0+rand()%10];
	printf("  -> you      : %d %d\n", a, b);
	A[0][2]=a+b;
	ci+=4;
	for(i=1; i<p; i++){
    d=c[0+rand()%10], f=c[0+rand()%10];
	    printf("  -> player%d  : %d %d\n", i, d, f);
	    A[i][2]=d+f;
	    ci+=2;
	}
}

//game start
int g; //go or stay
int k;
void game_start(){
	printf("\n--------------- GAME START --------------------\n");
	printf(">>> my turn! -------------\n");
	do{
	printf("  -> card : %d %d", a, b);
	printf("   ::: Action? (0 - go, others - stay) :");
	scanf("%d", &g);
	k=c[rand()%9];
	printf("  -> card : %d %d %d\n", a, b, k);
	A[0][2]+=k;
	if(A[0][2]>21){
		printf("   ::: DEAD (sum: %d)--> -$%d ($%d)", A[0][2], A[0][1], A[0][0]-A[0][1]); continue;
		}
	}while(g !=0);
}
void main(){
int r=1;  //round number 
	player();
	while(ci<=52){
		printf("--------------------------------------\n");
		printf("------- ROUND %d (cardindex:%d)----------------------------\n", r, ci);
		printf("--------------------------------------\n\n");
	    betting();
	    card();
	    game_start();
    }
	return 0;
}
