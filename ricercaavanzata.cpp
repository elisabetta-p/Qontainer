#include "ricercaavanzata.h"

ricercaavanzata::ricercaavanzata() {
    setWindowTitle("Qontainer: Ricerca Avanzata - Elisabetta Piombin");
    setFixedSize(700,650);
    setFocusPolicy(Qt::StrongFocus);

    //Creazione del titolo Ricerca Avanzata
   QGroupBox* titoloGropuBox = new QGroupBox(this);

   QLabel* titolo = new QLabel(this);
   titolo->setMinimumSize(this->width(), 100);
   titolo->setText(tr("Ricerca Avanzata"));
   titolo->setFont(QFont("Times", 36, QFont::Bold));

   QHBoxLayout* boxTitolo = new QHBoxLayout;

   boxTitolo->addWidget(titolo);

   boxTitolo->setSizeConstraint(QLayout::SetMinimumSize);
   titoloGropuBox->setLayout(boxTitolo);
   titolo->setAlignment(Qt::AlignCenter);
}
