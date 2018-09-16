

#include <iostream>
#include "Map.h"
#include <fstream> 


int main(){

    std::cout << "Compiling the Map if you see this, it means it worked " <<std::endl;

    std::fstream landmarkfile; 
    landmarkfile.open("landmarks1.txt",std::ios::in);

    // create a map 
    Map::LandmarkMap map1; 
    map1.ReadLandmarkFromFile(landmarkfile);

    map1.ShowInformation();

    return 0; 
}