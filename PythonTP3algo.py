from enum import Enum
import math 
class SolutionType(Enum):
    NONE=0
    ONE=1
    TWO=2

class Solution:
    def __init__(self,solution_type,x0=0,x1=0,x2=0):
        self.type=solution_type
        self.x0=x0
        self.x1=x1
        self.x2=x2

class Equation:
    def __init__(self,a,b,c):
        self.a=a
        self.b=b
        self.c=c
        self.solution=None

eq1=Equation(1,1,2)
#print(eq1.c)

def ShowSolution(Solution):
    if Solution.type==SolutionType.NONE:
        print("Il n'y a aucune solution")
    if Solution.type==SolutionType.ONE:
        print("Il y a une solution unique : x =",Solution.x0)
    if Solution.type==SolutionType.TWO:
        print("Il y a deux solutions distinctes : x1=",Solution.x1," et x2=",Solution.x2)

sol1=Solution(SolutionType.NONE)
sol2=Solution(SolutionType.ONE,5)
sol3=Solution(SolutionType.TWO,-3,2)

def test():
    Sol=[Solution(SolutionType.NONE),  
         Solution(SolutionType.ONE,5),
         Solution(SolutionType.TWO,-3,2,67),
         Solution(SolutionType.NONE)]
    i=1
    for s in Sol:
        print("Resultat de la solution",i)
        ShowSolution(s)
        i+=1


def ResolveOne(a:float,b:float):
    if a==0:
        sol=Solution(SolutionType.NONE)
    else:
        sol=Solution(SolutionType.ONE,-b/a)
    return sol
    
#test()
#ShowSolution(ResolveOne(3,2))

def ResolveTwo(a:float,b:float,c:float):
    delta=b*b-4*a*c
    if delta==0:
        sol=Solution(SolutionType.ONE,-b/(2*a))
    elif delta>0:
        RacineDelta=math.sqrt(delta)
        sol=Solution(SolutionType.TWO,0,(-b-RacineDelta)/(2*a),(-b+RacineDelta)/(2*a))
    elif delta<0:
        sol=Solution(SolutionType.NONE)
    return sol

def TestResolveTwo():
    t=[(1,2,2),
       (1,0,2),
       (-1,2,4)]
    i=1
    for k in t :
        print("Le resultat de l'equation associee au triplet",i,"est : ")   
        ShowSolution(ResolveTwo(k[0],k[1],k[2]))
        i+=1
#TestResolveTwo()


