// Creat per jhg 24/25
// Exemple bàsic del contenidor list
// Suposem que els elements d'entrada dels dos vectors estan ordenats

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1, v2;
    int numElements;
    int element;

    cout << "Nombre elements primer vector: ";
    cin >> numElements; // es podria demanar abans i invocar el constructor: vector v1(numElements);
    v1.resize(numElements);
    cout << "Elements primer vector: " << endl;
    for (int i = 0; i < numElements; i++) {
        cout << i << ": ";
        cin >> v1[i];
    }
    cout << "Elements segon vector (entra -1 per acabar):" << endl;
    cin >> element;
    while (element != -1) {
        v2.push_back(element);
        cin >> element;
    }
    vector<int> v3(v1.size() + v2.size());
    vector<int>::iterator it1 = v1.begin(),
            it2 = v2.begin(),
            it3;
    // inserim ordenadament a v3 (suposem v1 i v2 ens han arribat ordenats)
    int i = 0;
    while (it1 != v1.end() && it2 != v2.end()) {
        if (*it1 <= *it2) {
            v3[i++] = *it1; // equivalent a v3[i]=*it1; i++;
            it1++;
        } else
            v3[i++] = *it2++; // també podem afegir i postincrementar en una sola expressió
    }
    while (it1 != v1.end()) {
        v3[i++] = *it1++; // equivalent a v3[i]=*it1; i++; it1++;
    }
    while (it2 != v2.end()) {
        v3[i++] = *it2++;
    }
    cout << "Element més petit: " << v3.front() << endl <<
         "Element més gran: " << v3.back() << endl <<
         "Element central: " << v3[v3.size() / 2] << endl;
    cout << "Tots els elements: ";
    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " ";
    cout << endl;
    cout << "El vector al revés (amb iteradors): ";
    it3 = v3.end();
    while (it3 != v3.begin())
        cout << *--it3 << " "; // COMPTE: predecrementem. Equivalent a --it3; cout << *it3 << " ";
    cout << endl;
    cout << "El vector al revés (amb reverse_iterators): ";
    vector<int>::reverse_iterator rit3 = v3.rbegin();
    while (rit3 != v3.rend())
        cout << *rit3++ << " ";
    cout << endl;
    cout << "El vector al revés (copiant i buidant la còpia): ";
    // COMPTE: Aquesta no és la manera més eficient. Són millors les anteriors amb iteradors.
    vector<int> v4(v3.begin(), v3.end());
    while (!v4.empty()) {
        cout << v4.back() << " ";
        v4.pop_back();
    }
    cout << endl;
}
