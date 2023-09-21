""" Simple sudo solver"""
import pprint
import numpy as np


pp = pprint.PrettyPrinter()
# grille = [[0] * 9] * 9
grille = [
    [0, 0, 1, 0, 3, 0, 0, 2, 6],
    [0, 0, 0, 8, 1, 0, 7, 9, 0],
    [0, 4, 0, 7, 0, 0, 0, 0, 0],
    [1, 2, 4, 5, 0, 6, 3, 7, 0],
    [0, 8, 0, 2, 0, 9, 0, 0, 0],
    [7, 0, 9, 1, 0, 3, 8, 5, 2],
    [0, 0, 0, 0, 2, 0, 6, 0, 0],
    [6, 0, 7, 3, 0, 0, 0, 0, 0],
    [4, 3, 0, 0, 0, 0, 0, 0, 0]
]

grille = np.array(grille)
assert grille.shape == (9, 9), f"Invalid grid format. Should be (9, 9), not {grille.shape}"


def can_place_number(grille, ligne, col, num):
    for i in range(9):
        if grille[i, col] == num: return False
        if grille[ligne, i] == num: return False
    
    
    debut_ligne = ligne - ligne % 3
    debut_col = col - col % 3

    for i in range(3):
            for j in range(3):
                if grille[i + debut_ligne, j + debut_col] == num : return False
    
    return True

"""
Rétro-traçage : 

Le backtracking est une forme de parcours en profondeur d'un arbre avec des contraintes sur les noeuds
L'idée est de partir du noeud parent, descendre dans le premier noeud fils satisfaisant la contrainte. Ce noeud fils devient alors un noeud parent et l'on parcourt ensuite ses noeuds fils sous le même principe.
Lorsque l'on a parcouru tous les noeuds fils d'un noeud et qu'aucun ne satisfait la contrainte, on remonte alors au noeud parent et on descend dans le noeud fils suivant.
Si l'on arrive au dernier fils du premier noeud parent et qu'il ne satisfait pas la contrainte alors il n'existe pas de solution.
La solution est identifiée lorsque l'on arrive à un noeud qui satisfait la contrainte et qui n'a pas de noeud fils. 
"""

# solution inspired from computerphile's video: https://youtu.be/G_UYXzGuqvM?si=GdCwpxlCsM1_wDzz
def solve_sudoku(grille): 
    # On parcourt toute la grille, là où les cases sont vides
    for i in range(9):
         for j in range(9):
            if grille[i, j] == 0:
                for num in range(1, 10):
                    if can_place_number(grille, i, j, num):
                        grille[i, j] = num
                        # On veut maintenant résoudre cette nouvelle grille
                        solve_sudoku(grille)
                        # Si la grille n'est pas solvable, on doit changer le numéro actuel
                        grille[i, j] = 0
                return  
    print()
    pp.pprint(grille)
    
solve_sudoku(grille)