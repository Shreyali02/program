// write a program to check if madhyamgram is between sealdah and barasat ,or not.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Function to check if a station is in the vector
bool isStationOnRoute(const std::vector<std::string>& stations, const std::string& stationName) {
    return std::find(stations.begin(), stations.end(), stationName) != stations.end();
}

int main() {
    // Vector of stations on the route from Sealdah to Barasat
    std::vector<std::string> stations = {"Sealdah", "Bidhannagar", "Dum Dum", "Dum Dum Cantonment", 
                                         "Bangaon", "Madhyamgram", "Hridaypur", "Barasat"};

    std::string destination = "Madhyamgram";

    if (isStationOnRoute(stations, destination)) {
        std::cout << "Good news! " << destination << " is on the route from Sealdah to Barasat." << std::endl;
    } else {
        std::cout << "Sorry, " << destination << " is not on the route from Sealdah to Barasat." << std::endl;
    }

    return 0;
}