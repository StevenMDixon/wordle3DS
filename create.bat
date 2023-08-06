@echo off
make clean
make
pause
set Rom = ''
for /r %%i in (*.3dsx*) do (
  %Citra% %%i
)

