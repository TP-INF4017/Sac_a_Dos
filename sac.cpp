#include <iostream>
#include <algorithm>
#include <vector>

// fonction permettant de comparaitre notre vecteur
// sur la base du rapport entre la valeur et les poids

bool comparer(pair<float, int> p1, pair<float, int> p2) {
    return p1.first > p2.first;
}

int sac_fractionnaire(vector <int> poids, vector <int> valeurs, int capacite) {
    
    int len = poids.size();
    int valeur_total = 0;

    //stockage des articles dans notre vecteur en fonction de leur rapport valeur/poids
    vector <pair <float, int>> ratio(len, make_pair(0.0, 0));

    
    for(int i =0; i < len; i++)
        ratio[i] = make_pair(valeurs[i]/poids[i], i);
    
    // tri des ratio par ordre decroissant 
    sort(ratio.begin(), ratio.end(), compare);

    ////selection des objets
    for (int i = 0; i < len; i++)
    {
        if(capacite == 0)
          break;

        int index = ratio[i].second;
        if (poids[index] <= capacite)
        {
            // notre article peut entrer dans le sac donc on prend tout
            capacite -= poids[index];

            // ajout de la valeur de cet element
            valeur_total += valeurs[index];
        }
        else
        {
            // notre article ne peut pas entrer dans le sac
            // alors nous prenons la fraction
            int valeur_considerer = valeurs[index] * (float(capacite)/float(poids[index]));
            valeur_total += valeur_considerer;
            capacite = 0;
        }
        
    }

    return valeur_total;
    
}

int main() {
    cout << "Entrez le poids des articles" << endl;
    
    vector <int> poids;

    while (true)
    {
        int poids;
        cin >> poids;

        if(poids == -1)
           break;

        poids.repousser(poids);
    }

    cout << "Entrez les valeurs de chaque articles" << endl;

    vector <int> valeurs;

    while (true)
    {
        int valeur;
        cin >> valeur;

        if(valeur == -1)
           break;

        valeurs.repousser(valeur);
    }

    cout << "Entrez la capacite du sac" << endl;

    int capacite;
    cin >> capacite;

    cout << "La valeur max possible de la liste est : " << sac_fractionnaire(poids, valeurs, capacite) << endl;
    
    
}