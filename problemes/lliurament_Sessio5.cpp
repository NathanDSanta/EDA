#include <cstddef>
template <class clau, class element> class EDFDispersioIndirecte2 {
public:
  EDFDispersioIndirecte2();
  EDFDispersioIndirecte2(const EDFDispersioIndirecte2 &o);

private:
  // es poden usar mètodes privats… implementant-los
  struct node {
    clau id;
    element val;
    node *seg, *ant;
  };
  node **dades; // taula dinàmica de punters
  int nDades, maxDades;
};

template <class clau, class element> EDFDispersioIndirecte2<clau, element>::EDFDispersioIndirecte2(const EDFDispersioIndirecte2 &o) {
  maxDades = o.maxDades;
  nDades = o.nDades;
  dades = new node *[maxDades];
  for (int i = 0; i < maxDades; i++) {
    node *inici;
    node *ant = NULL;
    node *ptr = dades[i] = NULL;
    node *ptr_o = o.dades[i];
    while (ptr_o != NULL) {
      ptr = new node;
      ptr->ant = ant;
      ptr->id = ptr_o->id;
      ptr->val = ptr_o->val;
      ptr->seg = NULL;
      if (ant == NULL) {
        dades[i] = ptr;
        inici = ptr;
      } else {
        ant->seg = ptr;
      }
      ant = ptr;
      inici->ant = ptr;
      ptr_o = ptr_o->seg;
    }
  }
}
