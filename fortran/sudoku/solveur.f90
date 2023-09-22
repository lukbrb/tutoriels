module solveur
    implicit none
    
    private
    
    public :: solve, read_sudoku
    
    contains
    
    logical function is_possible(grille, ligne, col, num) result(possible)
        integer, dimension(9, 9), intent(in) :: grille
        integer, intent(in) :: ligne, col, num
        integer :: l, c
        logical :: ok_ligne, ok_col, ok_carre

        l=((ligne - 1) / 3) * 3 + 1
        c=((col - 1) / 3) * 3 + 1

        ok_ligne = all(grille(ligne, :) /= num)
        ok_col = all(grille(:, col) /= num)
        ok_carre = all(grille(l:l+2, c:c+2) /= num)
  
        if(ok_ligne .and. ok_col.and. ok_carre)then
            possible = .true.
        
        else 
            possible = .false.
        end if
    end function is_possible


    recursive subroutine solve(grille)
        integer, dimension(9, 9), intent(inout) :: grille
        integer :: ligne, col, num

        do ligne = 1, 9
            do col = 1, 9
                if (grille(ligne, col) == 0) then  ! Les cases vides sont spécifiées par des 0
                    do num = 1, 9
                        if (is_possible(grille, ligne, col, num)) then
                            grille(ligne, col) = num
                            call solve(grille)
                            grille(ligne, col) = 0
                        end if
                    end do
                return
                end if
            end do
        end do
        
        write(*, '(9(I3))') grille
        print*, new_line("")
    end subroutine solve

    subroutine read_sudoku(filename, grille)
        character(len=*), intent(in) :: filename
        integer, dimension(9, 9), intent(inout) :: grille
        integer :: i

        open(10, file=filename, action='read')
        do i = 1, 9
            read(10, *) grille(:, i)
        end do
        close(10)

    end subroutine read_sudoku

end module solveur