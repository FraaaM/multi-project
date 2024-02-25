@echo off

:: Вид сборки / суффикс в названии каталога сборки
::
:: "Ninja" / "ninja"
:: "Visual Studio 17 2022" / "visual_studio"
::
set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

copy ..\%SOURCE_FOLDER%\bubble_sort\run_bubble_sort.bat .\bubble_sort
copy ..\%SOURCE_FOLDER%\bubble_sort_mf\run_bubble_sort_mf.bat .\bubble_sort_mf
copy ..\%SOURCE_FOLDER%\selection_sort\run_selection_sort.bat .\selection_sort
