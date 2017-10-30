#ifndef __ZOEKBOOM_H
#define __ZOEKBOOM_H
#include <cstdlib>
#include <iostream>
#include <queue>
#include <memory>
#include <functional>

using std::ostream;
using std::unique_ptr;
using std::cerr;
/**********************************************************************

   Class: Zoekboom
   
   beschrijving: Binaire zoekboom waarin geen duplicaatsleutels zijn toegestaan.
   
***************************************************************************/

template <class Sleutel,class Data>
class Zoekknoop;

template <class Sleutel,class Data>
class Zoekboom : public unique_ptr<Zoekknoop<Sleutel,Data>>{
//.... constructoren, copy move
    using unique_ptr<Zoekknoop<Sleutel,Data>>::unique_ptr;
public:
    void voegtoe(const Sleutel& sleutel,const Data& data);
    void roteer(bool naarlinks);
    void inorder(std::function<void(const Zoekknoop<Sleutel,Data>&)> bezoek) const;
    void schrijf(ostream& os) const;
    bool repOK() const;
    int geefDiepte();
    void maakOnevenwichtig();
    void maakEvenwichtig();

protected:
//zoekfunctie zoekt sl en geeft de boom in waaronder de sleutel zit (eventueel een lege boom als de sleutel
//ontbreekt) en de pointer naar de ouder (als die bestaat, anders nulpointer).
//noot: alhoewel de functie niets verandert aan de boom is ze geen const functie.
    void zoek(const Sleutel& sleutel, Zoekknoop<Sleutel,Data>*& ouder, Zoekboom<Sleutel,Data>*& plaats);
};


template <class Sleutel,class Data>
class Zoekknoop {
    friend class Zoekboom<Sleutel,Data>;
    public:
        Zoekknoop():ouder(0){}
        Zoekknoop(const Sleutel& sl, const Data& d):sleutel{sl},data(d),ouder(0){};
        Zoekknoop(Sleutel&& sl, Data&& d):sleutel{move(sl)},data(move(d)),ouder(0){};
    protected:
        Sleutel sleutel;
        Data data;
        Zoekknoop<Sleutel,Data>* ouder;
        Zoekboom<Sleutel,Data> links,rechts;
};

template <class Sleutel,class Data>
void Zoekboom<Sleutel,Data>::voegtoe(const Sleutel& sleutel,const Data& data){
    Zoekboom<Sleutel,Data>* plaats;
    Zoekknoop<Sleutel,Data>* ouder;
    zoek(sleutel, ouder, plaats);
    if (!*plaats){
//noot: vanaf C++14 wordt dit
        Zoekboom<Sleutel,Data> nieuw=make_unique<Zoekknoop<Sleutel,Data> >(sleutel,data));
//tot dan was het:
//        Zoekboom<Sleutel,Data> nieuw(new Zoekknoop<Sleutel,Data>(sleutel,data));
        nieuw->ouder=ouder;
        *plaats=move(nieuw);
    };
    
};

template <class Sleutel,class Data>
void Zoekboom<Sleutel,Data>::zoek(const Sleutel& sleutel, Zoekknoop<Sleutel,Data>*& ouder, Zoekboom<Sleutel,Data>*& plaats){
    plaats=this;
    ouder=0;
    while (plaats && (*plaats)->sleutel !=sleutel){
        ouder=plaats->get();
        if ((*plaats)->sleutel < sleutel)
            plaats=&(*plaats)->rechts;
        else
            plaats=&(*plaats)->links;
    };
};
template <class Sleutel,class Data>
void Zoekboom::inorder(std::function<void(const Zoekknoop<Sleutel,Data>&)> bezoek) const{
    if (*this){
        (*this)->links.inorder(bezoek);
        bezoek(**this);
        (*this)->rechts.inorder(bezoek);
    };
}

template <class Sleutel,class Data>
void Zoekboom::schrijf(ostream& os) const{
    inorder([&os](const Zoekknoop<Sleutel,Data>& knoop){
        os<<"("<<knoop.sleutel<<" -> "<<knoop.data<<")";
        os<<"\n  Linkerkind: ";
        if (knoop.links)
            os<<knoop.links->sleutel;
        else
            os<<"-----";
        os<<"\n  Rechterkind: ";
        if (knoop.rechts)
            os<<knoop.rechts->sleutel;
        else
            os<<"-----";
        os<<"\n";
    });
}



#endif