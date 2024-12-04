#ifndef CANDIDATS_H
#define CANDIDATS_H

class Candidats {
public:
  Candidats(int inici, int final);
  void operator++(int); //seguent
  int actual() const;
  bool end() const; // esFi


private:
  int aICand;
  int aMax;
};

#endif // !CANDIDATS_H
