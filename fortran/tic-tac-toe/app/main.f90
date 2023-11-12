program main
  use tic_tac_toe, only: say_hello
  use c_interface
  implicit none

  call say_hello()
  call hello_c()
end program main
