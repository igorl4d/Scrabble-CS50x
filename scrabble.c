#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int pontos[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // PONTOS PRA CADA LETRA DO ALFABETO
int minus[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};//VALORES ASCII DAS LETRAS MINUSCULAS
int mais[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};//VALORES DAS LETRAS MAIUSCULAS    
int temp_points[] = {};

int compute_score(string word);

int main(void)
{
//JOGADAS DOS USUARIOS
    string word1 = get_string("PLAYER 1  ");
    string word2 = get_string("PLAYER 2  ");
//PONTOS 
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
//LOOP IF DETERMINA VENCEDOR
    if (score1 > score2)
    {  
        
    printf("Player 1 wins!...");

    }
    else if(score2 > score1)
    {

    printf("Player 2 wins!...");
    
        
    }
    
    else 

    {

    printf("Tie!");

    }   
}

    int compute_score(string word)
    {

    int score = 0;

    for(int i = 0; i < strlen(word); i++)

    {
    if (isupper(word[i]))
        {
            for(int f = 0; f < sizeof(mais);f++)
             {
                if (word[i] == mais[f])
                {
                    temp_points[i] = pontos[f];
                    score += temp_points[i];
                }
             }
         }
    else if(islower(word[i]))
    {
        for(int f=0; f< sizeof(minus);f++)
        {
            if (word[i] == minus[f]) 
            {
                temp_points[i] = pontos[f];
                score += temp_points[i];
            }
        }   
    }
    //ignorar palavras fora do alfabeto
    else
    {
    i += 1;
    }
}

return score;
}