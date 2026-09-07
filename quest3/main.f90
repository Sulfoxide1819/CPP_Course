program main
  use linear_solver
  implicit none

  integer :: n, i, j, method, ios
  real(8), allocatable :: A(:,:), B(:), X(:), R(:)
  character(len=20) :: arg, first_line
  real(8) :: norm, sharp_char
  character(len=1) :: sharp

  method = 0   ! по умолчанию обычный Гаусс
  if (command_argument_count() >= 1) then
    call get_command_argument(1, arg)
    select case (trim(arg))
    case ('gauss')
      method = 0
    case ('jordan')
      method = 1
    case ('pivot')
      method = 2
    case default
      write(*,*) 'Неизвестный аргумент, используется метод Гаусса'
      method = 0
    end select
  end if

  open(unit=10, file='data.dat', status='old', action='read', iostat=ios)
  if (ios /= 0) then
    write(*,*) 'Ошибка открытия файла data.dat'
    stop
  end if

  read(10, '(A)') first_line
  i = index(first_line, ' ')
  if (i == 0) then
    write(*,*) 'Неверный формат первой строки в data.dat'
    stop
  end if
  read(first_line(i+1:), *) n

  allocate(A(n,n), B(n), X(n), R(n))

  ! Читаем матрицу A
  do i = 1, n
    read(10, *) (A(i,j), j=1,n)
  end do
  ! Читаем вектор B
  do i = 1, n
    read(10, *) B(i)
  end do
  close(10)

  ! Решаем
  call solve(A, B, X, method)

  ! Запись результата в result.dat
  open(unit=11, file='result.dat', status='replace', action='write', iostat=ios)
  if (ios /= 0) then
    write(*,*) 'Ошибка открытия файла result.dat для записи'
    stop
  end if
  write(11, '(A, I0)') '# ', n
  do i = 1, n
    write(11, '(ES23.15)') X(i)    
  end do
  close(11)

  ! Невязка
  R = matmul(A, X) - B
  norm = sqrt(dot_product(R, R))

  write(*, '(A, ES23.15)') 'Норма невязки: ', norm

  deallocate(A, B, X, R)

end program main











