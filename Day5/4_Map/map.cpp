#include <map>
#include <iostream>

struct Point {
    double longi,latti;
    Point() = default;
    Point(const double &a, const double &b):longi(a),latti(b){}
};

int main() {
    std::map<std::string, Point> myFavoritePlaces;

    myFavoritePlaces["Gym"] = Point(56.435345,10.921311);

    auto work = std::make_pair<std::string,Point>("ALTEN",Point(57.706170, 11.944811));
    myFavoritePlaces.insert(work);
    
    myFavoritePlaces.insert(std::pair<std::string, Point>("Home",Point(55.43200,12.2331)));


    for (auto &e: myFavoritePlaces) {
        std::cout << e.first << " is located at longitude: " <<
                     e.second.longi << " latitude:" << e.second.latti << std::endl;
    }

    return 0;
};

