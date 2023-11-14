program main
  use c_interface
  use iso_c_binding, only: c_int, c_int32_t
  implicit none

  integer(kind=c_int) :: width, height, fps
  integer(c_int32_t) :: bleu

  width = 800
  height = 600
  fps = 60
  bleu = int(z'FFF17900', c_int32_t)
  call init_window(width, height, "Fenetre Raylib"//c_null_char)

  call set_target_fps(fps)
  do while(.not. window_should_close())
    call begin_drawing()
    call clear_background(bleu)
    call end_drawing()
  end do
end program main
