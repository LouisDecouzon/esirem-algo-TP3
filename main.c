#include <stdio.h>
#include <math.h>
#include <string.h>
enum SolutionType{
    NONE=0,
    ONE=1,
    TWO=2
};
struct Solution{
    enum SolutionType type;
    double x0;
    double x1;
    double x2;
};
struct equation{    
    float a;
    float b;
    float c;
    struct Solution solution;
};
void showSolution(struct Solution solution){
    switch(solution.type){
        case NONE:
            printf("Il n'y a aucune solution.\n");
            break;
        case ONE:
            printf("Il y a une solution : x=%f\n", solution.x0);
            break;
        case TWO:
            printf("Il y a 2 solutions : x1=%f et x2=%f\n",solution.x1,solution.x2);
            break;
    }
}
void test() {
    // Création d'un tableau de Solution avec différents cas
    struct Solution solutions[] = {
            {NONE, 0, 0, 0},
            {ONE, 3.14, 0, 0},
            {TWO, 2.5, 1.5, 3.0},
    };

    // Boucle sur le tableau et affichage des résultats
    for (int i = 0; i < sizeof(solutions)/sizeof(solutions[0]); ++i) { // j'ai cherché comment accéder à la longueur d'un tableau et apparament cette notation avec le quotient est répandue
        printf("\nTest %d :\n", i + 1);
        showSolution(solutions[i]);
    }
}

struct Solution resolveOne(double a, double b){
    if(a==0){
        struct Solution sol = {NONE,0,0,0};
        return sol;
    }
    else {
        struct Solution sol = {ONE, (-b / a), 0, 0};
        return sol;
    }
}

struct Solution resolveTwo(double a,double b, double c){
    double delta = b*b-4*a*c;
    if (delta==0){
        struct Solution sol={ONE,(-b)/(2*a),0,0};
        return sol;
    }
    if (delta<0){
        struct Solution sol={{NONE},0,0,0};
        return sol;
    }
    if (delta>0){
        double racine_delta=sqrt(delta);
        struct Solution sol={TWO,0,(-b-racine_delta)/(2*a),(-b+racine_delta/(2*a))};
        return sol;
    }
}

void resolve(double a,double b, double c){
    if (a==0){
        showSolution(resolveOne(b,c));
    }
    else{
        showSolution(resolveTwo(a, b, c));
    }
}

void decode(char expression[]) {//-4732x^2+83826x-5373
    int a;
    int b;
    int c;
    int co = 0;
    int i=0;
    int i_buffer;
    int sgn_a=0;
    int sgn_b=0;
    int sgn_c=0;
    // cherche a
    if (expression[0]=="-"){
        sgn_a=-1;
        co++;
    }
    for (co; expression[i] != "x"; i++) {
        if (co == 0) {
            a = expression[i];
            co++;
        } else {
            a = a * 10 + expression[i];
            co++;
        }
    }
    i_buffer = i_buffer + 3;
    co = 0;
    if(expression[co-1]=="-"){
        sgn_b=-1;
    }
    for (i = i_buffer; expression[i] != "x"; i++) {
        if (co == 0) {
            b = expression[i];
            co++;
        } else {
            b = b * 10 + expression[i];
            co++;
        }
    }
    i_buffer = i_buffer + 2;
    co = 0;
    if(expression[co-1]=="-"){
        sgn_c=-1;
    }
    for (i = i_buffer; i < (sizeof(expression) / sizeof(expression[0])); i++) {
        if (co == 0) {
            c = expression[i];
            co++;
        } else {
            c = c * 10 + expression[i];
            co++;
        }
    }
    a=a*sgn_a;
    b=b*sgn_b;
    c=c*sgn_c;
    resolve(a,b,c);
}

int main(){
    //showSolution(resolveOne(8,2));
    //resolve(78,0,-45);
    char ci[]="4732x^2+83826x-5373";
    decode(ci);
    return 0;
}
