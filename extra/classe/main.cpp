template <class clau, class element> class EDF {
public:
  EDF();
  virtual ~EDF();
  virtual void Afegir(const clau &c, const element &e) = 0;
  virtual void Esborrar(const clau &c) = 0;
  virtual bool Existeix(const clau &c) const = 0;
  virtual element Consulta(const clau &c) const = 0;
  virtual bool esBuida() const = 0;
  virtual bool esPlena() const = 0;
};