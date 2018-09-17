

#include "Map.h"
#include "../CoreSDC/Pose.h"
#include "../Common/Common.h"
#include <fstream> 


namespace Map{


    LandmarkMap::LandmarkMap(){
        pLandmarks.resize(0);
    }

    LandmarkMap::~LandmarkMap(){

    }

    Flag::ReadFileFlag LandmarkMap::ReadLandmarkFromFile(std::fstream& input_file){
        /* Reads in the landmark from file. (.lm or .txt)
            each line in the The landmarkfile is a space seperated list of (x,y)
        */
        if (input_file.is_open()){
            int nlandmarks; 
            input_file >> nlandmarks; 
            // read in all the landmark coordinates 
            Core::Position location;
            pLandmarks.resize(nlandmarks);
            for (int i = 0; i < nlandmarks; i++){
                input_file >> location.x >> location.y ;
                pLandmarks.at(i).location = location; 
            }
            return Flag::READ_FILE_SUCCESSFUL; 

            input_file.close();
        }
        else{
            return Flag::FILE_NOT_OPEN; 
        }
    }

    void LandmarkMap::PrintMap(){
        /*
        print the landmarks in the map  
        */
        for (size_t i = 0; i < pLandmarks.size(); i++){
            double x = pLandmarks.at(i).location.x; 
            double y = pLandmarks.at(i).location.y;
            std::cout<<"Landmark ["<<i<<"] = loc("<<x<<" , "<<y<<") "<<std::endl;
        }
    }

    void LandmarkMap::ShowInformation(){
        PrintMap();
    }
}