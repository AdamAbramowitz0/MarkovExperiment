//
// Created by Abhinav Mummaneni on 5/12/24.
//

#ifndef MARKOVEXPERIMENT_RANDOMWALK_H
#define MARKOVEXPERIMENT_RANDOMWALK_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
class RandomWalk { 
public:
    void train(std::string filename);
    void generate(unsigned char input);
private:
    std::vector<std::vector<double> > graph;
    
};


#endif //MARKOVEXPERIMENT_RANDOMWALK_H
