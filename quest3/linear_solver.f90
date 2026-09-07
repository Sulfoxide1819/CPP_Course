module linear_solver
  implicit none
contains

  ! Подпрограмма solve решает систему A*x = B одним из трёх методов:
  !   method = 0 : метод Гаусса
  !   method = 1 : метод Йордана
  !   method = 2 : метод Гаусса с выбором ведущего элемента по всей подматрице


subroutine solve(A, B, X, method)
  real(8), intent(in) :: A(:,:)
  real(8), intent(in) :: B(:)
  real(8), intent(out) :: X(:)
  integer, intent(in) :: method

  integer :: n,i,j,k,p,q
  real(8) :: pivot, factor
  real(8), allocatable :: aug(:,:)
  integer, allocatable :: perm(:)
  real(8), parameter :: eps = 1.0d-12
  integer :: idx(2)
  real(8), allocatable :: submat(:,:)
  real(8), allocatable :: x_perm(:)

  n = size(A, 1)

  allocate(aug(n, n+1))
  aug(:, 1:n) = A
  aug(:, n+1) = B


  select case(method)


  ! Метод Гаусса
  case(0)

    ! Прямой ход
    do k = 1,n
      ! Проверка ведущего элемента
      if (abs(aug(k,k)) < eps) then
        write(*,*) 'Ведущий элемент ', aug(k,k), ' близок к нулю на шаге ', k
      end if


      ! Нормировка строки
      pivot = aug(k,k)
      aug(k, k:n+1) = aug(k, k:n+1) / pivot

      do i = k+1, n
        factor = aug(i,k)

        forall (j = k:n+1) aug(i,j) = aug(i,j) - factor * aug(k,j)
      end do
    end do

    ! Обратный ход
    X(n) = aug(n, n+1)
    do i = n-1, 1, -1
      X(i) = aug(i, n+1)
      do j = i+1, n
        X(i) = X(i) - aug(i, j) * X(j)
      end do
    end do



  ! Метод Йордана
  case(1)

    ! Прямой ход
    do k = 1, n
      ! Проверка ведущего элемента
      if (abs(aug(k,k)) < eps) then
        write(*,*) 'Ведущий элемент ', aug(k,k), ' близок к нулю на шаге ', k
      end if

      ! Нормировка строки
      pivot = aug(k,k)
      aug(k, k:n+1) = aug(k, k:n+1) / pivot


      do i = 1, n
        if (k == i) cycle
        factor = aug(i,k)

        forall (j = k:n+1) aug(i,j) = aug(i,j) - factor * aug(k,j)
      end do
    end do

    ! Присваивание
    X(:) = aug(:, n+1)


  ! С выбором ведущего элемента
  case(2)

    allocate(perm(n))
    perm(:) = [(i, i = 1, n)]


    do k = 1, n
      allocate(submat(n-k+1, n-k+1))
      submat = abs(aug(k:n, k:n))
      idx = maxloc(submat)
      p = idx(1) + k - 1
      q = idx(2) + k - 1
      deallocate(submat)

      ! Проверка ведущего элемента
      if (abs(aug(k,k)) < eps) then
        write(*,*) 'Ведущий элемент ', aug(k,k), ' близок к нулю на шаге ', k
      end if

      if (p /= k) then
        do j = 1, n+1
          factor = aug(p,j)
          aug(p,j) = aug(k,j)
          aug(k,j) = factor
        end do
      end if

      if (q /= k) then
        do i = 1, n
          factor = aug(i,q)
          aug(i,q) = aug(i,k)
          aug(i,k) = factor
        end do

        factor = perm(q)
        perm(q) = perm(k)
        perm(k) = factor
      end if

      pivot = aug(k,k)
      aug(k, k:n+1) = aug(k, k:n+1) / pivot

      do i = k+1, n
        factor = aug(i,k)
        forall (j = k:n+1) aug(i,j) = aug(i,j) - factor * aug(k,j)
      end do
    end do


    ! Обратный ход

    allocate(x_perm(n))
    x_perm(n) = aug(n, n+1)
    do i = n-1, 1, -1
      x_perm(i) = aug(i, n+1)
      do j = i+1, n
        x_perm(i) = x_perm(i) - aug(i,j) * x_perm(j)
      end do
    end do

    ! Восстановление исходного порядка переменных
    do i = 1, n
      X(perm(i)) = x_perm(i)
    end do

    deallocate(x_perm)
    deallocate(perm)

  case default
    write(*,*) 'Неизвестный метод'
    stop
  end select

  deallocate(aug)
end subroutine solve

end module linear_solver















