// write a program in c++ to implement tower of hanoi .
#include <iostream>
#include <vector>
#include <string>

class TowerOfHanoi {
private:
    int numDisks;
    std::vector<std::vector<int>> pegs;

    void moveDisk(int from, int to) {
        int disk = pegs[from].back();
        pegs[from].pop_back();
        pegs[to].push_back(disk);
        printState();
    }

    void solve(int n, int from, int to, int aux) {
        if (n == 1) {
            moveDisk(from, to);
            return;
        }
        solve(n - 1, from, aux, to);
        moveDisk(from, to);
        solve(n - 1, aux, to, from);
    }

    void printState() {
        std::cout << "\nCurrent state:" << std::endl;
        int maxHeight = numDisks;
        for (int height = maxHeight - 1; height >= 0; height--) {
            for (int peg = 0; peg < 3; peg++) {
                if (height < pegs[peg].size()) {
                    std::cout << " " << std::string(numDisks - pegs[peg][height], ' ') 
                              << std::string(pegs[peg][height], '#') 
                              << "|" 
                              << std::string(pegs[peg][height], '#') 
                              << std::string(numDisks - pegs[peg][height], ' ') << " ";
                } else {
                    std::cout << " " << std::string(numDisks, ' ') << "|" << std::string(numDisks, ' ') << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "-" << std::string(6 * numDisks + 5, '-') << "-" << std::endl;
        std::cout << " " << std::string(2 * numDisks, ' ') << "A" 
                  << std::string(2 * numDisks + 2, ' ') << "B" 
                  << std::string(2 * numDisks + 2, ' ') << "C" << std::endl;
    }

public:
    TowerOfHanoi(int n) : numDisks(n), pegs(3) {
        for (int i = n; i > 0; i--) {
            pegs[0].push_back(i);
        }
    }

    void solve() {
        std::cout << "Initial state:" << std::endl;
        printState();
        solve(numDisks, 0, 2, 1);
    }
};

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    TowerOfHanoi tower(n);
    tower.solve();

    return 0;
}   