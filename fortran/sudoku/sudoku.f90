program sudoku
    use solveur, only: solve, read_sudoku
    implicit none

    integer, dimension(9, 9) :: grille
    
    call read_sudoku("pb1.txt", grille)
    ! grille = reshape(([0, 0, 1, 0, 3, 0, 0, 2, 6, &
    !                     0, 0, 0, 8, 1, 0, 7, 9, 0, &
    !                     0, 4, 0, 7, 0, 0, 0, 0, 0, &
    !                     1, 2, 4, 5, 0, 6, 3, 7, 0, &
    !                     0, 8, 0, 2, 0, 9, 0, 0, 0, &
    !                     7, 0, 9, 1, 0, 3, 8, 5, 2, &
    !                     0, 0, 0, 0, 2, 0, 6, 0, 0, &
    !                     6, 0, 7, 3, 0, 0, 0, 0, 0, &
    !                     4, 3, 0, 0, 0, 0, 0, 0, 0 & 
    !                 ]), shape(grille))

    print*, "Grille initiale:", new_line("")
    write(*, '(9(I3))') grille

    print*, new_line(""), "Grille(s) résolues(s):", new_line("")

    call solve(grille)
end program sudoku