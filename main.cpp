#include <iostream>
#include <stdlib.h>
#include <string>

void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);

int main(int argc, char** argv){
    deb:
    int option;
    int grille[7][6] = {};
    std::string choix;
    std::cout <<"Choisissez une option. \n 1: deux joueurs. \n 2: un joueur.\n";
    std::cin >> option;
    while(option != 1 && option !=2){
        std::cout <<"votre choix est invalide\n";
        std::cout <<"Choisissez une option. \n 1: deux joueurs. \n 2: un joueur.\n";
        std::cin >> option;
        break;
    }
    
    
    int player = 1;
    int conteur = 0;
    drawGrid(grille);
    bool gagnant (int grid[7][6]);
    bool win = false;

    if (option ==1 ){
        while (true){
            if(conteur < 42 ){
                std::cout << "player_" << player << " -> col :";
                std::cin >> choix;
            }

            if (choix == "exit"){
                break;
            }

            bool success = false;

            if (choix.size() == 1){
                if (choix[0] >= '0' && choix[0] <= '7'){
                    int col = choix[0]  - '0';

                    success = playTurn(grille, col, player);
                }
            }

            system("CLS");

            if (!success){
                std::cout << "win= " << win ;
                if (conteur >= 42 || win ==true){
                    std::cout <<"partie terminee\n Aucun gagnant.\n";
                    break;
                }
                else if (conteur < 42)
                {
                    std::cout << "votre choix est incorrect\n";
                }
                
            }
            else{
                if (player == 1) player = 2;
                else player = 1;
                conteur = conteur + 1;
                std::cout<<conteur<<"\n";
            }
            if(conteur < 42 || win == false){
                drawGrid(grille);
                win = gagnant(grille);
            }
            if (conteur >= 42 || win ==true){
                system("CLS");
                gagnant(grille);
                std::cout <<"partie terminee\n";
                std::cout << "rejouer ? (o / n)\n";
                std::cin >> choix;
                if (choix[0] == 'n')
                {
                    break;
                }  else if (choix[0] == 'o')
                {
                    goto deb;   
                }
                while(choix[0] != 'o' && choix[0] != 'n' ){
                    std::cout << "votre choix est incorrect\n";
                    std::cout << "rejouer ? (o / n)\n";
                    std::cin >> choix;
                    if (choix[0] == 'o'){
                        goto deb;
                    }
                    if (choix[0] == 'n'){
                        break;
                    } 
                }
                    
            }
        }
    }
    else if (option == 2){
        while (true){
            if(conteur < 42 ){
                std::cout << "player_1 -> col :";
                std::cin >> choix;
            }

            if (choix == "exit"){
                break;
            }

            bool success = false;

            if (choix.size() == 1){
                if (choix[0] >= '0' && choix[0] <= '7'){
                    int col = choix[0]  - '0';

                    success = playTurn(grille, col, player);
                }
            }

            system("CLS");

            if (!success){
                std::cout << "win= " << win ;
                if (conteur >= 42 || win ==true){
                    std::cout <<"partie terminee\n Aucun gagnant.\n";
                    break;
                }
                else if (conteur < 42)
                {
                    std::cout << "votre choix est incorrect\n";
                }
                
            }
            else{
                if (player == 1) 
                {player = 2;
                choix = 2;
                int col = choix[0]  ;

                success = playTurn(grille, col, player);
                player = 1;
                }
                else player = 1;
                conteur = conteur + 1;
                std::cout<<conteur<<"\n";
            }
            if(conteur < 42 || win == false){
                drawGrid(grille);
                win = gagnant(grille);
            }
            if (conteur >= 42 || win ==true){
                system("CLS");
                gagnant(grille);
                std::cout <<"partie terminee\n";
                std::cout << "rejouer ? (o / n)\n";
                std::cin >> choix;
                if (choix[0] == 'n')
                {
                    break;
                }  else if (choix[0] == 'o')
                {
                    goto deb;   
                }
                while(choix[0] != 'o' && choix[0] != 'n' ){
                    std::cout << "votre choix est incorrect\n";
                    std::cout << "rejouer ? (o / n)\n";
                    std::cin >> choix;
                    if (choix[0] == 'o'){
                        goto deb;
                    }
                    if (choix[0] == 'n'){
                        break;
                    } 
                }
                    
            }
        }
    }
    

    return 0;
}


// 0, 1, 2
void drawGrid(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";

        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}
bool gagnant (int grid[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        for (int col = 0; col < 7; col++){
            if (
            grid[ligne][col]==1 && grid[ligne][col +1]==1 && grid[ligne][col+2]==1 && grid[ligne][col+3]==1 ||
            grid[ligne][col]==1 && grid[ligne +1][col +1]==1 && grid[ligne+2][col+2]==1 && grid[ligne+3][col+3]==1 ||
            grid[ligne][col]==1 && grid[ligne+1][col]==1 && grid[ligne+2][col]==1 && grid[ligne+3][col]==1 ||
            grid[ligne][col]==1 && grid[ligne-1][col-1]==1 && grid[ligne-2][col-2]==1 && grid[ligne-3][col-3]==1 ||
            grid[ligne][col]==1 && grid[ligne-1][col+1]==1 && grid[ligne-2][col+2]==1 && grid[ligne-3][col+3]==1 ||
            grid[ligne][col]==1 && grid[ligne+1][col-1]==1 && grid[ligne+2][col-2]==1 && grid[ligne+3][col-3]==1)
            {
                std::cout<<"LE JOUEUR 1 A GAGNE\n";
                return true;
                break;
            }else if (grid[ligne][col]==2 && grid[ligne][col +1]==2 && grid[ligne][col+2]==2 && grid[ligne][col+3]==2 ||
            grid[ligne][col]==2 && grid[ligne +1][col +1]==2 && grid[ligne+2][col+2]==2 && grid[ligne+3][col+3]==2 ||
            grid[ligne][col]==2 && grid[ligne+1][col]==2 && grid[ligne+2][col]==2 && grid[ligne+3][col]==2)
            {
                std::cout<<"LE JOUEUR 2 A GAGNE\n";
                return true;
            }
        }
    }
}

