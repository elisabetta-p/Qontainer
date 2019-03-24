#include "modificaelementi.h"

modificaelementi::modificaelementi(container<ContenutoMultimediale*>* p_contenitore, int i, vector<ContenutoMultimediale*> v, QWidget* parent) : QWidget(parent), cont(p_contenitore), indice(i), vettRisultati(v) {
    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0, 600,600);

    layout = new QVBoxLayout(this);

    //Creazione del titolo della pagina
    QLabel* titoloFinestra = new QLabel(this);
    titoloFinestra->setText(tr("Modifica Contenuti"));
    titoloFinestra->setFont(QFont("Times", 36, QFont::Bold));
    titoloFinestra->setAlignment(Qt::AlignHCenter);
    titoloFinestra->setStyleSheet("QLabel {color : #cc0066; }");
    layout->addWidget(titoloFinestra);

    caricaCampiDaModificare();
}

void modificaelementi::caricaCampiDaModificare() {

}
