# execmd

Программулька позволяет запускать все подряд не показывая окно консоли и ожидая завершения отработки запускаемой пакетной команды.
Актуально для снятия скриншотов.

Например, можно запустить bat файл `save-screenshot.bat` запускающий [Nircmd](http://www.nirsoft.net/utils/nircmd.html):

```cmd
%~dp0\nircmd.exe win max foreground
%~dp0\nircmd.exe savescreenshot %1
```

таким образом, чтобы сначала окно развернулось на весь экран, а потом был снят его скриншот, при этом было не видно консоли, которая снимает скриншот.

```cmd
execmd.exe save-screenshot.bat screenshot.png
```