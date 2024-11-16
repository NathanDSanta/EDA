### Estructura global

- Padro `map<int,Anys>`
    - Anys `vector<Districte>` 
        - Districte `map<int,Seccio>`
            - Seccio `list<Persona>`
                - Habitant `Persona`


En Padro i Districte he utilitzat `map` a causa de 3 raons:

- Manté els elements ordenats
- Consultes i insercions (ordenades) molt ràpides
- Familiaritat amb la estructura

En Anys he utilitzat un `vector` perquè els índex de Districte son pocs
i coneguts. El vector permet treure'n profit d'aquest fet mantenint senzillesa. 

En el cas de Seccio he utilitzat una `list` ja que s'espera un gran nombre de
persones, que no cal mantenir ordenat i que no en coneixem el nombre exacte.
Hem de fer un gran nombre d'insercions, per tant aquestes han de ser el més
ràpides possibles.

### Estructures auxiliars

En la classe Districte he fet servir diferents atributs per a millorar la
eficiència del programa:

- **a_resumEstudis** `set<Estudi>`: Evita un recorregut de tota la llista
  d'habitants guardant els diferents estudis al inserir una persona. Utilitzo
  un `set` per a no inserir repetits
- **a_resumNacionalitats** `set<Nacionalitats>`: De la mateixa manera, evita un
  recorregut afegint les dades en inserir una persona. Un `set` per no guardar
  repetits
- **a_resumHabitantsNacio** `map<int,long>`: Guardem el nombre d'habitants per cada
  nacionalitat del districte. Utilitzem un map ja que no necessitem repetits
  i es senzill d'utilitzar.
- **sumaEdats** `double`: Igual que totes les estructures d'aquesta llista, evita
  un recorregut dels habitants. Guardem la suma d'edats per a calcular la
  mitjana en temps constant
- **sumaPromigEstudis** `double`: Evita un recorregut. Guardem la suma dels
  codis del Nivell d'Estudis per a poder calcular el promig ràpidament


### Fitxers de Proves

#### inPadroCurt.txt

Aquest fitxer és un fitxer de proves que permet comprovar el funcionament de
totes les funcions del programa sense preocupar-se per la complexitat dels
mètodes i serveix com a provà ràpida del funcionament del nostre programa.


#### inPadroLlarg.txt

Aquest fitxer de proves permet comprovar la eficiència del nostre programa
llegint el fitxer **PadroLlarg.csv** que conté un nombre de línies d'informació
més elevat. Aquest inclou proves de totes les funcions del programa i posa
a prova l'eficàcia i velocitat d'aquest.
