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

string helpMe(string currentCity) {
    vector<string> candidates;

    char last = tolower(currentCity[currentCity.size() - 1]);

    for (int i = 0; i < n; i++) {
        if (!cities[i].city.empty()) {
            char first = tolower(cities[i].city[0]);  //mecatarery dranum e poqratar;
            if (first == last) {
                candidates.push_back(cities[i].city);
            }
        }
    }

    if (candidates.empty()) { //empty stringi metod e;
        return "No variants";
    }

    srand(time(0)); //random num verdarcnelu jamankn e;
    int index = rand() % candidates.size(); //rand() 0 ic tarber reandom num;

    return candidates[index];
}


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
            getline(ss, temp, ',');
            cities[n].id = (temp.empty()) ? 0 : stoi(clean(temp));

            getline(ss, cities[n].city, ',');
            cities[n].city = clean(cities[n].city);

            getline(ss, temp, ',');
            cities[n].lat = (temp.empty()) ? 0.0 : stod(clean(temp));

            getline(ss, temp, ',');
            cities[n].lng = (temp.empty()) ? 0.0 : stod(clean(temp));

            getline(ss, cities[n].country, ',');
            cities[n].country = clean(cities[n].country);

            getline(ss, cities[n].iso2, ',');
            cities[n].iso2 = clean(cities[n].iso2);

            getline(ss, cities[n].iso3, ',');
            cities[n].iso3 = clean(cities[n].iso3);

            if (getline(ss, temp)) {
                temp = clean(temp);
                cities[n].population = (temp.empty()) ? 0 : stoll(temp);
            } else {
                cities[n].population = 0;
            }

            n++;
        } catch (...) {
            continue;
        }
    }
    file.close();
}

int main() {
    string filename = "worldcities.csv";
    readCSV(filename);

    if (n == 0) {
        cout << "not data" << endl;
        return 1;
    };
    string curenCity;
    string input;

    curenCity = cities[1].city;
    cout << "start city is '" << cities[1].city << "' " << endl;

    while (true) {
        cin >> input;
        int founded = -1;

        
        for (int i = 0; i < n; i++) {
            if (cities[i].city == input) {
                founded = i;
                break;
            }
        }

        if (input == "break") {
            break;
        }
        if (input == "help") {
        string hint = helpMe(curenCity);
        cout << "Try: " << hint << endl;
        continue;
        }


        if (founded == -1) {
            cout << "erorr: incorect city" << endl;
            continue;
        }

        char last = toupper(curenCity[curenCity.size() - 1]);
        char first = toupper(input[0]);

        if (tolower(last) != tolower(first)) {
            cout << "eror,plese continue input city with " << first << endl;
            continue;
        }

        curenCity = input;
        cout << "Ok countinue with " << curenCity << endl;
    }

    return 0;
}