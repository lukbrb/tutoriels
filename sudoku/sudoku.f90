program sudoku
    use solveur, only: solve, read_sudoku
    implicit none

    integer, dimension(9, 9) :: grille
    
    call read_sudoku("grilles/pb1.txt", grille)

    print*, "Grille initiale:", new_line("")
    write(*, '(9(I3))') grille

    print*, new_line(""), "Grille(s) résolues(s):", new_line("")

    call solve(grille)
end program sudoku