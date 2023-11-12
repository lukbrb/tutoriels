module c_interface
    use iso_c_binding, only : c_char, c_null_char
    
    interface
        subroutine hello_c() bind(C, name="hello_c")
        end subroutine hello_c
    end interface

end module c_interface
