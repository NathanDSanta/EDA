// Creat per jhg 24/25
// Exemple bàsic del contenidor list
// Suposem que els elements d'entrada de les dues lists estan ordenats

#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l1, l2;
    int numElements;
    int element;

    cout << "Nombre elements primera list: ";
    cin >> numElements;
    cout << "Elements primera list: " << endl;
    for (int i = 0; i < numElements; i++) {
        cout << i << ": ";
        cin >> element;
        l1.push_back(element);
    }
    cout << "Elements segona list (entra -1 per acabar): " << endl;
    cin >> element;
    while (element != -1) {
        numElements++;
        l2.push_back(element);
        cin >> element;
    }
    list<int> l3(l1.begin(), l1.end());
    list<int>::iterator it2 = l2.begin(),
            it3 = l3.begin();
    // inserim ordenadament a l3 (suposem l1 i l2 ens han arribat ordenats)
    while (it2 != l2.end() && it3 != l3.end()) {
        if (*it2 < *it3) {
            l3.insert(it3, *it2);
            it2++;
        } else {
            it3++;
        }
    }
    while (it2 != l2.end()) {
        l3.push_back(*it2++);
    }
    cout << "Element més petit: " << l3.front() << endl <<
         "Element més gran: " << l3.back() << endl;
    it3 = l3.begin(); // busquem element central
    for (int i = 0; i < numElements / 2; i++)
        it3++;
    cout << "Element central: " << *it3 << endl;
    cout << "Tots els elements: ";
    it3 = l3.begin();
    for (int i = 0; i < l3.size(); i++) // també while(it3!=l3.end())
        cout << *it3++ << " ";
    cout << endl;
    cout << "La list al revés (amb iteradors): ";
    it3 = l3.end();
    while (it3 != l3.begin())
        cout << *--it3 << " "; // COMPTE: predecrementem
    cout << endl;
    cout << "La list al revés (amb reverse_iterators): ";
    list<int>::reverse_iterator rit3 = l3.rbegin();
    while (rit3 != l3.rend())
        cout << *rit3++ << " ";
    cout << endl;
    cout << "La list al revés (copiant i buidant la còpia): ";
    // COMPTE: Aquesta no és la manera més eficient. Són millors les anteriors amb iteradors.
    list<int> l4(l3.begin(), l3.end());
    while (!l4.empty()) {
        cout << l4.back() << " ";
        l4.pop_back();
    }
    cout << endl;
    // Una altra manera de fusionar (que funcionaria encara que no estessin ordenats (menys eficient però)
    list<int> l5(l1.begin(),l1.end()); // copiem l1 a l5 al constructor
    l5.insert(l5.begin(),l2.begin(),l2.end()); // afegim l2 al principi d'l5
    l5.sort(); // ordenem l5 amb operador < de int
    cout << "Tots els elements (amb sort): ";
    list<int>::iterator it5 = l5.begin();
    while (it5!=l5.end())
        cout << *it5++ << " ";
    cout << endl;

}

