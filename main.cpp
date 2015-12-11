#include <iostream>
#include <string>
using namespace std;

struct Dugum{
    string veri;
    Dugum* ileri;
};
void dugumBasi(struct Dugum *bas , string n){
    bas->veri = n;
    bas->ileri = NULL;
}
void dugumEkle(struct Dugum *bas , string n){
    Dugum *yeni = new Dugum();
    yeni->veri = n;
    yeni->ileri = NULL;
    
    Dugum *gecici = bas;
    while(gecici){
        if(gecici->ileri == NULL){
            gecici->ileri = yeni;
            return;
        }
        gecici = gecici->ileri;
    }  
}
struct Dugum *dugumAra(struct Dugum *bas , string n){
    Dugum *gecici = bas;
    while(gecici){
        if(gecici->veri == n)
        return gecici;
        gecici = gecici->ileri;
    }
    cout<<"Listede "<<n<<" dugumu yoktur.";
}
bool dugumSil(struct Dugum **bas , Dugum *sil){
    Dugum *gecici = *bas;
    if(sil == *bas){
        *bas = gecici->ileri;
         delete sil;
         return true;
    }
    while(gecici){
        if(gecici->ileri == sil){
            gecici->ileri = sil->ileri;
            delete sil;
            return true;
        }
        gecici = gecici->ileri;
    }
    return false;
}
void listele(struct Dugum *bas){
    Dugum *liste = bas;
    cout<<"Guncel liste --->";
    while(liste){
        cout<<liste->veri<<" ";
        liste = liste->ileri;
    }
    cout<<endl<<endl;
}
int main(){
	Dugum *bas = new Dugum();
	
	string cars[] = {"Renault" , "Ford" , "Mercedes" , "BMW"};
	
	dugumBasi(bas,cars[0]);
	listele(bas);
	
	for(int i=1;i<4;i++){
		dugumEkle(bas,cars[i]);
		listele(bas);
	}
	
	string silinecek = "Ford";
	Dugum *sil = dugumAra(bas,silinecek);
	if(dugumSil(&bas , sil))
		cout<<"Durum --->"<<silinecek<<" dugumu silinmistir."<<endl;
			
	listele(bas);
	
	system("PAUSE");
    return 0;
}
