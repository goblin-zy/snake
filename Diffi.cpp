#include "allcpp.h"

void setDifficulty(ClickType click){
	if(click==CLICK_EASY){
		snakespeed=100;
		obstacle=1;
	}
	if(click==CLICK_MEDIUM){
		snakespeed=150;
		obstacle=2;
	}
	if(click==CLICK_DIFFICULT){
		snakespeed=200;
		obstacle=3;
	}
}
void loadDefaultDifficulty(){
	snakespeed=100;
	obstacle=1;
}
