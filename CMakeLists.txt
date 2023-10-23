cmake_minimum_required(VERSION 3.0.0)
project(Asesorias VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(Structs datos_personalizados.c)
add_executable(ListasIndexadas busqueda_indexada.c)
add_executable(VerdaderoFalso verdadero_y_falso.c)
add_executable(MultiplicacionMatrices multiplicacion_matrices.c)
add_executable(Contextos stack_frames.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
