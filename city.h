#include <string>
#include <vector>


using namespace std;

class City {
private:
    string name;
    string population;
    string timeZone;
    double longitude;
    double latitude;
public:
    string getName();
    string getCoordinates();
    double getLatitude();
    double getLongitude();
    double distanceBetween(City a);
};
