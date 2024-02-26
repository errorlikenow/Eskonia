#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "firstsettingsup.h"
using namespace std;
int main(){
	ifstream systemRegister("System.registry");
	if (!systemRegister.is_open()){
		firstsettingup();
		return 15;
	}
	else {}
	
	return 0;

}
