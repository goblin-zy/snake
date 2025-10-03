#include "allcpp.h"

void setDifficulty(ClickType click){
	if(click==CLICK_EASY){
		snakespeed=15;
		obstacle=1;
	}
	if(click==CLICK_MEDIUM){
		snakespeed=10;
		obstacle=2;
	}
	if(click==CLICK_DIFFICULT){
		snakespeed=5;
		obstacle=3;
	}
}
void loadDefaultDifficulty(){
	snakespeed=10;
	obstacle=1;
}
