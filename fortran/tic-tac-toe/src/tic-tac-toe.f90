module tic_tac_toe
  implicit none
  private

  public :: say_hello
contains
  subroutine say_hello
    print *, "Hello, tic-tac-toe!"
  end subroutine say_hello
end module tic_tac_toe
