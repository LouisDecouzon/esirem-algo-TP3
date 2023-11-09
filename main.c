#include <stdio.h>
enum SolutionType{
    None=0,
    One=1,
    Two=2
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
        case None:
            printf("Il n'y a aucune solution.\n");
            break;
        case One:
            printf("Il y a une solution : x=%.2f\n", solution.x0);
            break;
        case Two:
            printf("Il y a 2 solutions : x1=%.2f et x2=%.2f\n",solution.x1,solution.x2);
            break
    }
}

int main(){
    printf("Hello, World!\n");
    return 0;
}
