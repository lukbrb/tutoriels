module c_interface
    use iso_c_binding, only : c_char, c_null_char, c_int, c_bool
    
    interface
        subroutine init_window(width, height, title) bind (C, name="InitWindow")
            import c_char, c_int

            integer(kind=c_int), value :: width, height
            character(kind=c_char) :: title(*)
        end subroutine init_window

        subroutine set_target_fps(fps) bind(C, name="SetTargetFPS")
            import c_int
            integer(c_int), value :: fps
        end subroutine set_target_fps

        logical(c_bool) function window_should_close() bind(C, name="WindowShouldClose")
            import c_bool
        end function window_should_close

        subroutine begin_drawing() bind(C, name="BeginDrawing")
        end subroutine begin_drawing
        subroutine end_drawing() bind(C, name="EndDrawing")
        end subroutine end_drawing
    end interface

end module c_interface
