#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void player_select(int x){

	do{
	    printf("Too many players!\n");
	    printf("input the number of players (MAX: 5): ");
		scanf("%x", &x);
	}while(x>5);
	printf("--> card is mixed and put into the tray\n", x);
}

void main(){
/*플레이어 수 선택*/ 
int i; /*player*/ 
int k; /*round*/

int yourmoney;
printf("input the number of players (MAX: 5): ");
scanf("%d", &i);

if(i<=5){
	printf("--> card is mixed and put into the tray\n", i);
} 
else{
    player_select(i);
}

for(k=1;k<=3;k++){
	printf("\n---------------------------------------------\n-----------------ROUND %d(card index %d)---------------\n---------------------------------------------\n", k, k-1);
    printf("\n----- BETTING STEP -----");
    
}
	return 0;
} 
