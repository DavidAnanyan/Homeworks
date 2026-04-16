#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

struct City {
    int id;
    string city;
    double lat;
    double lng;
    string country;
    string iso2;
    string iso3;
    long long population;
};

const int Max = 45000;
City cities[Max];
int n = 0;

//maqrenq avelord symbpolneric;
string clean(string s) {
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    s.erase(remove(s.begin(), s.end(), '\r'), s.end());
    s.erase(remove(s.begin(), s.end(), '\n'), s.end());
    return s;
}


// poqratar voronum;
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void readCSV(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "error " << filename << " not found" << endl;
        return;
    }

    string line;
    getline(file, line); // vernagreru ancnenq

    while (getline(file, line) && n < Max) {
        if (line.empty()) continue;

        stringstream ss(line);
        string temp;

        try {
            
            // 1. ID
            getline(ss, temp, ','); 
            cities[n].id = (temp.empty()) ? 0 : stoi(clean(temp));

            // 2. City
            getline(ss, cities[n].city, ',');
            cities[n].city = clean(cities[n].city);

            // 3. Lat
            getline(ss, temp, ',');
            cities[n].lat = (temp.empty()) ? 0.0 : stod(clean(temp));

            // 4. Lng
            getline(ss, temp, ',');
            cities[n].lng = (temp.empty()) ? 0.0 : stod(clean(temp));

            // 5. Country
            getline(ss, cities[n].country, ',');
            cities[n].country = clean(cities[n].country);

            // 6. ISO2
            getline(ss, cities[n].iso2, ',');
            cities[n].iso2 = clean(cities[n].iso2);

            // 7. ISO3
            getline(ss, cities[n].iso3, ',');
            cities[n].iso3 = clean(cities[n].iso3);

            // 8. Population 
            if (getline(ss, temp)) {
                temp = clean(temp);
                cities[n].population = (temp.empty()) ? 0 : stoll(temp);
            } else {
                cities[n].population = 0;
            }

            n++;
        } catch (...) { continue; }
    }
    file.close();
}

int main() {
    string filename = "worldcities.csv";
    readCSV(filename);

    if (n == 0) {
        cout << "not data" << endl;
        return 1;
    }

    string searchTarget = "Tokyo";
    string lowerTarget = toLower(searchTarget);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (toLower(cities[i].city) == lowerTarget) {
            cout << "city founded" << endl;
            cout << "name : " << cities[i].city << endl;
            cout << "city:   " << cities[i].country << endl;
            cout << "population: " << cities[i].population << endl;
            cout << "kordinats: " << cities[i].lat << ", " << cities[i].lng << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "city '" << searchTarget << " is not founded ";
    }

    return 0;
}