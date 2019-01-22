#include "pugixml.cpp"
#include "SimulatedAnnealing.h"
#include <iostream>
#include <functional>
#include <vector>
using namespace pugi;
using namespace std;
const char* node_types[] =
{
    "null", "document", "element", "pcdata", "cdata", "comment", "pi", "declaration"
};

//bezoekt een (deel)boom met een visitor in preorder
void DEZBezoekpre(pugi::xml_node n,std::function<void(pugi::xml_node)> bezoekKnoop=[](pugi::xml_node){}){
    bezoekKnoop(n);
    for (auto&& k:n.children())
        DEZBezoekpre(k,bezoekKnoop);
};

//verwijdert knopen uit de deelboom die aan de voorwaarde voldoen, maar NIET de wortel
void verwijderUitBoom(xml_node n, function<bool(xml_node)> moetweg){
    DEZBezoekpre(n,[&moetweg](xml_node nn){
        xml_node kind = nn.first_child();
        while(kind){
            xml_node broer = kind.next_sibling();
            if (moetweg(kind))
                nn.remove_child(kind);
            kind = broer;
        }

    });
};


void schrijfPugiboom(pugi::xml_node n){
    DEZBezoekpre(n,[](pugi::xml_node nn){
        std::cout << node_types[nn.type()] << ": '" << nn.name()<<"'";
        if (nn.value() && strlen(nn.value()) !=0)
            std::cout<< ", waarde='" << nn.value();
        std::cout<<"\n";

        if (nn.attributes_begin() != nn.attributes_end()){
            std::cout<<"  Attributen:\n    ";
            for (auto&& att : nn.attributes())
                std::cout << " " << att.name() << "=" << att.value();
            std::cout<<"\n";
        };
    });
    
};



vector<pair<int,int>> leesin(pugi::xml_node n){
    
    vector<pair<int,int>> v;
	
	DEZBezoekpre(n,[&v](pugi::xml_node nn){

	

		if (nn.name()==string("knooppunt") && nn.attributes_begin() != nn.attributes_end()){
            
            int x = nn.attribute("xcoordinaat").as_int();
            int y = nn.attribute("ycoordinaat").as_int();
            
            
            pair<int,int> p(x,y);
            v.push_back(p);
            
            
		};
        
    });
    
    return v;
};


int main()
{
    pugi::xml_document doc;
    if (!doc.load_file("kerstnet.xml")) return -1;
    auto coos = leesin(doc);
    
    KerstmanAnnealing k(coos);
    auto oplossing = k.oplossing();
    
    cout << "Totale Afstand: " << k.geefAfstand(oplossing) << endl;
    cout << "Totale # iteraties: " << k.geefIteraties() << endl;
	for(int nummer : oplossing) {
    	cout << nummer << " -> ";
	}
    cout << oplossing[0] << endl;
    
}

// vim:et
