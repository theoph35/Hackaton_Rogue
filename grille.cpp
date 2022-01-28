#include <iostream>
#include <vector>
#include "grille.h"


const int LINES = 10;
const int COLUMNS = 30;
const int BACKGROUND = 1 ;
const int GROUND = 2 ;
const int CORRIDOR = 3 ;
const int DOOR = 4 ;


//Grille::Grille(const std::vector <std::vector <int> > grille) :
//grille(grille)
//{}

Grille::Grille()
{}

void Grille::draw_Grille() {
    // Fonction permettant d'afficher la grille que l'on a construit
    for (int i=0 ; i<grille.size() ; i++) {
        for (int j=0 ; j<grille[1].size() ; j++) {
            std::cout << grille[i][j];
        }
        std::cout << std::endl;
    }
}

void Grille::vertical_Walls() {
    // Fonction permettant d'ajouter à la grille les murs verticaux

    
    for (int i=1 ; i<grille.size() ; i++) {
        grille[i][0] = '|' ;
        grille[i][int(grille[1].size()/3)] = '|';
        grille[i][int(2*grille[1].size()/3)] = '|';
        grille[i][grille[1].size()-1] = '|';
    }
}

void Grille::horizontal_Walls() {
    // Fonction permettant d'ajouter à la grille les murs horizontaux
    
    for (int j=0 ; j<int(grille[1].size()/3) ; j++) {
        grille[0][j] = '_';
        grille[grille.size()-1][j] = '_';
    }
    
    for (int j=int(2*grille[1].size()/3) ; j<grille[1].size() ; j++) {
        grille[0][j] = '_';
        grille[grille.size()-1][j] = '_';
    }
}

void Grille::Corridor() {
    // Fonction permettant d'ajouter à la grille le couloir

    for (int j=int(grille[1].size()/3) ; j<int(2*grille[1].size()/3) ; j++) {
        grille[int(grille.size()/2)][j] ;
    }
}


void Grille::Ground() {
    // Fonction permettant d'ajouter à la grille le sol

    for (int i=1 ; i<grille.size()-1 ; i++){
        for (int j=1 ; j<int(grille[1].size()/3)-1 ; j++) {
            grille[i][j] = GROUND ;
        }
        for (int j=int(2*grille[1].size()/3)+1 ; j<grille[1].size()-1 ; j++) {
            grille[i][j] = GROUND ;
        }
    }
}

void Grille::init_Grille() {
    // Fonction permettant de reinitialiser/initialiser la grille en ne construisant que le background, le ground, les murs, et le couloir
    grille = std::vector<std::vector<int>> (LINES, std::vector <int> (COLUMNS,BACKGROUND)) ;
    this->Ground();
    this->vertical_Walls();
    this->horizontal_Walls();
    this->Corridor();
}


int Grille::at(int a, int b){
    return grille[a][b] ;
}






