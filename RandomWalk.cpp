#include "RandomWalk.h"
#include <random>
int main(int argc, char *argv[]) {
    RandomWalk rw;
    rw.train(argv[1]);
    unsigned char input;
    std::cin >> input;
    rw.generate(input);
}


void RandomWalk::train(std::string filename) {
    graph.resize(256);
    for (int i = 0; i < graph.size(); ++i) { 
        graph[i].resize(256);
        std::fill(graph[i].begin(), graph[i].end(), 0);
    }
    std::ifstream infile(filename);
    unsigned char curr = infile.get();
    for (unsigned char next = infile.get(); infile.good(); next = infile.get()) {
        graph[curr][next]++;
        curr = next;
    }
    
}

void RandomWalk::generate(unsigned char input) {
    std::cout << std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    const int numWords = 100;
    for (int i = 0; i < numWords; ++i) {
        std::discrete_distribution<> d(graph[input].begin(), graph[input].end());
        input = d(gen);
        std::cout << input;
    }
}