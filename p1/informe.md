# Pràctica 1


<div style="text-align: right"><sup> Darius Natan, Santa</div>

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

-
