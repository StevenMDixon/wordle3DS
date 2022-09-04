@echo off
make 
pause
set Rom = ''
for /r %%i in (*.3dsx*) do (
  %Citra% %%i
)

