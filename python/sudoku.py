""" Simple sudo solver"""
import pprint
import numpy as np


pp = pprint.PrettyPrinter()

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