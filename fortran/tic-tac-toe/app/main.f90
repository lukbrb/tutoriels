program main
  use c_interface
  use iso_c_binding, only: c_int
  implicit none

  integer(kind=c_int) :: width, height, fps

  width = 600
  height = 800
  fps = 60

  call init_window(width, height, "Fenetre Raylib"//c_null_char)

  call set_target_fps(fps)
  do while(.not. window_should_close())
    call begin_drawing()
    call end_drawing()
  end do
end program main
