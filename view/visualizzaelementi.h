#ifndef VISUALIZZAELEMENTI_H
#define VISUALIZZAELEMENTI_H
#include "mainwindow.h"
#include <vector>
#include <QLineEdit>

class visualizzaelementi: public QWidget {
  Q_OBJECT
private:
  QGridLayout* griglia;
  QVBoxLayout* layout;
  void lunghezzaFissaQLineEdit(QLineEdit*, int = 0);
  void creaOpzioneVisualizzazione(QString, QString, int, QGridLayout*, int);
  void caricaCampiDaVisualizzare();
  ContenutoMultimediale* multimedia;
public:
  visualizzaelementi(ContenutoMultimediale*, QWidget* = nullptr);
  ~visualizzaelementi() = default;
};

#endif //VISUALIZZAELEMENTI_H
